/* Axel Alvarez Lab 9 */
/* Purpose: Get the Max width of a tree using height and width functions recursively */

#include <iostream>

using namespace std;


class Node{
    public:
    int data;

    Node *left, *right;

    Node(int data){
        this->data;
        left = right = NULL;

    }

};
//Utility function to get the height of the Binary tree
int height(Node* node){

    int lefth, righth = 0;

    if(node == NULL){
        return 0;
    }
    else
    {
        lefth = height(node->left);
        righth = height(node->right);

        if(lefth > righth){
            return (lefth + 1);
        }
        else return(righth + 1);
    }

}
//Utility function to get the width of all levels of the Binary Tree
int getwidth(Node* node, int data){

    if (node == NULL){
        return 0;
    }
    if(data  ==  1){
        return 1;
    }
    else if(data > 1){
        
        return getwidth(node->left, data - 1) + getwidth(node->right, data - 1);

    }

    return 0;
}

int getmax(Node* node){

    int width_max = 0;
    int tree_h = height(node);

    for(int i = 0; i < tree_h; i++){
        int width = getwidth(node, i);
        if(width > width_max){
            width_max = width;
        }

    }
    return width_max;
}

int main(){

    Node* root;
    
    //construct tree
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
   
    
    cout<< "Maximum width is: "<<endl;
    cout<< getmax(root) <<endl;
    cout<< "===End of Lab 9===" <<endl;

    
}






