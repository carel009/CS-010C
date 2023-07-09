#include "arithmeticExpression.h"
#include <fstream>
#include <sstream>
#include <stack>

arithmeticExpression::arithmeticExpression(const string& arithExp): infixExpression(arithExp), root(0) {}

void arithmeticExpression::buildTree()
{
    char key = 'a';
    char ch;
    stack <TreeNode*> st;
    string postfixArithExp = infix_to_postfix();
    
    for (unsigned int i = 0; i < postfixArithExp.size(); ++i)
    {
        ch = postfixArithExp.at(i);
        
        if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            TreeNode* newNode = new TreeNode(ch, key+i);
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
            st.push(newNode);
        }
        
        else
        {
            st.push(new TreeNode(ch, key+i));
        }
    }
    root = st.top();
    st.pop();
}

void arithmeticExpression::infix()
{
  if (root == 0)
  {
      return;
  }
  
  else
  {
      infix(root);
  }
}

void arithmeticExpression::prefix()
{
  if (root == 0)
  {
      return;
  }
  
  else
  {
      prefix(root);
  }
}

void arithmeticExpression::postfix()
{
  if (root == 0)
  {
      return;
  }
  
  else
  {
      postfix(root);
  }
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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

int arithmeticExpression::evaluate()
{
    if (!isValidIntegerExpression(root))
    {
        throw invalid_argument("expression not valid");
    }
    
    else
    {
        return evaluateIntegerExpression(root);
    }
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode* node)
{
    if (node)
    {
        if (node->left != 0 || node->right != 0)
        {
            cout << "(";
        }
        
        infix(node->left);
        cout << node->data;
        infix(node->right);
        
        if (node->left != 0 || node->right != 0)
        {
            cout << ")";
        }
    }
    
    else
    {
        return;
    }
}

void arithmeticExpression::prefix(TreeNode* node)
{
    if (node)
    {
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
    }
    
    else
    {
        return;
    }
}

bool arithmeticExpression::isValidIntegerExpression(TreeNode* node)
{
    if (node)
    {
        if (node->data >= '0' && node->data <= '9')
        {
            return true;
        }
        
        if (node->data == '*' || node->data == '/' || node->data == '+' || node->data == '-')
        {
            bool left = isValidIntegerExpression(node->left);
            bool right = isValidIntegerExpression(node->right);
            
            if (left && right)
            {
                return true;
            }
            
            else
            {
                return false;
            }
        }
        
        else
        {
            return false;
        }
    }
    
    else
    {
        return false;
    }
}

int arithmeticExpression::evaluateIntegerExpression(TreeNode* node)
{
    if (node->data >= '0' && node->data <= '9')
    {
        int value = (node->data - '0');
        return value;
    }
        
    int leftVal = evaluateIntegerExpression(node->left);
    int rightVal = evaluateIntegerExpression(node->right);
        
    if (node->data == '*')
    {
        return (leftVal * rightVal);
    }
        
    if (node->data == '/')
    {
        return (leftVal / rightVal);
    }
        
    if (node->data == '+')
    {
        return (leftVal + rightVal);
    }
        
    if (node->data == '-')
    {
        return (leftVal - rightVal);
    }
    
    return 0;
}

void arithmeticExpression::postfix(TreeNode* node)
{
    if (node)
    {
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
    }
    
    else
    {
        return;
    }
}

void arithmeticExpression::visualizeTree(ofstream& outFS, TreeNode* node){}