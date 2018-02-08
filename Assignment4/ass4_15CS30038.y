 %{ 
 	
	#include <string.h>
	#include <stdio.h>
	#include "ass4_15CS30038_translator.h"
	extern	int yylex();
	void yyerror(const char *s);
	extern type_e TYPE;
	extern int gDebug;

%}


%union {
	int intvalue;
	int instr;
	sym* symt;
	expr* expAttr;
	char* strval;
	float floatvalue;
	lint* nl;
	statement* statm;
	unary* A;
	char uoptr;
	sym_type* stp;
		
}

%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID BOOL
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH RETURN MATRIX
%token PLUS_ASSIGN
%token MINUS_ASSIGN
%token RIGHT_ASSIGN
%token LEFT_ASSIGN
%token MULTIPLY_ASSIGN
%token <symt>PUNCTUATORS
%token <strval> STRING_LITERAL
%token <symt>IDENTIFIER
%token <intvalue>INT_CONSTANT 
	
%token <strval> FLOAT_CONSTANT
%token <char>CHAR_CONSTANT

%token MODULUS_ASSIGN
%token AND_ASSIGN
%token DIVIDE_ASSIGN 
%token XOR_ASSIGN
%token POINTER_OP 
%token AND_OP
%token OR_ASSIGN
%token RIGHT_OP
%token LEFT_OP 
%token INCREMENT_OP
%token DECREMENT_OP
%token EQ_OP
%token NE_OP
%token ZERO_CONSTANT
%token POINTCOL
%token OR_OP
%token LE_OP
%token GE_OP

   	
// Expressions
%type <A> postfix_expression
%type <expAttr> primary_expression
%type <expAttr> shift_expression
%type <A> cast_expression
%type <A> unary_expression 
%type <expAttr> expression
%type <expAttr> assignment_expression
%type <expAttr> expression_statement
%type <expAttr> relational_expression
%type <expAttr> conditional_expression
%type <expAttr> equality_expression
%type <expAttr> and_expression
%type <expAttr> logical_and_expression
%type <expAttr> exclusive_or_expression
%type <expAttr> inclusive_or_expression
%type <expAttr> multiplicative_expression
%type <expAttr> additive_expression
%type <expAttr> logical_or_expression  
%type <symt> initializer


%type <symt> constant

%type <instr> M
%type <symt> init_declarator
%type <symt> declarator
%type <expAttr> N
%type <stp> pointer
%type <uoptr> unary_operator
%type <symt> direct_declarator
%type <intvalue> argument_expression_list

%type <statm>  statement labeled_statement iteration_statement jump_statement compound_statement selection_statement block_item block_item_list

%start translation_unit

%%
primary_expression
	: IDENTIFIER {
		$$ = new expr();
		$$->symt = $1;
		$$->isbool = false;
	}
	| '(' expression ')' {
		$$ = $2;
	}
	| STRING_LITERAL {
		$$ = new expr();
		$$->symt = gentemp(PTR, $1);
		$$->symt->initialize($1);
		$$->symt->type->ptr = new sym_type(_CHAR);
	}
	| constant {
		$$ = new expr();
		$$->symt = $1;
	}
	;

equality_expression
	: equality_expression NE_OP relational_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// If any is bool get its value
			con_from_bool ($3);
			con_from_bool ($1);
			$$ = new expr();string isexpr;
			$$->falselist = makelist (nextinstr()+1);
			$$->isbool = true;
			$$->truelist = makelist (nextinstr());
			emit (GOTOOP, "");
			emit (NEOP, $$->symt->name, $1->symt->name, $3->symt->name);
		}else cout << "Type-Error"<< endl;
	}
	| relational_expression {$$ = $1;}
	| equality_expression EQ_OP relational_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// If any is bool get its value
			con_from_bool ($3);
			con_from_bool ($1);
			$$ = new expr();
			$$->falselist = makelist (nextinstr()+1);
			$$->truelist = makelist (nextinstr());
			$$->isbool = true;
			emit (GOTOOP, "");
			emit (EQOP, "", $1->symt->name, $3->symt->name);
		}else cout << "Type-Error"<< endl;
	}
	;

constant
	: INT_CONSTANT {
		$$ = gentemp(_INT, num_to_string($1));
		emit(EQUAL, $$->name, $1);
	}
	| CHAR_CONSTANT{
		$$ = gentemp(_CHAR);
		emit(EQUAL, $$->name, "a");
	}
	| FLOAT_CONSTANT {
		$$ = gentemp(_DOUBLE, *new string ($1));
		emit(EQUAL, $$->name, *new string($1));
	}
	| ZERO_CONSTANT {	/* Ignored */
	}
	;

argument_expression_list
	: assignment_expression {
		emit (PARAM, $1->symt->name);
		$$ = 1;
	}
	| argument_expression_list ',' assignment_expression {
		emit (PARAM, $3->symt->name);
		$$ = $1+1;
	}
	;

unary_operator
	: '&' {$$ = '&';
	}
	| '+' {$$ = '+';
	}
	| '-' {$$ = '-';
	}
	| '*' {$$ = '*';
	}
	;

postfix_expression
	: primary_expression  {
		$$ = new unary ();
		$$->symt = $1->symt;
		$$->loc = $$->symt;
		$$->type = $1->symt->type;
	}
	| postfix_expression '(' ')'
	| postfix_expression '.' IDENTIFIER /* Ignored */
	| postfix_expression '(' argument_expression_list ')' {
		$$ = new unary();
		$$->symt = gentemp($1->type->cat);
		emit(CALL, $$->symt->name, $1->symt->name, tostr($3));
	}
	| postfix_expression POINTER_OP IDENTIFIER  /* Ignored */
	| postfix_expression INCREMENT_OP {
		$$ = new unary();
		if($1->is_matrix){
			$$->symt = gentemp(_DOUBLE);
			sym *vartemp = gentemp(_DOUBLE);
			emit(ARRR , vartemp->name , $1->symt->name , $1->loc->name);
			sym *tempvar1=gentemp(_DOUBLE);
			emit(EQUAL,$$->symt->name,vartemp->name);
			sym *tempvar2=gentemp(_DOUBLE);
			emit (ADD, vartemp->name, vartemp->name, "1");	
			emit(ARRL , $1->symt->name,$1->loc->name,vartemp->name);
		}else{
		$$->symt = gentemp($1->symt->type->cat);
		emit (EQUAL, $$->symt->name, $1->symt->name);string unarys;
		emit (ADD, $1->symt->name, $1->symt->name, "1");
		}
	}
	| postfix_expression DECREMENT_OP {
		$$ = new unary();
		if($1->is_matrix ){
			$$->symt= gentemp(_DOUBLE);
			sym *vartemp = gentemp(_DOUBLE);
			emit(ARRR, vartemp->name , $1->symt->name , $1->loc->name);
			sym *tempvar1=gentemp(_DOUBLE);
			emit(EQUAL,$$->symt->name,vartemp->name);string unarys;
			sym *tempvar2=gentemp(_DOUBLE);
			emit( SUB, vartemp->name , vartemp->name , "1");	
			emit(ARRL, $1->symt->name,$1->loc->name,vartemp->name);	
		}else
		{$$->symt = gentemp($1->symt->type->cat);
		emit (EQUAL, $$->symt->name, $1->symt->name);string unarys;
		emit (SUB, $1->symt->name, $1->symt->name, "1");}
	}
	| primary_expression '[' expression ']''[' expression ']' {
		$$ = new unary();
		$$->symt = $1->symt;
		$$->is_matrix=true;
		sym* t = gentemp(_DOUBLE);
		emit(MULT,t->name,t->name,num_to_string($1->symt->type->len));
		emit(MULT, t->name, $3->symt->name, num_to_string(8));
		sym* temvar = gentemp(_DOUBLE);
 		emit(ADD, t->name, temvar->name, t->name);
    	emit(MULT,temvar->name, $6->symt->name, num_to_string(8));
    	$$->loc=gentemp(_DOUBLE);
 		emit (EQUAL, $$->loc->name, t->name );
	}
	| postfix_expression POINTCOL{
		$$ = new unary();
			$$->symt = gentemp(_DOUBLE);
			sym *vartemp = gentemp(_DOUBLE);
			sym *tempvar1=gentemp(_DOUBLE);
			emit(ARRR, vartemp->name , $1->symt->name , $1->loc->name);
			emit(EQUAL,$$->symt->name,vartemp->name);sym *tempvar2=gentemp(_DOUBLE);
			sym* tp = gentemp(_DOUBLE);
			emit(MULT,tp->name,num_to_string($1->symt->type->len),num_to_string($1->symt->type->width));
			emit(SUB,tp->name,tp->name,$1->loc->name);sym *tempvar3=gentemp(_DOUBLE);
			emit(ARRR,tp->name,$1->symt->name,tp->name);sym *tempvar4=gentemp(_DOUBLE);
			emit(ARRL,$1->symt->name,$1->loc->name,tp->name);
	}
	;

cast_expression
	: unary_expression  {
		$$ = $1;
	}
	;



unary_expression
	: postfix_expression {
		$$ = $1;
	}
	| INCREMENT_OP unary_expression {
		// Increment value $1
		emit (ADD, $2->symt->name, $2->symt->name, "1");
		$$ = $2;
	}
	| unary_operator cast_expression {
		$$ = new unary();
		
		if($1=='&'){
			if($2->is_matrix){
					$$->symt = gentemp(PTR);
					$$->symt->type->ptr = $2->symt->type;
					sym* temp = gentemp(_DOUBLE);
					emit(ARRR, temp->name , $2->symt->name , $2->loc->name);
					emit (ADDRESS, $$->symt->name, temp->name);
				}else{
				$$->symt = gentemp(PTR);
				$$->symt->type->ptr = $2->symt->type; 
				emit (ADDRESS, $$->symt->name, $2->symt->name);}

		}else if($1=='*'){
				if($2->is_matrix){
						$$->symt = gentemp(_DOUBLE);
						$$->symt->type->ptr = $2->symt->type;
						sym* temp = gentemp(_DOUBLE);
						emit(ARRR, temp->name , $2->symt->name , $2->loc->name);
						emit (PTRR, $$->symt->name, temp->name);
					//offset++;
						break;
					}else{
				$$->cat = PTR;
				$$->loc = gentemp ($2->symt->type->ptr);
				emit (PTRR, $$->loc->name, $2->symt->name);
				$$->symt = $2->symt;	}

		}else if($1=='+'){
				if($2->is_matrix){
					$$->symt = gentemp(_DOUBLE);
					emit(ARRR, $$->symt->name , $2->symt->name , $2->loc->name);	
				}else{
					$$ = $2;	}
		
		}else if($1=='-'){
				if($2->is_matrix){
					sym* temp = gentemp(_DOUBLE);
					$$->symt = gentemp(_DOUBLE);
					emit(ARRR, temp->name , $2->symt->name , $2->loc->name);
					emit (UMINUS, $$->symt->name, temp->name);
				}else{
					$$->symt = gentemp($2->symt->type->cat);
					emit (UMINUS, $$->symt->name, $2->symt->name);	}
		}
	}
	| DECREMENT_OP unary_expression {
		if($2->is_matrix){
			$$ = new unary();
			$$->symt = gentemp(_DOUBLE);
			emit(ARRR, $$->symt->name , $2->symt->name , $2->loc->name);
			emit( SUB, $$->symt->name , $$->symt->name , "1");	
			emit(ARRL, $2->symt->name , $2->loc->name  , $$->symt->name);
		}else{

		// Decrement $1
		emit (SUB, $2->symt->name, $2->symt->name, "1");

		// Use the same value
		$$ = $2;}
	}
	;



additive_expression
	: multiplicative_expression {$$ = $1;}
	| additive_expression '+' multiplicative_expression {
		if (typecheck($1->symt, $3->symt)) {
			$$ = new expr();string generatemp;
			$$->symt = gentemp($1->symt->type->cat);
			emit (ADD, $$->symt->name, $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	| additive_expression '-' multiplicative_expression {
		if (typecheck($1->symt, $3->symt)) {
			$$ = new expr();string generatemp;
			$$->symt = gentemp($1->symt->type->cat);
			emit (SUB, $$->symt->name, $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	;


relational_expression
	: shift_expression { $$ = $1;}
	| relational_expression '<' shift_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;bool checkbool;
			$$->falselist = makelist(nextinstr()+1);
			$$->truelist = makelist(nextinstr());
			emit (GOTOOP, "");
			emit(LT, "", $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	| relational_expression GE_OP shift_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			$$ = new expr();bool ifbool;
			string falselistk;$$->isbool = true;
			$$->falselist = makelist (nextinstr()+1);
			$$->truelist = makelist (nextinstr());
			emit (GOTOOP, "");
			emit(LE, "", $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	| relational_expression '>' shift_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// New bool
			$$ = new expr();$$->isbool = true;
			$$->falselist = makelist (nextinstr()+1);
			$$->truelist = makelist (nextinstr());
			emit (GOTOOP, "");
			emit(GT, "", $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	| relational_expression LE_OP shift_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// New bool
			$$ = new expr();$$->isbool = true;
			$$->falselist = makelist (nextinstr()+1);
			$$->truelist = makelist (nextinstr()); 
			emit (GOTOOP, "");
			emit(LE, "", $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	
	;



and_expression
	: and_expression '&' equality_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			$$ = new expr();
			$$->isbool = false;
			int ifbool;
			$$->symt = gentemp (_INT);
			emit (BAND, $$->symt->name, $1->symt->name, $3->symt->name);
		}else cout << "Type Error"<< endl;
	}
	| equality_expression {$$ = $1;}
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// If any is bool get its value
			con_from_bool ($3);
			con_from_bool ($1);
			$$ = new expr();
			$$->symt = gentemp (_INT);
			$$->isbool = false;
			emit (XOR, $$->symt->name, $1->symt->name, $3->symt->name);
		}else cout << "Type Error"<< endl;
	}
	;

init_declarator
	: declarator {
		$$ = $1;
	}
	| declarator '=' initializer {
		debug ($1->name);
		debug ($3->name);
		debug ($3->init);
		debug ("here init");
		if ($3->init!="") $1->initialize($3->init);
		emit (EQUAL, $1->name, $3->name);
	}
	;

inclusive_or_expression
	: inclusive_or_expression '|' exclusive_or_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			// If any is bool get its value
			con_from_bool ($1);
			con_from_bool ($3);
			$$ = new expr();string backpat;
			$$->isbool = false;
			$$->symt = gentemp (_INT);
			emit (INOR, $$->symt->name, $1->symt->name, $3->symt->name);
		}
		else cout << "Type Error"<< endl;
	}
	|exclusive_or_expression {$$ = $1;}
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	{printf("declaration_specifiers\n");}
	;

logical_and_expression
	: logical_and_expression N AND_OP M inclusive_or_expression {
		con_to_bool($5);

		// N to convert $1 to bool
		backpatch($2->nextlist, nextinstr());
		con_to_bool($1);

		$$ = new expr();
		$$->isbool = true;string backpat;
		backpatch($1->truelist, $4);
		$$->truelist = $5->truelist;
		$$->falselist = merge ($1->falselist, $5->falselist);
	}
	|inclusive_or_expression {$$ = $1;}

	;


logical_or_expression
	: logical_or_expression N OR_OP M logical_and_expression {
		con_to_bool($5);

		// N to convert $1 to bool
		backpatch($2->nextlist, nextinstr());
		con_to_bool($1);

		$$ = new expr();
		$$->isbool = true;

		backpatch ($$->falselist, $4);
		$$->falselist = $5->falselist;
		$$->truelist = merge ($1->truelist, $5->truelist);
	}
	| logical_and_expression {$$ = $1;}
	;

N 	: %empty { 	// Non terminal to prevent fallthrough by emitting a goto
		debug ("n");
		$$  = new expr();
		$$->nextlist = makelist(nextinstr());
		emit (GOTOOP,"");
		debug ("n2");
	}

M 	: %empty{	// To store the address of the next instruction for further use.
		$$ = nextinstr();
	};


conditional_expression
	: logical_or_expression N '?' M expression N ':' M conditional_expression {
		$$->symt->update($5->symt->type);
		$$->symt = gentemp();
		emit(EQUAL, $$->symt->name, $9->symt->name);
		emit (GOTOOP, "");
		lint l = makelist(nextinstr());

		backpatch($6->nextlist, nextinstr());
		lint m = makelist(nextinstr());
		emit (GOTOOP, "");
		emit(EQUAL, $$->symt->name, $5->symt->name);
		l = merge (l, m);
		backpatch($2->nextlist, nextinstr());string con_bool;
		con_to_bool ($1);
		backpatch (l, nextinstr());
		backpatch ($1->falselist, $8);
		backpatch ($1->truelist, $4);
	}
	| logical_or_expression {$$ = $1;}
	;

assignment_expression
	: unary_expression assignment_operator assignment_expression {
		if($1->cat==ARR){
				$3->symt = conv($3->symt, $1->type->cat);
				emit(ARRL, $1->symt->name, $1->loc->name, $3->symt->name);
		}else if($1->cat==PTR){
			emit(PTRL, $1->symt->name, $3->symt->name);
		}else {
			$3->symt = conv($3->symt, $1->symt->type->cat);
			emit(EQUAL, $1->symt->name, $3->symt->name);
			}
		$$ = $3;
	} 
	|conditional_expression {
		$$ = $1;
	}
	;

initializer
	: assignment_expression {
		$$ = $1->symt;
	}
	| '{' initializer_list '}' {}
	| '{' initializer_list ',' '}'
	{printf("initializer\n");}
	;

shift_expression
	: additive_expression {$$ = $1;}
	| shift_expression LEFT_OP additive_expression {
		if ($3->symt->type->cat == _INT) {
			$$ = new expr();
			$$->symt = gentemp (_INT);
			emit (LEFTOP, $$->symt->name, $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	| shift_expression RIGHT_OP additive_expression {
		if ($3->symt->type->cat == _INT) {
			$$ = new expr();
			$$->symt = gentemp (_INT);
			emit (RIGHTOP, $$->symt->name, $1->symt->name, $3->symt->name);
		}
		else cout << "Type-Error"<< endl;
	}
	;

expression
	: assignment_expression {
		$$ = $1;
	}
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	{printf("constant_expression\n");}
	;


declaration
	: declaration_specifiers ';' {

	}
	| declaration_specifiers init_declarator_list ';' {
		debug ("declaration");
	}
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator {
		debug("init_declarator_list");
	}
	;


declarator
	: pointer direct_declarator {
		sym_type * t = $1;
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = $2->type;
		$$ = $2->update($1);
	}
	| direct_declarator
	;

assignment_operator
	: MODULUS_ASSIGN	
	| '='			
	| DIVIDE_ASSIGN		
	| MULTIPLY_ASSIGN	
	| PLUS_ASSIGN		
	| XOR_ASSIGN		
	| MINUS_ASSIGN		
	| RIGHT_ASSIGN		
	| OR_ASSIGN		
	| LEFT_ASSIGN		
	| AND_ASSIGN		
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration 
	;

direct_declarator
	: IDENTIFIER {
		$$ = $1->update(TYPE);
		debug ("currsym: "<< $$->name);
		currsym = $$;
	}
	| '(' declarator ')' {
		$$ = $2;
	}
	| direct_declarator '(' identifier_list ')' { /* Ignored */}
	| direct_declarator '[' assignment_expression ']''[' assignment_expression ']'{
		sym_type * t = $1 -> type;string assignexp;
		sym_type * prev = NULL;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}if (prev==NULL) {
			int x = atoi($3->symt->init.c_str());
			int y= atoi($6->symt->init.c_str());
			sym_type* s = new sym_type(ARR, $1->type, x,y);
			y = size_type(s);
			$$ = $1->update(s);
		}
		else {
			prev->ptr =  new sym_type(ARR, t, atoi($3->symt->init.c_str()),atoi($6->symt->init.c_str()));
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator '[' ']''[' ']' {
		sym_type * prev = NULL;
		sym_type * t = $1 -> type;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}if (prev==NULL) {
			sym_type* s = new sym_type(ARR, $1->type, 0);
			$$ = $1->update(s);
			int y = size_type(s);
		}else {
			prev->ptr =  new sym_type(ARR, t, 0);
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator '(' CST ')' {		
		table->tname = $1->name;		
		if ($1->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");// Update type of return value
			s->update($1->type);
		}
		$1 = $1->linkst(table);		// Update type of function in global table
		int r=0;
		table->parent = gTable;
		changeTable (gTable,r);				
		currsym = $$;
		debug ("currsym: "<< $$->name);
	}
	| direct_declarator '(' CST parameter_type_list ')' {
		table->tname = $1->name;
		if ($1->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");
			s->update($1->type);		
		}
		$1 = $1->linkst(table);
		int r=0;
		table->parent = gTable;
		changeTable (gTable,r);			
		currsym = $$;						
		debug ("currsym: "<< $$->name);
	}
	;

CST : %empty { // Used for changing to symbol table for a function
		int r=0;
		if (currsym->nest==NULL) changeTable(new sym_table(""),r);	
		else {
			changeTable (currsym ->nest,r);				
			emit (LABEL, table->tname);
		}
	}
	;

pointer
	: '*' {
		$$ = new sym_type(PTR);
	}
	| '*' pointer {
		$$ = new sym_type(PTR, $2);
	}
	;


parameter_type_list
	: parameter_list
	;


parameter_declaration
	: declaration_specifiers declarator {
		debug ("here");
		$2->category = "param";
	}
	| declaration_specifiers
	{printf("parameter_declaration\n");}
	;

identifier_list
	: IDENTIFIER 
	| identifier_list ',' IDENTIFIER
	{printf("identifier_list\n");}
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	|  initializer_list ',' designation initializer
	{printf("initializer_list\n");}
	;


designator_list
	: designator
	| designator_list designator
	;

function_definition
	: declaration_specifiers declarator declaration_list CST compound_statement {

	}
	| declaration_specifiers declarator CST compound_statement {
		int declrs=0;table->parent = gTable;
		changeTable (gTable,declrs);
	}
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

statement
	: labeled_statement /* Skipped */
	| compound_statement {
		$$ = $1;
	}
	| expression_statement {
		$$ = new statement();
		$$->nextlist = $1->nextlist;
	}
	| selection_statement {
		$$ = $1;
	}
	| iteration_statement {
		$$ = $1;
	}
	| jump_statement {
		$$ = $1;
	}
	;

labeled_statement /* Ignored */
	: IDENTIFIER ':' statement {$$ = new statement();}
	| CASE constant_expression ':' statement {$$ = new statement();}
	| DEFAULT ':' statement {$$ = new statement();}
	;

multiplicative_expression
	: cast_expression {
		$$ = new expr();
		if ($1->cat==ARR) { 
			string generatemp;$$->symt = gentemp($1->loc->type);
			emit(ARRR, $$->symt->name, $1->symt->name, $1->loc->name);
		}else if ($1->cat == PTR) { // Pointer
				$$->symt = $1->loc;
		}else { $$->symt = $1->symt;
		}
	}
	| multiplicative_expression '*' cast_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			string generatemp;$$ = new expr();
			$$->symt = gentemp($1->symt->type->cat);
			emit (MULT, $$->symt->name, $1->symt->name, $3->symt->name);
		}else cout << "Type-Errors"<< endl;
	}
	| multiplicative_expression '%' cast_expression {
		if (typecheck ($1->symt, $3->symt) ) {
			string generatemp;$$ = new expr();
			$$->symt = gentemp($1->symt->type->cat);
			emit (MODOP, $$->symt->name, $1->symt->name, $3->symt->name);
		}else cout << "Type-Errors"<< endl;
	}
	| multiplicative_expression '/' cast_expression{
		if (typecheck ($1->symt, $3->symt) ) {
			string generatemp;$$ = new expr();
			$$->symt = gentemp($1->symt->type->cat);
			emit (DIVIDE, $$->symt->name, $1->symt->name, $3->symt->name);
		}else cout << "Type-Errors"<< endl;
	}
	;

block_item_list
	: block_item {
		$$ = $1;		
	}
	| block_item_list M block_item {
		$$ = $3;
		backpatch ($1->nextlist, $2);
	}
	;


expression_statement
	: ';' {	$$ = new expr();}
	| expression ';' {
		$$ = $1;
	}
	;

selection_statement
	: SWITCH '(' expression ')' statement {}
	| IF '(' expression N ')' M statement N {
		backpatch ($4->nextlist, nextinstr());
		con_to_bool($3);string con_bool;
		$$ = new statement();
		backpatch ($3->truelist, $6);
		lint temp = merge ($3->falselist, $7->nextlist);
		$$->nextlist = merge ($8->nextlist, temp);
		
	}
	| IF '(' expression N ')' M statement N ELSE M statement {
		backpatch ($4->nextlist, nextinstr());string con_bool;
		con_to_bool($3);
		backpatch ($3->falselist, $10);
		backpatch ($3->truelist, $6);
		lint temp = merge ($7->nextlist, $8->nextlist);
		$$->nextlist = merge (temp, $11->nextlist);
	}
	;

block_item
	: statement {
		$$ = $1;
	}
	| declaration { 
		$$ = new statement();
	}
	;

compound_statement
	: '{' '}' { $$ = new statement();}
	| '{' block_item_list '}' {
		$$ = $2;
	}
	;

iteration_statement 	
	: WHILE M '(' expression ')' M statement { 
		$$ = new statement();
		con_to_bool($4);
		backpatch($4->truelist, $6);
		$$->nextlist = $4->falselist;
		backpatch($7->nextlist, $2);
		// Emit to prevent fallthrough
		emit (GOTOOP, tostr($2));
	}
	| FOR '(' expression_statement M expression_statement ')' M statement {
		$$ = new statement();
		con_to_bool($5);
		backpatch ($5->truelist, $7);
		backpatch ($8->nextlist, $4);
		emit (GOTOOP, tostr($4));
		$$->nextlist = $5->falselist;
	}
	| DO M statement M WHILE '(' expression ')' ';' {
		$$ = new statement();
		con_to_bool($7);
		backpatch ($7->truelist, $2);
		backpatch ($3->nextlist, $4);
		$$->nextlist = $7->falselist;

	}
	| FOR '(' expression_statement M expression_statement M expression N ')' M statement {
		$$ = new statement();
		con_to_bool($5);
		backpatch ($5->truelist, $10);
		backpatch ($8->nextlist, $4);
		backpatch ($11->nextlist, $6);
		emit (GOTOOP, tostr($6));
		$$->nextlist = $5->falselist;
	}
	;

designation
	: designator_list '='
	;

jump_statement 
	: CONTINUE ';' {$$ = new statement();}
	| RETURN expression ';'{
		$$ = new statement();
			emit(_RETURN,$2->symt->name);			

	}
	| BREAK ';' {$$ = new statement();}
	| GOTO IDENTIFIER ';' {$$ = new statement();}
	| RETURN ';' {
		$$ = new statement();
		emit(_RETURN,"");
	}
	;

external_declaration
	: function_definition
	| declaration
	;

type_specifier
	: SHORT	
	| LONG	
	| CHAR	{	TYPE = _CHAR;	}
	| VOID	{	TYPE = _VOID;	}
	| SIGNED
	| INT	{	TYPE = _INT;	}
	| DOUBLE{	TYPE = _DOUBLE;	}
	| UNSIGNED	
	| FLOAT	
	| MATRIX
	| BOOL	
	;

translation_unit
	: external_declaration 
	| translation_unit external_declaration {
	}
	;


declaration_list
	: declaration
	| declaration_list declaration
	;

%%

void yyerror(const char *s) {
	printf ("ERROR: %s",s);
}
