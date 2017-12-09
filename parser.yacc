%{
#include <stdio.h>
#include <iostream>
#include "global.h"

int yylex(void);
void yyerror(char *);
%}

%union {
    char* str;
    int num;
}

%token NEWLINE
%type <str> STRING
%type <num> INTEGER
%start start
%%

start: STRING NEWLINE
     |
     ;

%%
void yyerror(char *msg)
{
   fprintf(stderr,"%s, line number: %d\n", msg, yylineno);
}
