#ifndef _ASS4_15CS30038_TRANSLATOR_H
#define _ASS4_15CS30038_TRANSLATOR_H
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>

#define debug(x) do { \
  if (gDebug) { cerr << x << std::endl; } \
} while (0)

#define size_of_char 		1
#define size_of_pointer		4	
#define size_of_double		8
#define size_of_int  		4

extern  char* yytext;
extern  int yyparse();
using namespace std;

class sym;
class sym_type;			
class quad_array;			

enum type_e {_VOID, _CHAR, _INT, _DOUBLE, PTR, ARR, FUNC}; 	
enum optype { EQUAL, LT, GT,PTRL, PTRR,ARRR, LE, GE, EQOP, 
	NEOP,
	PARAM, 
	CALL, LABEL,GOTOOP, _RETURN,RIGHT_POINTER,
	 BNOT,ADD, SUB, MULT, DIVIDE, 
	 RIGHTOP, LEFTOP, MODOP,UMINUS, 
	 UPLUS, ADDRESS, LNOT,BAND, XOR, INOR, ARRL};

class quad;
class sym_table;
class sym_ptr;

/* Declaration of Classes */

class sym_type { 

public:
	sym_type(type_e cat, sym_type* ptr = NULL, int width = 1, int len=1);
	type_e cat;int width;int len;
	sym_type* ptr;		// Array -> array of ptr type; pointer-> pointer to ptr type 
	friend ostream & operator<<(ostream&, const sym_type);
};

class sym_ptr {

public:
//sym_temp(int width,sum_type* ptr);
 sym_type* ppx;
 type_e cat;
 int r;

};

class sym_table { 

public:
	string tname; 
	int tcount;
	list <sym> table; 
	sym_table* parent;
	sym_table (string name="");
	void computeOffsets();						// Compute offset of the whole symbol table recursively
	sym* lookup (string name);					// Lookup for a symbol in symbol table
	void print(int all = 0);					// Print the symbol table
};


class quad { 

public:
	string result;
	optype op; 
	string arg2;				
	string arg1; 

	quad (string result, string arg1, optype op = EQUAL, string arg2 = "");
	quad (string result, int arg1, optype op = EQUAL, string arg2 = "");
	void print ();					// Print quad_array
	void update (int addr);			// Used for backpatching address

};




class sym { 

public:
	string category ; 
	string name ;
	sym_type *type ;
	string init ; 
	int offset ; 
	int size ; 
	sym_table* nest ;				
	sym (string, type_e t=_INT, sym_type* ptr = NULL, int width = 0);
	sym* initialize (string);
	sym* update(type_e t); 		
	sym* update(sym_type * t); 	
	friend ostream& operator<<(ostream&, const sym*);
	sym* linkst(sym_table* t);
};

class quad_array { 

public:
	vector <quad> array;;		// Vector of a quad-array
	quad_array () {array.reserve(300);}
	void printtab();			// Print quad_array data in tabular form
	void print ();				// Print all the quad-array
};

int nextinstr();									
string num_to_string(int);

class Singleton {	

public:
   static Singleton* GetInstance();

private:
   Singleton();
static Singleton* pSingleton;					// singleton instance
};

/* Declartion of functions */

string optostr(int);
int size_type (sym_type*);							// Calculate size of any type

sym* gentemp (type_e t=_INT, string init = "");		// Generate a temporary variable and insert it in symbol table
sym* gentemp (sym_type* t, string init = "");		// Generate a temporary variable and insert it in symbol table

typedef list<int> lint;
list<int> makelist (int);							// Make a new list contaninig an integer
list<int> merge (list<int> &, list <int> &);		// Merge two lists


string con_to_string (const sym_type*);			// For printing type structure

void backpatch (list <int>, int);
void emit(optype op, string result, int arg1, string arg2 = "");
void emit(optype opL, string result, string arg1="", string arg2 = "");


sym* conv (sym*, type_e);							// Convert symbol to different type
bool typecheck(sym* &s1, sym* &s2);					// Checks if two symbbol table entries have same type
bool typecheck(sym_type* s1, sym_type* s2);			// Check if the type objects are equivalent



extern sym* currsym;			// Pointer to just encountered symbol
extern quad_array qarr;			// quad_array
extern sym_table* table;			// Current Symbbol Table
extern sym_table* gTable;			// Global Symbbol Table

void printlist (lint list);		// Print list of integers

struct expr {
	bool isbool;		// boolean variable to store if exp is bool
	sym* symt;			
	lint truelist; 
	lint falselist;	
	lint nextlist;
};


struct unary {
	sym_type* type;
	type_e cat;
	bool is_matrix;
	sym* symt;				
	sym* loc; 
};

struct statement {
	lint nextlist;	
};

expr* con_to_bool (expr*);				
expr* con_from_bool (expr*);	

							

void changeTable (sym_table* newtable,int kx);

// Utility functions
template <typename T> string tostr(const T& t) { 
   ostringstream os; os<<t; 
   return os.str(); 
} 
#endif
