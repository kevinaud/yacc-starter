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

    /* vector<Node*> empty; */

    /* vector<Node*> childrenB; */
    /* childrenB.push_back(new Node("D", 4, empty)); */
    /* childrenB.push_back(new Node("E", 5, empty)); */
    /* childrenB.push_back(new Node("F", 6, empty)); */

    /* vector<Node*> childrenC; */
    /* childrenC.push_back(new Node("G", 7, empty)); */
    /* childrenC.push_back(new Node("H", 8, empty)); */
    /* childrenC.push_back(new Node("I", 9, empty)); */

    /* Node* nodeB = new Node("B", 2, childrenB); */
    /* Node* nodeC = new Node("C", 3, childrenC); */

    /* vector<Node*> childrenA; */
    /* childrenA.push_back(nodeB); */
    /* childrenA.push_back(nodeC); */

    /* Node* nodeA = new Node("A", 1, childrenA); */
    
    /* nodeA->print(); */
    
    /* Node* result = node->search("child1"); */

    /* if (result) { */
    /*     result->print(); */ 
    /* } */

    /* node->print(); */
    
    /* int ntoken, vtoken; */

    /* ntoken = yylex(); */
    /* while (ntoken) { */
    /*     printf("%s\n", names[ntoken]); */
    /*     if (ntoken == SEMICOLON) { */
    /*         printf("\n"); */
    /*     } */
    /*     ntoken = yylex(); */
    /* } */

    return 0;
}
