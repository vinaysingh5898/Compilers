%{
#include "ass4_15CS30038_translator.h"
#include <stdio.h>
#include <math.h>
#include "y.tab.h"
extern void yyerror(char *s);
void comment();
%}

/* Regular Expression Definitions */

Digit					[0-9]
Id_N_Digit			 	[a-zA-Z_]
nonzero_digit				[1-9]
Identifier				{Id_N_Digit}({Id_N_Digit}|{Digit})*
Int_Constant 				{nonzero_digit}{Digit}*

Exp					([Ee][+-]?{Digit}+)
Float_Ct 				({Frac_Ct}{Exp}?)|({Digit}+{Exp})
Frac_Ct 				(({Digit}+)?\.{Digit}+)|(({Digit}+)\.)
 
EC 					{ID}
Esc_Seq					\\["'?\\abfnrtv]
cchar 					[^'\\\n]|{Esc_Seq}
Ch_const 				'({cchar})+'

schar 					[^"\\\n]|{Esc_Seq}
Str_literal				\"({schar}+)\"

WS  					[ \t\v\n\f]

%%


"/*"					{ comment();}
"//".*  		   		{  }
"for"					{return FOR;}
"signed"				{return SIGNED;}
"unsigned"				{return UNSIGNED;} 
"break"					{return BREAK;}
"case"					{return CASE;}
"float"					{return FLOAT;}
"Bool"					{return BOOL;}
"continue"				{return CONTINUE;}
"do"					{return DO;}
"void"					{return VOID;}
"short"					{return SHORT;}
"int"					{return INT;}
"long"					{return LONG;}
"else"					{return ELSE;}
"return"				{return RETURN;} 
"char"					{return CHAR;}
"while"					{return WHILE;}
"switch"				{return SWITCH;} 
"double"				{return DOUBLE;}
"Matrix"				{return MATRIX;}
"goto"					{return GOTO;}
"if"					{return IF;}
"default"				{return DEFAULT;}

{Int_Constant} 				{ yylval.intvalue = atoi(yytext);
					  return INT_CONSTANT; }

{Float_Ct} 				{ yylval.strval = yytext;
					  return FLOAT_CONSTANT; }

{Ch_const} 				{ return CHAR_CONSTANT; }

"0"					{ return ZERO_CONSTANT; }

{Str_literal} 				{ yylval.strval = yytext;
					  return STRING_LITERAL; }

{Identifier}				{ yylval.symt = table->lookup(yytext);
					  return IDENTIFIER; }

"["					{ return '['; }
"]"					{ return ']'; }
"{"					{ return '{'; }
"}"					{ return '}'; }
"."					{ return '.'; }
"("					{ return '('; }
")"					{ return ')'; }
"->"					{ return POINTER_OP; }
"++"					{ return INCREMENT_OP; }
"--"					{ return DECREMENT_OP; }
"&"					{ return '&'; }
"*"					{ return '*'; }
"!"					{ return '!'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"+"					{ return '+'; }
"-"					{ return '-'; }
"~"					{ return '~'; }
".'"					{return POINTCOL;}
"<<"					{ return LEFT_OP; }
">>"					{ return RIGHT_OP; }
"<"					{ return '<'; }
">"					{ return '>'; }
"<="					{ return LE_OP; }
">="					{ return GE_OP; }
"=="					{ return EQ_OP; }
"!="					{ return NE_OP; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"&&"					{ return AND_OP; }
"||"					{ return OR_OP; }
"?"					{ return '?'; }
":"					{ return ':'; }
";"					{ return ';'; }
"="					{ return '='; }
"*="					{ return MULTIPLY_ASSIGN; }
"/="					{ return DIVIDE_ASSIGN; }
"%="					{ return MODULUS_ASSIGN; }
"+="					{ return PLUS_ASSIGN; }
"-="					{ return MINUS_ASSIGN; }
"<<="					{ return LEFT_ASSIGN; }
">>="					{ return RIGHT_ASSIGN; }
"&="					{ return AND_ASSIGN; }
"^="					{ return XOR_ASSIGN; }
"|="					{ return OR_ASSIGN; }
","					{ return ','; }
"#"					{ return '#'; }
{WS}					{ }

%%

int column = 0;
void count(void) {
	int i;
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n') column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	ECHO;
}
void comment(void) {
	char c, prev = 0;
	while ((c = getchar()) != 0) {     /* (EOF maps to 0) */
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
//	yyerror("unterminated comment");
}
