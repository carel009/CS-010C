#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
  public:
    Node(string);
    void setLeft(Node*);
    void setRight(Node*);
    void setHeight(int);
    string getData();
    Node* getLeft();
    Node* getRight();
    int getHeight();
  
  private:
    string data;
    Node* left;
    Node* right;
    int height;
};
#endif