#include "AVLTree.h"

void AVLTree::insert(const string & data)
{
    root = insert(root, data);
}

int AVLTree::balanceFactor(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    
    int balFact = height(node->getLeft()) - height(node->getRight());
    return balFact;
}

void AVLTree::printBalanceFactors()
{
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

AVLTree::AVLTree()
{
    root = NULL;
}

Node* AVLTree::rotate(Node* node, string data, int balance)
{
    Node* errorAvoidance = NULL;
    
    if (balance > 1 && data < node->getLeft()->getData())
    {
        return rotateRight(node);
    }
    
    if (balance < -1 && data > node->getRight()->getData())
    {
        return rotateLeft(node);
    }
    
    if (balance > 1 && data > node->getLeft()->getData())
    {
        node->setLeft(rotateLeft(node->getLeft()));
        return rotateRight(node);
    }
    
    if (balance < -1 && data < node->getRight()->getData())
    {
        node->setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }
    
    return errorAvoidance;
}

Node* AVLTree::rotateLeft(Node* x)
{
    Node* y = x->getRight();
    Node* b = y->getLeft();
    y->setLeft(x);
    x->setRight(b);
    x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
    y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
    return y;
}

Node* AVLTree::rotateRight(Node* y)
{
    Node* x = y->getLeft();
    Node* b = x->getRight();
    x->setRight(y);
    y->setLeft(b);
    y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
    x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
    return x; 
}

void AVLTree::printBalanceFactors(Node* node)
{
    if (node != NULL)
    {
        printBalanceFactors(node->getLeft());
        cout << node->getData() << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->getRight());
    }
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->getLeft()){
            visualizeTree(outFS,n->getLeft());
            outFS<<n->getData() <<" -> " <<n->getLeft()->getData()<<";"<<endl;    
        }

        if(n->getRight()){
            visualizeTree(outFS,n->getRight());
            outFS<<n->getData() <<" -> " <<n->getRight()->getData()<<";"<<endl;    
        }
    }
}

Node* AVLTree::insert(Node* node, string data)
{
    if (node == NULL)
    {
        return (new Node(data));
    }
    
    if (data < node->getData())
    {
        node->setLeft(insert(node->getLeft(), data));
    }
    
    else if (data > node->getData())
    {
        node->setRight(insert(node->getRight(), data));
    }
    
    else
    {
        return node;
    }
    
    node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
    int balance = balanceFactor(node);
    
    if (balance < -1 || balance > 1)
    {
        return rotate(node, data, balance);
    }
    
    return node;
}

int AVLTree::height(Node* h)
{
   if (h == NULL)
   {
       return 0;
   }
   
   int hght = h->getHeight();
   return hght;
}

int AVLTree::max(int x, int y)
{
    int maximum;
    if (x > y)
    {
        maximum = x;
    }
    
    else
    {
        maximum = y;
    }
    
    return maximum;
}