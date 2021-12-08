#include <iostream>
#include <queue>

//create a binary tree
//traverse using postorder()
//mirror the binary tree using swap() 


using namespace std;
//Class Node
class Node{
  public:
  int data;
  Node* left;
  Node* right;
};


Node* createnode(int n){
    Node* newNode = new Node();
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout << node->data<<" ";
    inorder(node->right);
}

void postorder(Node* node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data<<" ";

}

void mirror(Node* root){
    if(root == NULL){
      return;
    }
    
    queue<Node*> q;
    q.push(root);

    //Breadth First search
    while(!q.empty())
    {
      Node* sp = q.front();
      q.pop();

      swap(sp->left, sp->right);

      if (sp->left)
        q.push(sp->left);
      if (sp->right)
        q.push(sp->right);
      
    }

}

int main(){
    
    //Creating the Binary Tree
    Node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    /*root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->left->left->left = createnode(6);
    root->left->left->right = createnode(7);*/

    
  
    int choice;

    while(choice != 3)
    {
      cout<<"-------Lab 7-------"<<endl;
      cout<<"Post-Order Mirror(1)\nIn-Order Mirror(2)"<<endl;
      cout<<"Exit(3)"<<endl;
      cin >> choice;
      switch(choice)
      {
        case 1:
            cout << "\nMirror of Binary Tree Post-Order >> ";
            postorder(root);
            mirror(root);
            cout<<"\nPost-Order Binary Tree << ";
            postorder(root); 
            cout<<endl;
            break;
        case 2:
            cout << "\nMirror of Binary Tree In-Order >> ";
            inorder(root);
            mirror(root);
            cout<<"\nBinary Tree In-Order << ";
            inorder(root);
            cout<<endl;
            break;
        default:
            break;
      }
    }


    return 0;
}