#include <stdio.h>
#include "y.tab.h"

extern char* yytext;

int main() 
{
    	int token;
    	while (token = yylex()) {
    	switch (token) {

      case IDENTIFIER: printf("<IDENTIFIER, %d, %s>\n",token, yytext); 
			break;
      case INT_CONSTANT: printf("<INT_CONSTANT, %d, %s>\n",token, yytext); 
			break;
      case ZERO_CONSTANT: printf("<ZERO_CONSTANT, %d, %s>\n",token, yytext); 
			break;
      case CHAR_CONSTANT: printf("<CHAR_CONSTANT, %d, %s>\n",token, yytext); 
			break;
      case FLOAT_CONSTANT: printf("<FLOAT_CONSTANT, %d, %s>\n",token, yytext);  
			break;

      case STRING_LITERAL: printf("<STRING LITERAL, %d, %s>\n",token, yytext); 
			break;
      case PUNCTUATORS: printf("<PUNCTUATORS, %d, %s>\n",token, yytext); 
			break;

      case BREAK:
      case LONG:
      case RETURN:
      case SHORT:
      case CASE:
      case CHAR:
      case DO:
      case DOUBLE:
      case ELSE:
      case CONTINUE:
      case DEFAULT:
      case UNSIGNED:
      case VOID:
      case WHILE:
      case BOOL:
      case MATRIX:
      case FLOAT:
      case FOR:
      case GOTO:
      case IF:
      case INT:
      case SIGNED:
      case SWITCH:
      
	printf("<KEYWORD, %d, %s>\n",token, yytext); 
		break;

      default: 	printf("<PUNCTUATOR, %d, %s>\n",token, yytext); 
		break;
    }
  }
}
