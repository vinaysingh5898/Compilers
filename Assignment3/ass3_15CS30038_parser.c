#include <stdio.h>
#include "y.tab.h"

extern char* yytext;
extern int yyparse();
extern void yyerror(char *s);
extern int yylex();

int main() 
{
	yyparse();
  	return 0;
}
