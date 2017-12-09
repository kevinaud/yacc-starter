#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Node {
    private:
        string name;
        int weight;
        vector<Node*> children;

        string weightToStr();
        string dependenciesToStr();

    public:
        Node(string name, int weight, vector<Node*> children);
        Node(string name);

        Node* search(string name);

        int getSize();

        vector<Node*> getChildren();
        string getName();
        void setWeight(int weight);

        void print(string offset = "");
};

void addChild(string name, vector<Node*> &children, vector<Node*> &trees);
void printStatus(
    string name,
    int weight,
    vector<Node*> &children,
    vector<Node*> &trees
);

extern Node *currentNode;
extern string name;
extern int weight;
extern vector<Node*> children;
extern vector<Node*> trees;
extern int yylineno;
