/* Homework #4 Alvarez_Axel */

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    
    Node *left;
    Node *right;
    //constructor
    Node(int data){

        this->data = data;
        left = right = NULL;
    }
};
//Traversals
void inorder(Node* node){

    if(node == NULL){
        return;
    }

    inorder(node->left);
    inorder(node->right);
    cout<< node->data << " ";

}

void postorder(Node* node){
    
    if(node == NULL){
        return;
    }

    postorder(node->left);
    cout<< node->data << " ";
    postorder(node->right);
}

void preorder(Node* node){
    if(node == NULL){
        return;
    }

    cout<< node->data << " ";
    preorder(node->left);
    preorder(node->right);

}

Node* create_tree(Node* node, int data){
    
    if (node == NULL){

        node = new Node(data);

        return node;
    }

    if(data < node->data){

        node->left = create_tree(node->left, data);
      
    }
    else if(data > node->data){
        node->right = create_tree(node->right, data);
    }

    return node;
}

void search(Node *node, int data){

    if(node == NULL){
        return;
    }
    search(node->left, data);
    if(node->data == data){
        cout << "Successful! Node does Exist";
        
        cout<<endl;
        return;
    }
    search(node->right, data);
    if(node->data == data){
        cout << "Successful! Node does Exist";
        cout<<endl;
        return;
    }
 
}
//Utility Function returns Height of Tree
int height(Node* node){
    int left_h = 0;
    int right_h = 0;
    if(node == NULL){
        return 0;
    }
    else
    {
        int left_h = height(node->left);
        int right_h = height(node->right);
        if(left_h > right_h)
        {
            return(left_h + 1);
        }
        else return(right_h + 1);
        
    }
}
//BreadthFirstTraversal Utility Function
void print_level(Node* node, int lev){
    if(lev == 1){
        cout << node->data << " ";
    
    }
    else if (lev > 1){
        print_level(node->left, lev - 1);
        print_level(node->right, lev - 1);
    }
}

void BreadthFirstTraversal(Node* node){
    int h = height(node);
    
    for (int i = 1; i <= h; i++)
    {
        print_level(node, i);
    }

}
//Delete Node Utility function to find min of a Tree
Node* min(Node* node){
    while(node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* delete_node(Node* node, int data){
    if(node == NULL){
        cout << "Error: node does not exist"<<endl;
        return node;
    }
    else if(data < node->data){
        node->left = delete_node(node->left, data);
    }
    else if(data > node->data){
        node->right = delete_node(node->right, data);

    }

    else
    {
        if(node->left == NULL && node->right == NULL){
            delete node;
            node = NULL;
        }
        else if(node->left == NULL){
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else if(node->right == NULL){
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else{
            Node* temp = min(node->right);
            node->data = temp->data;
            node->left = delete_node(node->right, temp->data);
        }
    }
    return node;
}




//Driver function
int main()
{
    int choice, data, n, target;  
    Node *root = NULL;
   
    while(choice != 7)
    {
        cout<<"-----------------======<<<< MENU >>>>======----------------"<<endl;
        cout<<"Create Tree(0) Search Tree(1) BreadthFirstTraversal(2)  " << endl;
        cout<<"Depth-First Traversal: Preorder(3) Inorder(4) Postorder(5) "<<endl;
        cout<<"Delete Node(6)"<<endl;
        cout<<endl;
        cout<< "Exit(7)"<<endl;
        cout<<"Choose >> ";
        cin >> choice;

        switch(choice)
        {
            case 0:
                //You may continue inserting nodes as long as the root does not equal NULL 
                cout << "Enter n Number of Key values: " <<endl;
                
                cin >> n;
                cout<<"Enter Root Node:"<<endl;
               
                cin >> data;
                cout<<"Create Tree (In Binary Search Tree format left < root < right):"<<endl;
                
                root = create_tree(root, data);
                for(int i = 0; i < n - 1; i++){

                    cin >> data;
                    create_tree(root, data);

                }
                break;
            case 1:
                cout<< "Enter target key value >>"<<endl;
                cin >> target;
                search(root, target);
            
             
                break;
            case 2:
                cout<<"Breadth First Traversal: " <<endl;
                BreadthFirstTraversal(root);
                cout<<endl;
                cout << "Tree Height is: ";
                cout<< height(root) << " ";
                cout<<endl;

                break;

            case 3:
                cout<<"Preorder:";
                preorder(root);
                cout<<endl;
                break;
            case 4:
                cout<< "Inorder:";
                inorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Postorder:";
                postorder(root);
                cout<<endl;
                break;
            case 6:
                cout<<" Warning! do not Delete root Node"<<endl;
                cout<< "Enter Target Node Key to be deleted:"<<endl;
                cin >> target;
                delete_node(root, target);
                if(target = data){ 
                    cout<< "target successfully deleted:"<<endl;
                }
                cout<< "Preorder: ";
                preorder(root);
                cout<<endl;
                cout<< "PostOrder: ";
                postorder(root);
                cout<<endl;
                cout << "Inorder: ";
                inorder(root);
                cout<<endl;
                break;
            default:
                return 0;
                break;
        }
    }   

    return 0;
}
