#include <iostream>
#include <cmath>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
    
};

void inorder(Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<< node->data<<" ";
    inorder(node->right);

}
//get tree height
int height(struct Node* node){
    int left_height = 0;
    int right_height = 0;
    if (node == NULL){
        return 0;
    }
    else
    {

        int left_height = height(node->left);
        int right_height = height(node->right);

        if(left_height > right_height)
        {
            return(left_height + 1);
        }
        else return(right_height + 1);
    }

}

int check_balanced(Node* node){

    int left_height;
    int right_height;

    if (node == NULL){
        return 1;
    }

    left_height = height(node->left);
    right_height = height(node->right);
    //using Absolute value function abs() imported from cmath
    int heightdiff = abs(left_height - right_height);
    //check if the height difference is balanced 
    if(heightdiff <= 1 && check_balanced(node->left) && check_balanced(node->right))
    {
        return 1;
    }
    //Otherwise return 0 if tree isnt balanced
    return 0;
}
//Utility Functions for check_BST
bool ut_checklesser(Node* node, int value){
    if(node == NULL){
        return true;
    }
    //check if left leaf is less than root node
    if(node->data <= value && ut_checklesser(node->left, value) && ut_checklesser(node->right, value)){
        return true;
    }
    else{
        return false;
    }

}
bool ut_checkgreater(Node* node, int value){
    if(node == NULL){
        return true;
    }
    //check if right leaf is greater than root node
    if(node->data > value && ut_checkgreater(node->left,value) && ut_checkgreater(node->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }

}
//check if a tree is a binary search tree
bool check_BST(Node* node){
    if(ut_checklesser(node->left, node->data) && ut_checkgreater(node->right, node->data) && check_BST(node->left) && check_BST(node->right)){
        return true;
    }
    else{
        return false;
    }

}
//Driver Program
int main()
{
    
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    /*Comment: Program crashes when BST is true not sure whats wrong but it will
    correctly check if tree is not a BST*/
   
    cout<< "-----=== Lab 8 ===-----"<<endl;

    cout<< "Given Inorder tree: "<<endl;
    inorder(root);
    cout<<endl;
    cout<< "Height of Tree is: " <<endl;
    cout<< height(root);
    cout<<endl;
    if(check_balanced(root) == 0){
        cout<<" >> Tree is not Balanced"<<endl;
        
    }
    else{
        cout<<" >> Tree is balanced:"<<endl;
    }

    if(check_BST(root) == 0){
        cout<< " >> Tree is not a BST"<<endl;

    }
    else{
        cout<< " >> Tree is a BST" <<endl;
    }

    return 0;
}

