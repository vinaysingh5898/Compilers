#include "ass4_15CS30038_translator.h"

sym_table* gTable;		
quad_array qarr;						
type_e TYPE;							
sym_table* table;					
sym* currsym; 
bool gDebug = false;				



Singleton* Singleton::pSingleton= NULL;

Singleton::Singleton() {	}

Singleton* Singleton::GetInstance() {
	if (pSingleton== NULL) {
		pSingleton = new Singleton();
	}
	return pSingleton;
}

int size_type (sym_type* t){
	if(t->cat == _VOID)
			return 0;
		else if(t->cat == FUNC)
			return 0;
		else if(t->cat == _CHAR)
			return size_of_char;
		else if(t->cat == _INT)
			return size_of_int;
		else if(t->cat == PTR)
			return size_of_pointer;
		else if(t->cat == _DOUBLE)
			return 8;
		else if(t->cat == ARR)
			return t->width * t->len *8;
}

sym* gentemp (type_e t, string init) {
	char n[20],m[20];
	sprintf(n, "t%02d", table->tcount++);
	sym* s = new sym (n,t);
	s-> init = init;
	s->category = "temp";
	table->table.push_back (*s);
	if (gDebug) table->print();
	return &table->table.back();
}

string con_to_string (const sym_type* t){
		if (t == NULL) 
			return "null";
		else if(t->cat == _DOUBLE) 
			return "double";
		else if(t->cat == _VOID)
			return "void";
		else if(t->cat == PTR) 
			return "ptr("+ con_to_string(t->ptr)+")";
		else if(t->cat == ARR) 
			return "Matrix(" + tostr(t->width) + ", "+ tostr(t->len)  + ", double )";
		else if(t->cat == FUNC) 
			return "funct";
		else if(t->cat == _CHAR)
			return "char";
		else if(t->cat == _INT) 
			return "int";
}

sym_type::sym_type(type_e cat, sym_type* ptr, int width,int len): 
	ptr (ptr), 
	cat (cat), 
	len (len),
	width (width) {};

sym* sym_table::lookup (string name) {
	list <sym>::iterator it;
	sym* s;
	for (it = table.begin(); it!=table.end(); it++) {
		if (it->name == name ) 
			break;
	}if (it!=table.end() ) {
		//if (gDebug) cout << name << " already present" << endl;
		return &*it;
	}else {
			s =  new sym (name);
			s->category = "local";
			table.push_back (*s);
			if (gDebug) print();
			return &table.back();	
	}
}


sym* gentemp (sym_type* t, string init) {
	char n[20];
	sprintf(n, "t%02d", table->tcount++);
	sym* s = new sym (n);
	s->category = "temp";
	s->type = t;
	table->table.push_back ( *s);
	s-> init = init;
	if (gDebug) table->print();
	return &table->table.back();
}

sym_table::sym_table (string name): tname (name), tcount(0) {}

void sym_table::print(int all) {
	list<sym_table*> tablelist;
	cout << setw(80) << setfill ('=') << "="<< endl;
	cout << "Symbol Table: " << setfill (' ') << left << setw(35)  << this -> tname ;
	cout << right << setw(20) << "Parent: ";
	if (this->parent!=NULL)
		cout << this -> parent->tname;
	else cout << "null" ;
	cout << endl;
	cout << setw(80) << setfill ('-') << "-"<< endl;
	cout << setfill (' ') << left << setw(16) << "Name";
	cout << left << setw(16) << "Type";
	cout << left << setw(12) << "Category";
	cout << left << setw(12) << "Init Val";
	cout << left << setw(8) << "Size";
	cout << left << setw(8) << "Offset";
	cout << left << "Nest" << endl;
	cout << setw(80) << setfill ('-') << "-"<< setfill (' ') << endl;
	
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		cout << &*it;
		if (it->nest!=NULL) tablelist.push_back (it->nest);
		
	}
	cout << setw(80) << setfill ('-') << "-"<< setfill (' ') << endl;
	cout << endl;
	if (all) {
		for (list<sym_table*>::iterator iterator = tablelist.begin();
				iterator != tablelist.end();
				++iterator) {
		    (*iterator)->print();
		}		
	}
}



sym* sym::linkst(sym_table* t) {
	this->nest = t;
	this->category = "function";
}

list<int> makelist (int i) {
	list<int> l(1,i);
	return l;
}

sym* sym::update(type_e t) {
	this->type = new sym_type(t);
	this->size = size_type(this->type);
	if (gDebug) table->print();
	return this;
}


ostream& operator<<(ostream& os, const sym* it) {
	os << left << setw(16) << it->type;
	os << left << setw(12) << it->category;
	os << left << setw(16) << it->name;
	os << left << setw(8) << it->offset;
	os << left << setw(12) << it->init;
	os << left << setw(8) << it->size;
	os << left;
	if (it->nest == NULL) {
		os << "null" <<  endl;	
	}else {
		os << it->nest->tname <<  endl;
	}
	return os;
}

quad::quad (string result, string arg1, optype op, string arg2):
	result (result), arg1(arg1), arg2(arg2), op (op){};

quad::quad (string result, int arg1, optype op, string arg2):
	result (result), arg2(arg2), op (op) {
		this ->arg1 = num_to_string(arg1);
	}

sym* sym::initialize (string init) {
	this->init = init;
}

sym::sym (string name, type_e t, sym_type* ptr, int width): name(name)  {
	type = new sym_type (sym_type(t, ptr, width));
	size = size_type(type);
	nest = NULL;
	category = "";
	init = "";
	offset = 0;
}


sym* sym::update(sym_type* t) {
	type = t;
	this -> size = size_type(t);
	if (gDebug) table->print();
	return this;
}

void quad::update (int addr) {	// Used for backpatching address
	this ->result = addr;
}


ostream& operator<<(ostream& os, const sym_type* t) {
	type_e cat = t->cat;
	string stype = con_to_string(t);
	os << stype;
	return os;
}

void quad::print () {
	if(op == ADD) {
		cout << result << " = " << arg1 << " + " << arg2;	
	}
	else if(op == SUB) {
		cout << result << " = " << arg1 << " - " << arg2;	
	}
	else if(op == MODOP)	{
		cout << result << " = " << arg1 << " % " << arg2;	
	}
	else if(op == XOR) {
		cout << result << " = " << arg1 << " ^ " << arg2;	
	}
	else if(op == MULT) {
		cout << result << " = " << arg1 << " * " << arg2;	
	}
	else if(op == DIVIDE) {
		cout << result << " = " << arg1 << " / " << arg2;	
	}	
	else if(op == LEFTOP)		
		cout << result << " = " << arg1 << " << " << arg2;				 
	else if(op == RIGHTOP)		
		cout << result << " = " << arg1 << " >> " << arg2;				 
	else if(op == EQUAL)			
		cout << result << " = " << arg1 ;
	else if(op == GT)			
		cout << "if " << arg1 <<  " > "  << arg2 << " goto " << result;			 
	else if(op == GOTOOP)		
		cout << "goto " << result;	
	else if(op == EQOP)			
		cout << "if " << arg1 <<  " == " << arg2 << " goto " << result;					 
	else if(op == GE)			
		cout << "if " << arg1 <<  " >= " << arg2 << " goto " << result;				 
	else if(op == LE)			
		cout << "if " << arg1 <<  " <= " << arg2 << " goto " << result;				 
	else if(op == NEOP)			
		cout << "if " << arg1 <<  " != " << arg2 << " goto " << result;				 
	else if(op == LT)			
		cout << "if " << arg1 <<  " < "  << arg2 << " goto " << result;				 
	else if(op == INOR)		
		cout << result << " = " << arg1 << " | " << arg2;				 
	else if(op == BAND)			
		cout << result << " = " << arg1 << " & " << arg2;
	else if(op == ADDRESS)		
		cout << result << " = &" << arg1;
	else if(op == LABEL)			
		cout << result << ": ";					 
	else if(op == PTRL)			
		cout << "*" << result	<< " = " << arg1 ;
	else if(op == BNOT)			
		cout << result 	<< " = ~" << arg1;
	else if(op == CALL) 			
		cout << result << " = " << "call " << arg1<< ", " << arg2;		 
	else if(op == UMINUS)		
		cout << result 	<< " = -" << arg1;				 
	else if(op == PTRR)			
		cout << result	<< " = *" << arg1 ;				 				 				 
	else if(op == ARRR)	 		
		cout << result << " = " << arg1 << "[" << arg2 << "]";
	else if(op == LNOT)		
		cout << result 	<< " = !" << arg1;			 
	else if(op == ARRL)	 		
		cout << result << "[" << arg1 << "]" <<" = " <<  arg2;			 
	else if(op == _RETURN) 		
		cout << "ret " << result;				 
	else if(op == PARAM) 		
		cout << "param " << result;				 				 
	cout << endl;
}

void quad_array::printtab() {
	cout << "=== Quad Table ===" << endl;
	cout << setw(8) << "index";
	cout << setw(8) << " op";
	
	cout << setw(8) << "arg 1";
	cout << setw(8) << "arg 2";
	cout << setw(8) << "result" << endl;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << left << setw(8) << it - array.begin(); 
		cout << left << setw(8) << optostr(it->op);
		
		cout << left << setw(8) << it->arg1;
		cout << left << setw(8) << it->arg2;
		cout << left << setw(8) << it->result << endl;
	}
}

void backpatch (list <int> l, int addr) {
	for (list<int>::iterator it= l.begin(); it!=l.end(); it++) qarr.array[*it].result = tostr(addr);
	if (gDebug) qarr.printtab();
}

list<int> merge (list<int> &a, list <int> &b) {
	a.merge(b);
	return a;
}

void quad_array::print () {
	cout << setw(30) << setfill ('=') << "="<< endl;
	cout << "Quad-Translation" << endl;
	cout << setw(30) << setfill ('-') << "-"<< setfill (' ') << endl;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		if (it->op != LABEL) {
			
			cout << "\t" << setw(4) << it - array.begin() << ":\t";
			it->print();
		}else {
			cout << "\n";
			it->print();
			
			cout << "\n";
		}
	}
	cout << setw(30) << setfill ('-') << "-"<< endl;
}

void emit(optype op, string result, string arg1, string arg2) {
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));
	if (gDebug) qarr.print();
}

expr* con_to_bool (expr* e) {	
	if (!e->isbool) {
		e->falselist = makelist (nextinstr());
		emit (EQOP, "", e->symt->name, "0");
		e->truelist = makelist (nextinstr());
		emit (GOTOOP, "");
	}else {
		
	}
}

void sym_table::computeOffsets() {
	list<sym_table*> tablelist;
	int off;
	
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		if (it==table.begin()) {
			it->offset = 0;
			off = it->size;
		}else {
			it->offset = off;
			off = it->offset + it->size;
		}if (it->nest!=NULL) tablelist.push_back (it->nest);
		
	}for (list<sym_table*>::iterator iterator = tablelist.begin(); 
			iterator != tablelist.end(); 
			++iterator) {(*iterator)->computeOffsets();
	}
}

void printlist (lint l) {	// Print integers in list l 
	for (list<int>::iterator iterator = l.begin(); iterator != l.end(); ++iterator) {
	    if (gDebug) cout << *iterator << " ";
	}
	cout << endl;
}

void emit(optype op, string result, int arg1, string arg2) {
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));
	
	if (gDebug) qarr.print();
}

string optostr (int op) {
		if(op == ADD)				
			return " + ";
		else if(op == EQUAL)				
			return " = ";
		else if(op == UMINUS)			
			return " -";
		else if(op == BNOT)				
			return " ~";
		else if(op == MULT)				
			return " * ";
		else if(op == PTRL)				
			return " *L";
		else if(op == ARRR)	 			
			return " =[]R";
		else if(op == SUB)				
			return " - ";
		else if(op == DIVIDE)			
			return " / ";
		else if(op == PARAM) 			
			return " param ";
		else if(op == CALL) 				
			return " call ";
		else if(op == PTRR)				
			return " *R";
		else if(op == EQOP)				
			return " == ";
		else if(op == LNOT)				
			return " !";
		else if(op == NEOP)				
			return " != ";
		else if(op == GOTOOP)			
			return " goto ";
		else if(op == ADDRESS)			
			return " &";
		else if(op == GT)			
			return " > ";
		else if(op == GE)				
			return " >= ";
		else if(op == _RETURN) 			
			return " ret";
		else if(op == LT)				
			return " < ";
		else if(op == LE)				
			return " <= ";
}



string num_to_string ( int Number ) {
	ostringstream ss;
	ss << Number;
	return ss.str();
}

int nextinstr() {
	return qarr.array.size();
}

bool typecheck(sym*& p1, sym*& p2){ 	// Check if the symbols have same type or not
	sym_type* type2 = p2->type;
	sym_type* type1 = p1->type;
	if (p2 = conv (p2, type1->cat) ) return true;
	else if (p1 = conv (p1, type2->cat) ) return true;
	else if ( typecheck (type1, type2) ) return true;
	return false;
}

expr* con_from_bool (expr* e) {	
	if (e->isbool) {
		backpatch (e->truelist, nextinstr());
		e->symt = gentemp(_INT);
		emit (GOTOOP, tostr (nextinstr()+1));
		emit (EQUAL, e->symt->name, "true");
		emit (EQUAL, e->symt->name, "false");
		backpatch (e->falselist, nextinstr());
	}else {
		
	}
}

int typecheck1(){
	return 0;
}

bool typecheck(sym_type* q1, sym_type* q2){ 	// Check if the symbol types are same or not
	if (q1 != NULL || q2 != NULL) {
		if (q1==NULL) return false;
		if (q2==NULL) return false;
		int q3 = 0;
		if (q1->cat==q2->cat) return (q1->ptr, q2->ptr);
		else return false;
	}
	return true;
}


void changeTable (sym_table* newtable, int kx ) {	// Change current symbol table
	if (gDebug)	cout << "Symbol table changed from " << table->tname;
	table = newtable;
	if (gDebug)	cout << " to " << table->tname << endl;
} 

sym* conv (sym* s, type_e t) {
	sym* temp = gentemp(t);
	switch (s->type->cat) {
		case _INT: {
			if(t== _DOUBLE){
					emit (EQUAL, temp->name, "int2double(" + s->name + ")");
					return temp;

			}else if(t== _CHAR){
				emit (EQUAL, temp->name, "int2char(" + s->name + ")");
					return temp;
			}
			return s;
		}
		case _CHAR: {
			if(t== _INT){
				emit (EQUAL, temp->name, "char2int(" + s->name + ")");
				return temp;
				} else if(t== _DOUBLE){
					emit (EQUAL, temp->name, "char2double(" + s->name + ")");
					return temp;
				}
			return s;
		}
		case _DOUBLE: {

			if(t== _INT){
				emit (EQUAL, temp->name, "double2int(" + s->name + ")");
					return temp;
				} else if(t== _CHAR){
				emit (EQUAL, temp->name, "double2char(" + s->name + ")");
					return temp;
				}
			return s;
		}
	}
	return s;
}



int  main (int argc, char* argv[]){
	int n,x;
	if (argc>1) gDebug = true;
	gTable = new sym_table("Global");
	table = gTable;
	yyparse();
	table->computeOffsets();
	table->print(1);
	qarr.print();
	cin >> n;int gptable;
	if (n==10) {
		while (n--) {
			cin >> x;
			if(x==2) {
				emit(ADD, "a", "b", "c");
			}
			else if (x==1) {
				gentemp(_DOUBLE);
			}
		}	
	}

};
