#include "Node.h"

Node::Node(string d)
{
    data = d;
    left = NULL;
    right = NULL;
    height = 1;
}

void Node::setLeft(Node* l)
{
    left = l;
}

void Node::setRight(Node* r)
{
    right = r;
}

void Node::setHeight(int h)
{
    height = h;
}

string Node::getData()
{
    return data;
}

Node* Node::getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

int Node::getHeight()
{
    return height;
}