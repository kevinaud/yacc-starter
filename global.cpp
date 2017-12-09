#include "global.h"

Node *currentNode;
string name;
int weight;
vector<Node*> children;

vector<Node*> trees;

Node::Node(string name, int weight, vector<Node*> children) {
    this->name = name;
    this->weight = weight;
    this->children = children;
}

Node::Node(string name) {
    this->name = name;
    this->weight = 0;
}

Node* Node::search(string name) {
    int numChildren = this->children.size();
    if (this->name == name) {
        return this; 
    } else if (numChildren < 1) {
        return NULL; 
    } else {
        bool found = false;
        Node* result;
        for (int i = 0; i < numChildren; i++) {
            if (!found) {
                result = this->children[i]->search(name);
                if (result) {
                    found = true;
                }
            }
        }
        return result;
    }
}

int Node::getSize() {
    int size = 1;
    for (int i = 0; i < this->children.size(); i++) {
        size += this->children[i]->getSize();
    }
    return size;
}

vector<Node*> Node::getChildren() {
    return this->children;
}

string Node::getName() {
    return this->name;
}

void Node::setWeight(int weight) {
    this->weight = weight;
}

void Node::print(string offset) {
    cout << offset << this->name;
    cout << " ";
    cout << this->weightToStr();
    //cout << this->dependenciesToStr();
    cout << endl;
    for (int i = 0; i < this->children.size(); i++) {
        this->children[i]->print(offset + "    ");
    }
}

string Node::weightToStr() {
    string result = "";
    result += "(";
    result += to_string(this->weight);
    result += ")";
    return result;
}

string Node::dependenciesToStr() {
    string result = "";
    int numChildren = this->children.size();
    if (numChildren > 0) {
        result += " -> ";
    }
    for (int i = 0; i < numChildren; i++) {
        result += this->children[i]->name;

        if (i < numChildren - 1) {
            result += ", ";
        }
    }
    return result;
}

void addChild(string name, vector<Node*> &children, vector<Node*> &trees) {
    bool found = false;
    for (int i = 0; i < trees.size(); i++) {
        if (trees[i]->getName() == name) {
            children.push_back(trees[i]); 
            trees.erase(trees.begin() + i);
            found = true;
        }
    }
    if (!found) {
        children.push_back(new Node(name)); 
    }
}

void printStatus(
    string name,
    int weight,
    vector<Node*> &children,
    vector<Node*> &trees
) {
    Node node(name, weight, children);
    cout << name << ": ";
    node.print();
    cout << "CURRENT STATE OF TREE WITH " << name << " BEING ADDED" << endl;
    for (int i = 0; i < trees.size(); i++) {
        trees[i]->print();
    }
    cout << "END CURRENT STATE OF TREE" << endl << endl;
}
