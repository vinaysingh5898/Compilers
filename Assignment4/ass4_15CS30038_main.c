#include "y.tab.h"
#include <stdio.h>

extern "C" {
  char* yytext;
  int yyparse();
}

int main() {
  int token;
  yyparse();
  return 0;
}
