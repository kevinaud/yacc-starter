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

%token ARROW COMMA OPEN_PEREN CLOSE_PEREN NEWLINE
%type <str> STRING
%type <num> INTEGER
%start towerList
%%

towerList: tower towerList 
     |
     ;

tower: STRING towerWeight dependencies NEWLINE { 

            string name = $1;

            trees.push_back(new Node(name, weight, children));

            children.clear();
       };
     | STRING towerWeight NEWLINE { 

            string name = $1;

            bool found = false;
            Node* result;
            for (int i = 0; i < trees.size(); i++) {
                if (!found) {
                    result = trees[i]->search(name);
                    if (result) {
                        found = true;
                    }
                }
            }

            if (found) {
                result->setWeight(weight);
            } else {
                trees.push_back(new Node(name, weight, children));
            }
       };

towerWeight: OPEN_PEREN INTEGER CLOSE_PEREN {
        weight = $2;
    };

dependencies: ARROW dependencyList
            |
            ;

dependencyList: STRING COMMA dependencyList { 
                    addChild($1, children, trees);
                }
              | STRING {
                    addChild($1, children, trees);
                }
              ;

%%
void yyerror(char *msg)
{
   fprintf(stderr,"%s, line number: %d\n", msg, yylineno);
}
