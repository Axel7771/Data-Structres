#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Node{
    public:
    char data;
    Node *left, *right;
  
Node(int data){
    this->data = data;
    this->left = this->right = nullptr;
  }

Node(int data, Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
  }

};


void value_result(char);
// Function to check if a given token is an operator
bool isOperator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void postorder(Node* root){
  
    if (root == nullptr) //checks if root points null
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}
//print post tree

void inorder(Node* root){
    if (root == nullptr)
    {
        return;
    }

    if (isOperator(root->data))
    {
        cout << "(";
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);

    if (isOperator(root->data))
    {
        cout << ")";
    }

}

Node* construct(string postfix) // Create Binary Tree
{
    stack<Node*> tree; //stack pointer

  
    for (char c : postfix)
    {
        if (isOperator(c)){
            
      
            Node* left_child = tree.top(); //Child Node
            tree.pop();
            Node* right_child = tree.top(); //Child Node
            tree.pop();
            Node* node = new Node(c, left_child, right_child); //Creating the Root and Child Nodes
            tree.push(node);
        }

    else
        {
            tree.push(new Node(c));//Checks if Binary Tree has a root
        }
    }

  return tree.top(); //Return to Root Node
}


int a_precedence(char c) {
    /*if (c == '(' || c == ')')
        return 5;*/
    switch(c)
    {
        case '^':
        return 4;
        case '/':
        case '*':
        return 3;
        case '+':
        case '-':
        return 2;
        default:
        return 1;

    }   
}


string convert_postfix(string s){

    stack<char> stack; 
    string result;
    int i;

    for (i = 0; i < s.length(); i++) {
        char c = s[i];

        if(c >= 'a' && c <= 'z'){
            cout<< "Error Instance of letter variable in expression"<<endl;
        }

        if((c >= '0' && c <= '9')){
            result += c;
        }
        //Logic for closed and open paranthesis in the expression
        else if(c == '('){
            stack.push('(');
        }

        else if (c == ')') {
            while(stack.top() != '(')
            {
                result += stack.top();
                stack.pop();
            }
        stack.pop();
        }

    else{
        while(!stack.empty() && a_precedence(s[i]) <= a_precedence(stack.top())){
                result += stack.top();
                stack.pop();
            }
        stack.push(c);
        }
    }

    while(!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }

    return result;
}

//Converts Expression to infix and postfix

int main()
{
  
    string arith_exp;
    cout<< "Enter Expression >>> (a+((b+c)*d)) CASE SENSITIVE"<<endl;
    getline(cin, arith_exp);
    

    Node* root = construct(convert_postfix(arith_exp));

    
    cout << "Infix Expression >> ";
    inorder(root);
    
    cout<<endl<<endl;
    
    cout << "Postfix Expression << ";
    postorder(root);
    
    cout<<endl;
    cout<< "Result is: " <<endl;
    //result_value();

    
    
    return 0;
}


