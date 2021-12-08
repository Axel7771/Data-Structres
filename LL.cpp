#include <iostream>


using namespace std;

class Node{
    public:
        int data;
        
        
        //nextlink will be the next pointer
        Node *nextlink;
        Node *prevlink;
        //Constructor using data as parameters
        Node(int data){
            //this pointers linking data* with data and next pointer with nextlink
            this->data = data;
            
            this->nextlink = NULL;

        }
};
//Class for a Single linked list
class SLL{
    Node *head;
    public:
        SLL(){
            head = NULL;
        }
        void IH(int);
        void IT(int);
        void DH(int);
        void DT(int);
        void printSLL();
        void SD(int);
        


};
//Doubly linked list class
class DLL{
    Node *head;
    Node *tail;
    public:
        DLL(){
            head = NULL;
            tail = NULL;
        }
        void DLLIH(int);
        void DLLIT(int);
        void DLLDH(int);
        void DLLSD(int);
        void DLLDT(int);
        void DLLprintDLL();

};
//Function Calls for Both SLL and DLL
void DLL::DLLIH(int data){
    Node* newNode = new Node(data);
    Node* temp = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    temp = temp->nextlink;
    temp->nextlink = newNode;
    newNode->prevlink = temp;
}

void DLL::DLLIT(int data){

    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    if(head != NULL){

    
        Node* temp = head;
        while(temp->nextlink != NULL){
        temp = temp->nextlink;
        }
        temp->nextlink = newNode;
        newNode->prevlink = temp;
        return;
    }
}
void DLL::DLLDH(int traverse){
    Node* temp1 = head;
    int size_list = 0;
    temp1 = head;
    if(traverse == 1){
        head = head->nextlink;
        delete temp1;
        return;
    }
}
void DLL::DLLDT(int traverse){
    /*Node* temp1 = head;
    Node* temp2 = tail;
    int size_list = 0;
    temp1 = head;
    temp2 = tail;
    while(temp1 != NULL){
        temp1 = temp1->nextlink;
        temp2 = temp2->prevlink;
        size_list++;

    }
    if(traverse == sizeof(DLL)){
        tail = tail->prevlink;
        delete temp2;
        return;


    }
    if(traverse == 1){
        head = head->nextlink;
        head = tail->prevlink;
        delete temp1, temp2;
    }*/
   

  
}
void DLL::DLLprintDLL(){
    Node* temp = head;
    if (head == NULL){
        cout << "Error Empty List" << endl;
        return;
    }
    while (temp !=NULL){
        cout << "DLL(" << temp->data << "" << ") ";
        temp = temp->nextlink;
    }
    cout << endl;

}

void DLL::DLLSD(int traverse){
    Node* temp1 = head;
    Node *temp2 = NULL;
    int size_list = 0;
    if(head == NULL){
        cout << "Error Empty List" << endl;
        return;
    }
    while (temp1 != NULL){
        temp1 = temp1->nextlink;
        size_list++;
    }
    if (size_list < traverse){
        cout << "Index is not in range: " << endl;
        return;
    }
    temp1 = head;
    if(traverse == 1){
        head = head->nextlink;
        delete temp1;
        return;
    }
    while(traverse-- > 1){
        temp2 = temp1;
        temp1 = temp1->nextlink;
    }
    temp2->nextlink = temp1->nextlink;
    delete temp1;
    
}

void SLL::IH(int data){
    Node* newNode = new Node(data);
    Node* setNext(head);
    head = newNode;
    Node* temp = head;
 
}

void SLL::IT(int data){
    Node* newNode = new Node(data);
    Node* temp = head;
        if(head == NULL){
        head = newNode;
        return;
        }
    while (temp->nextlink != NULL){
        temp = temp->nextlink;
    }
    temp->nextlink = newNode;

}


void SLL::DH(int traverse){
    Node* temp1 = head;
    int size_list = 0;
    temp1 = head;
    if(traverse == 1){
        head = head->nextlink;
        delete temp1;
        return;
    }
    
}

void SLL::DT(int traverse){
    /*Node* temp1 = head;
    Node *tail = NULL;
    int size_list = 0;
    while(temp1 != NULL){
        temp1 = temp1->nextlink;
        tail 
        size_list++;
    }*/

}

void SLL::SD(int traverse){
    Node* temp1 = head;
    Node *temp2 = NULL;
    int size_list = 0;
    if(head == NULL){
        cout << "Error Empty List" << endl;
        return;
    }
    while (temp1 != NULL){
        temp1 = temp1->nextlink;
        size_list++;
    }
    if (size_list < traverse){
        cout << "Index is not in range: " << endl;
        return;
    }
    temp1 = head;
    if(traverse == 1){
        head = head->nextlink;
        delete temp1;
        return;
    }
    while(traverse-- > 1){
        temp2 = temp1;
        temp1 = temp1->nextlink;
    }

    temp2->nextlink = temp1->nextlink;

    delete temp1;
    
}

void SLL::printSLL(){
    Node* temp = head;
    if (head == NULL){
        cout << "SLL: Error Empty List" << endl;
        return;
    }

    while (temp !=NULL){
        cout << "SLL(" << temp->data << "" << ") ";
        temp = temp->nextlink;
    }
    cout << endl;
}

int menu(){
    SLL SL;
    DLL DL;
    int i;
    int data;
    int traverse;
    int choice;
 
    while (choice != 12){
        cout << "==Menu==\n Enter op: \nSLL: IH(0)  IT(1)  SD(2)  DH(3)  DT(4)  PS(5)\nDLL: IH(6)  IT(7)  SD(8)  DH(9)  DT(10) PD(11)\nExit(12)" << endl;
        cin >> choice;
    switch (choice)
    {
    case 0:

        //Int i is the position of the linked list 
        cout << "Insert Head: " << endl;
        cin >> data;
        SL.IH(data);
        cout << "SLL: ";
        SL.printSLL();
        
        break;
    
    case 1:
        cout << "Insert Tail: " << endl;
        cin >> data;
        SL.IT(data);
        SL.printSLL();
        break;

    case 2:
        cout << "Enter Node Position to delete: " << endl;
        cin >> traverse;
        SL.SD(traverse);
        SL.printSLL();
        
        break;
    case 3:
        cout << "Deleting head: " << endl;
        traverse = 1;
        SL.DH(traverse);
        SL.printSLL();

        break;
    case 4:
        cout << "Deletinig Tail: " << endl;
        SL.DT(traverse);
        SL.printSLL();
        break;
    case 5:
        cout<<"Current SLL: ";
        SL.printSLL();

    case 6:
        cout << "DLL: Enter head: " << endl;
        cin >> data;
        DL.DLLIH(data);
        DL.DLLprintDLL();
        break;
    case 7:
        cout <<"DLL: Enter Tail: " << endl;
        cin >> data;
        DL.DLLIT(data);
        DL.DLLprintDLL();
        break;
    case 8:
        cout <<"DLL: Enter Target to Delete Node: " << endl;
        cin >> traverse;
        DL.DLLSD(traverse);
        DL.DLLprintDLL();
        break;
    case 9:
        cout <<"DLL: Deleting Head" <<endl;
        traverse = 1;
        DL.DLLDH(traverse);
        DL.DLLprintDLL();
    case 10:
        cout <<"DLL: Deleting Head" <<endl;
        traverse = sizeof(DLL);
        DL.DLLDT(traverse);
        DL.DLLprintDLL();
        break;
    case 11:
        cout <<"Current DLL: ";
        DL.DLLprintDLL();
        break;
    case 12:

        SL.printSLL();
        DL.DLLprintDLL();
        
        break;
    default:
        break;
    }
  
    } 
    return 0;
}



int main(){
    SLL SL;
    DLL DL;
    int n, i;
    int data;
    int choice;
    menu();

    cout << endl;
    return 0;
}
