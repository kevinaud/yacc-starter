#include <stdio.h>
#include <iostream>

#include "global.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;

int yyparse(void);

int main(void) {

    yyparse();

    return 0;
}
