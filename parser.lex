%{ 
#include "global.h"
#include "y.tab.h"
%}
%option yylineno
%%
\n      return NEWLINE;

[a-z]+  { yylval.str = strdup(yytext); return STRING; };
[0-9]+  { 
            yylval.num = atoi(yytext);
            return INTEGER;
        };
[ \t]  ;
.      printf("unexpected character\n");
%%
int yywrap(void)
{
    return 1;    
}
