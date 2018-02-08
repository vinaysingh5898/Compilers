%{

#include <stdio.h>
void yyerror(char *s);
extern int yylex();

%}

%union { int intval; }

%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID BOOL
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH RETURN MATRIX
%token RIGHT_ASSIGN LEFT_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN
%token DIVIDE_ASSIGN MODULUS_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN RIGHT_OP LEFT_OP 
%token INCREMENT_OP DECREMENT_OP POINTER_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP
%token IDENTIFIER STRING_LITERAL PUNCTUATORS INT_CONSTANT FLOAT_CONSTANT CHAR_CONSTANT ZERO_CONSTANT POINTCOL

%start translation_unit

%%

primary_expression
	: IDENTIFIER	{printf("primary_expression => IDENTIFIER\n");}
	| constant	{printf("primary_expression => IDENTIFIER\n");}
	| STRING_LITERAL	{printf("primary_expression => STRING_LITERAL\n");}
	| '(' expression ')'	{printf("primary_expression => (expression)\n");}
	;

constant
	: INT_CONSTANT	{printf("constant => INT_CONSTANT\n");}
	| FLOAT_CONSTANT {printf("constant => FLOAT_CONSTANT\n");}
	| ZERO_CONSTANT	{printf("constant => ZERO_CONSTANT\n");}
	| CHAR_CONSTANT	{printf("constant => CHAR_CONSTANT\n");}
	;

postfix_expression
	: primary_expression {printf("postfix_expression => primary_expression\n");}
	| postfix_expression '[' expression ']' {printf("postfix_expression => postfix_expression [ expression ] \n");}
	| postfix_expression '('')'	{printf("postfix_expression =>  postfix_expression ( )\n");}
	| postfix_expression '(' argument_expression_list ')'	{printf("postfix_expression=>  postfix_expression ( argument_expression_list )\n");}
	| postfix_expression '.' IDENTIFIER	{printf("postfix_expression =>  postfix_expression '.' IDENTIFIER\n");}
	| postfix_expression POINTER_OP IDENTIFIER	{printf("postfix_expression=>  postfix_expression -> IDENTIFIER\n");}
	| postfix_expression INCREMENT_OP	{printf("postfix_expression =>  postfix_expression ++ \n");}
	| postfix_expression DECREMENT_OP	{printf("postfix_expression =>  postfix_expression -- \n");}
	| postfix_expression POINTCOL		{printf("postfix_expression =>  postfix_expression .' \n");}
	;

argument_expression_list
	: assignment_expression	{printf("argument_expression_list =>  assignment_expression\n");}
	| argument_expression_list ',' assignment_expression {printf("argument_expression_list =>  assignment_expression_list '.' assignment_expression\n");}
	;

unary_expression
	: postfix_expression {printf("unary_expression =>  postfix_expression\n");}
	| INCREMENT_OP unary_expression	{printf("unary_expression =>  ++ unary_expression\n");}
	| DECREMENT_OP unary_expression	{printf("unary_expression =>  -- unary_expression\n");}
	| unary_operator cast_expression{printf("unary_expression =>  unary_operator cast_expression\n");}
	;

unary_operator
	: '&'	{printf("unary_operator => '&' \n");}
	| '*'	{printf("unary_operator => '*' \n");}
	| '+'	{printf("unary_operator => '+' \n");}
	| '-'	{printf("unary_operator => '-' \n");}
	;

cast_expression
	: unary_expression {printf("cast_expression => unary_expression '+' \n");}
	;

multiplicative_expression
	: cast_expression	{printf("multiplicative_expression => cast_expression \n");}
	| multiplicative_expression '*' cast_expression {printf("multiplicative_expression => multiplicative_expression '*' cast_expression \n");}
	| multiplicative_expression '/' cast_expression	{printf("multiplicative_expression => multiplicative_expression '/' cast_expression \n");}
	| multiplicative_expression '%' cast_expression	{printf("multiplicative_expression => multiplicative_expression MOD cast_expression \n");}
	;

additive_expression
	: multiplicative_expression	{printf("additive_expression => multiplicative_expression\n");}
	| additive_expression '+' multiplicative_expression {printf("additive_expression => additive_expression '+' multiplicative_expression\n");}
	| additive_expression '-' multiplicative_expression{printf("additive_expression => additive_expression '-' multiplicative_expression\n");}
	;

shift_expression
	: additive_expression	{printf("shift_expression => additive_expression\n");}
	| shift_expression LEFT_OP additive_expression{printf("shift_expression => shift_expression << additive_expression\n");}
	| shift_expression RIGHT_OP additive_expression{printf("shift_expression => shift_expression >> additive_expression\n");}
	;

relational_expression
	: shift_expression {printf("relational_expression => shift_expression\n");}
	| relational_expression '<' shift_expression{printf("relational_expression => relational_expression '<' shift_expression\n");}
	| relational_expression '>' shift_expression{printf("relational_expression =>  relational_expression '>' shift_expression\n");}
	| relational_expression LE_OP shift_expression{printf("relational_expression => relational_expression '<=' shift_expression\n");}
	| relational_expression GE_OP shift_expression{printf("relational_expression => relational_expression '>=' shift_expression\n");}
	;

equality_expression
	: relational_expression	{printf("equality_expression => equality_expression\n");}
	| equality_expression EQ_OP relational_expression{printf("equality_expression => equality_expression == relational_expression\n");}
	| equality_expression NE_OP relational_expression{printf("equality_expression => equality_expression != relational_expression\n");}
	;

and_expression
	: equality_expression	{printf("and_expression => equality_expression\n");}
	| and_expression '&' equality_expression{printf("and_expression => and_expression '&' equality_expression\n");}
	;

exclusive_or_expression
	: and_expression {printf("exclusive_or_expression => and_expression\n");}
	| exclusive_or_expression '^' and_expression{printf("exclusive_or_expression => exclusive_or_expression '^' and_expression\n");}
	;

inclusive_or_expression
	: exclusive_or_expression	{printf("inclusive_or_expression => exclusive_or_expression\n");}
	| inclusive_or_expression '|' exclusive_or_expression	{printf("inclusive_or_expression=> inclusive_or_expression '|' exclusive_or_expression\n");}
	;

logical_and_expression
	: inclusive_or_expression{printf("logical_and_expression => inclusive_or_expression\n");}
	| logical_and_expression AND_OP inclusive_or_expression	{printf("logical_and_expression => logical_and_expression AND_OP inclusive_or_expression\n");}
	;

logical_or_expression
	: logical_and_expression{printf("logical_or_expression =>  logical_and_expression\n");}
	| logical_or_expression OR_OP logical_and_expression{printf("logical_or_expression =>  logical_or_expression || logical_and_expression\n");}
	;

conditional_expression
	: logical_or_expression{printf("conditional_expression => logical_or_expression\n");}
	| logical_or_expression '?' expression ':' conditional_expression{printf("conditional_expression => logical_or_expression '?' expression ':' conditional_expression\n");}
	;

assignment_expression
	: conditional_expression{printf("assignment_expression => conditional_expression\n");}
	| unary_expression assignment_operator assignment_expression{printf("assignment_expression => unary_expression assignment_operator assignment_expression\n");}
	;

assignment_operator
	: '='			{printf("assignment_operator => '='\n");}
	| MULTIPLY_ASSIGN	{printf("assignment_operator => MULTIPLY_ASSIGN\n");}
	| DIVIDE_ASSIGN		{printf("assignment_operator => DIVIDE_ASSIGN\n");}
	| MODULUS_ASSIGN	{printf("assignment_operator => MODULUS_ASSIGN\n");}
	| PLUS_ASSIGN		{printf("assignment_operator => PLUS_ASSIGN\n");}
	| MINUS_ASSIGN		{printf("assignment_operator => MINUS_ASSIGN\n");}
	| LEFT_ASSIGN		{printf("assignment_operator => LEFT_ASSIGN\n");}
	| RIGHT_ASSIGN		{printf("assignment_operator => RIGHT_ASSIGN\n");}
	| AND_ASSIGN		{printf("assignment_operator => AND_ASSIGN\n");}
	| XOR_ASSIGN		{printf("assignment_operator => XOR_ASSIGN\n");}
	| OR_ASSIGN		{printf("assignment_operator => OR_ASSIGN\n");}
	;

expression
	: assignment_expression	{printf("expression => assignment_expression\n");}
	| expression ',' assignment_expression{printf("expression => expression ',' assignment_expression\n");}
	;

constant_expression
	: conditional_expression{printf("constant_expression =>  conditional_expression\n");}
	;

declaration
	: declaration_specifiers ';'	{printf("declaration =>  declaration_specifiers ';'\n");}
	| declaration_specifiers init_declarator_list ';'{printf("declaration =>  declaration_specifiers init_declarator_list ';'\n");}
	;

declaration_specifiers
	: type_specifier	{printf("declaration_specifiers => type_specifier\n");}
	| type_specifier declaration_specifiers	{printf("declaration_specifiers => type_specifier declaration_specifiers\n");}
	;

init_declarator_list
	: init_declarator	{printf("init_declarator_list =>  init_declarator\n");}
	| init_declarator_list ',' init_declarator	{printf("init_declarator_list =>  init_declarator_list ',' init_declarator\n");}
	;

init_declarator
	: declarator	{printf("init_declarator =>  declarator\n");}
	| declarator '=' initializer	{printf("init_declarator =>declarator '=' initializer\n");}
	;


type_specifier
	: VOID	{printf("type_specifier =>  VOID\n");}
	| CHAR	{printf("type_specifier =>  CHAR\n");}
	| SHORT	{printf("type_specifier =>  SHORT\n");}
	| INT	{printf("type_specifier =>  INT\n");}
	| LONG	{printf("type_specifier =>  LONG\n");}
	| FLOAT	{printf("type_specifier =>  FLOAT\n");}
	| DOUBLE{printf("type_specifier =>  DOUBLE\n");}
	| MATRIX{printf("type_specifier =>  MATRIX\n");}
	| SIGNED{printf("type_specifier =>  SIGNED\n");}
	| UNSIGNED	{printf("type_specifier =>  UNSIGNED\n");}
	| BOOL	{printf("type_specifier =>  BOOL\n");}
	;

declarator
	: pointer direct_declarator	{printf("declarator =>  pointer direct_declarator\n");}
	| direct_declarator		{printf("declarator => direct_declarator\n");}
	;

direct_declarator
	: IDENTIFIER	{printf("direct_declarator =>  IDENTIFIER\n");}
	| '(' declarator ')'	{printf("direct_declarator =>  '(' declarator ')'\n");}
	| direct_declarator '[' ']'	{printf("direct_declarator =>  direct_declarator '[' ']'\n");}
	| direct_declarator '[' assignment_expression ']'	{printf("direct_declarator =>  direct_declarator '[' assignment_expression ']'\n");}
	| direct_declarator '(' parameter_type_list ')'	{printf("direct_declarator => direct_declarator '(' parameter_type_list ')'	\n");}
	| direct_declarator '(' identifier_list ')'	{printf("direct_declarator => direct_declarator '(' identifier_list ')'\n");}
	| direct_declarator '(' ')'	{printf("direct_declarator =>  direct_declarator '(' ')'\n");}
	;

pointer
	: '*'	{printf("pointer => '*'\n");}
	| '*' pointer	{printf("pointer =>  '*' pointer\n");}
	;

parameter_type_list
	: parameter_list	{printf("parameter_type_list =>   parameter_list\n");}
	;

parameter_list
	: parameter_declaration	{printf("parameter_list =>  parameter_declaration\n");}
	| parameter_list ',' parameter_declaration	{printf("parameter_list =>   parameter_list ',' parameter_declaration\n");}
	;

parameter_declaration
	: declaration_specifiers declarator	{printf("parameter_declaration=>  declaration_specifiers declarator\n");}
	| declaration_specifiers	{printf("parameter_declaration =>  declaration_specifiers\n");}
	;

identifier_list
	: IDENTIFIER	{printf("identifier_list => IDENTIFIER\n");}
	| identifier_list ',' IDENTIFIER	{printf("identifier_list => identifier_list ',' IDENTIFIER\n");}
	;

initializer
	: assignment_expression	{printf("initializer => assignment_expression\n");}
	| '{' initializer_row_list '}'	{printf("initializer => '{' initializer_row_list '}'\n");}
	;

initializer_row_list
	: initializer_row	{printf("initializer_row_list => initializer_row\n");}
	| initializer_row_list ';' initializer_row	{printf("initializer_row_list => initializer_row_list ';' initializer_row\n");}
	;

initializer_row
	: designation initializer	{printf("initializer_row =>  designation initializer\n");}
	| initializer			{printf("initializer_row =>  initializer\n");}
	| initializer_row ',' designation initializer	{printf("initializer_row =>  initializer_row ',' designation initializer\n");}
	| initializer_row ',' initializer	{printf("initializer_row =>  initializer_row ',' initializer\n");}
	;

designation
	: designator_list '='	{printf("designation =>  designator_list '='\n");}
	;

designator_list
	: designator	{printf("designator_list => designator\n");}
	| designator_list designator	{printf("designator_list =>  designator_list designator\n");}
	;

designator
	: '[' constant_expression ']'	{printf("designator => '[' constant_expression ']'\n");}
	| '.' IDENTIFIER	{printf("designator=> '.' IDENTIFIER\n");}
	;

statement
	: labeled_statement	{printf("statement => labeled_statement\n");}
	| compound_statement	{printf("statement => compound_statement\n");}
	| expression_statement	{printf("statement => expression_statement\n");}
	| selection_statement	{printf("statement => selection_statement\n");}
	| iteration_statement	{printf("statement =>  iteration_statement\n");}
	| jump_statement	{printf("statement => jump_statement\n");}
	;

labeled_statement
	: IDENTIFIER ':' statement	{printf("labeled_statement => IDENTIFIER ':' statement\n");}
	| CASE constant_expression ':' statement{printf("labeled_statement => CASE constant_expression ':'\n");}
	| DEFAULT ':' statement	{printf("labeled_statement => DEFAULT ':' statement\n");}
	;

compound_statement
	: '{' '}'	{printf("compound_statement => '{' '}'\n");}
	| '{' block_item_list '}'	{printf("compound_statement => '{' block_item_list '}'\n");}
	;

block_item_list
	: block_item	{printf("block_item_list => block_item\n");}
	| block_item_list block_item	{printf("block_item_list => block_item_list block_item\n");}
	;

block_item
	: declaration	{printf("block_item => declaration\n");}
	| statement	{printf("block_item => statement\n");}
	;


expression_statement
	: ';'			{printf("expression_statement => ';'\n");}
	| expression ';'	{printf("expression_statement => expression ';'\n");}
	;

selection_statement
	: IF '(' expression ')' statement	{printf("selection_statement => IF '(' expression ')' statement\n");}
	| IF '(' expression ')' statement ELSE statement	{printf("selection_statement => IF '(' expression ')' statement ELSE statement\n");}
	| SWITCH '(' expression ')' statement	{printf("selection_statement => SWITCH '(' expression ')' statement\n");}
	;

iteration_statement
	: WHILE '(' expression ')' statement	{printf("iteration_statement => WHILE '(' expression ')' statement\n");}
	| DO statement WHILE '(' expression ')' ';'	{printf("iteration_statement => DO statement WHILE '(' expression ')' ';'\n");}
	| FOR '(' ';' ';' ')' statement		{printf("iteration_statement =>FOR '(' ';' ';' ')' statement\n");}
	| FOR '(' ';' ';' expression ')' statement	{printf("iteration_statement => FOR '(' ';' ';' expression ')' statement\n");}
	| FOR '(' ';' expression ';' ')' statement	{printf("iteration_statement => FOR '(' ';' expression ';' ')' statement\n");}
	| FOR '(' ';' expression ';' expression ')' statement	{printf("iteration_statement => FOR '(' ';' expression ';' expression ')' statement\n");}
	| FOR '(' expression ';' ';' ')' statement	{printf("iteration_statement =>  FOR '(' expression ';' ';' ')' statement\n");}
	| FOR '(' declaration ';' expression ')' statement	{printf("iteration_statement => FOR '(' declaration ';' expression ')' statement\n");}
	| FOR '(' declaration expression ';' ')' statement	{printf("iteration_statement => FOR '(' declaration expression ';' ')' statement\n");}
	| FOR '(' declaration expression ';' expression ')' statement	{printf("iteration_statement => FOR '(' declaration expression ';' expression ')' statement\n");}
	| FOR '(' expression ';' ';' expression ')' statement	{printf("iteration_statement => FOR '(' expression ';' ';' expression ')' statement\n");}
	| FOR '(' expression ';' expression ';' ')' statement	{printf("iteration_statement => FOR '(' expression ';' expression ';' ')' statement\n");}
	| FOR '(' expression ';' expression ';' expression ')' statement	{printf("iteration_statement => WHILE '(' expression ')' statement\n");}
	| FOR '(' declaration ';' ')' statement	{printf("iteration_statement => FOR '(' declaration ';' ')' statement\n");}
	;

jump_statement
	: GOTO IDENTIFIER ';'	{printf("jump_statement =>  GOTO IDENTIFIER ';'\n");}
	| CONTINUE ';'		{printf("jump_statement =>  CONTINUE ';'\n");}
	| RETURN ';'		{printf("jump_statement =>  RETURN ';'\n");}
	| RETURN expression ';'	{printf("jump_statement =>  RETURN expression ';'\n");}
	| BREAK ';'		{printf("jump_statement =>  BREAK ';'\n");}
	;

translation_unit
	: external_declaration	{printf("translation_unit =>  external_declaration\n");}
	| translation_unit external_declaration	{printf("translation_unit =>  translation_unit external_declaration\n");}
	;

external_declaration
	: function_definition	{printf("external_declaration =>  function_definition\n");}
	| declaration		{printf("external_declaration =>  declaration\n");}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement	{printf("function_definition => declaration_specifiers declarator declaration_list compound_statement\n");}
	| declaration_specifiers declarator compound_statement	{printf("function_definition =>  declaration_specifiers declarator compound_statement\n");}
	;

declaration_list
	: declaration	{printf("declaration_list =>  declaration");}
	| declaration_list declaration	{printf("declaration_list =>  declaration_list declaration\n");}
	;

%%

void yyerror(char *s) 
{
	printf ("ERROR: %s\n",s);
	yyparse();
}
