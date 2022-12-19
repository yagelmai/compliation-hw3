%{

/* Declarations section */
#include <stdio.h>
void printundef();
#include "hw3_output.hpp"
#include "parser.tab.hpp"
#include "parser.hpp"
using namespace output;
#include <iostream>
#include <stdlib.h>
%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([\t\n\r ])
es              (\x5C\x5C|\x5C\x22|\x5C\x6E|\x5C\x72|\x5C\x74|\x5C\x30|\x5C\x78[0-9A-F][0-9A-F]|\\[^"])

l_binop [(\*|\/)]
r_binop [(\+|\-)]
%%

void                        return VOID;
int                         {yylval = new Number(TYPE_INT,stoi(yytext)); return INT;}
byte                        return BYTE;
b                           return B;
bool                        return BOOL;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
if                          return IF;
else                        return ELSE;
while                       return WHILE;
break                       return BREAK;
continue                    return CONTINUE;
;                           return SC;
\,                          return COMMA;
\(                          return LPAREN;
\)                          return RPAREN;
\{                          return LBRACE;
\}                          return RBRACE;
=                           return ASSIGN;
==|!=|<=|>=|<|>             return RELATIONAL;
{l_binop}                   return MULTIPLICATIVE;
{r_binop}                   return ADDITIVE;
[a-zA-Z][0-9a-zA-Z]*        return ID;
[1-9][0-9]*|0               return NUM;//what to do when number starts with 0?
\"([^\n\r\"\\]|\\[rnt"\\])+\" return STRING;
\"([^\\\n\r\"]|{es})*       errorLex(yylineno);exit(0);
{whitespace}|\/\/[^\r\n]* 				;
.		                    errorLex(yylineno);exit(0);

%%

