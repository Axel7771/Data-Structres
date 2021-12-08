#include <iostream>

using namespace std;

int data;

void Dec_to_Bin(int data);
void binaryconv(){
    int n;
    int i;
    int decimal;
    int bin_num[32];
    while(n > 0){
        bin_num[i] = n;
        n = n % 2;
        i++
    }
    cout<<"Binary form of "<< n <<" is ";
    for (int j = i - 1; j >= 0; j--){
        cout << bin_num[j];
        cout<<endl;
    }
}

int menu( );



int main(){
    
    /*menu();
    cout<<"Enter decimal (base10) Number"<<endl;
    int data;
    cin >> data;
    Dec_to_Bin(data);*/

    binaryconv();
    return 0;
}
void Dec_to_Bin(int data){
    int result;
    if(data == 1){
        int result = 1;

        cout<<re";
    }
    else{
        Dec_to_Bin(data/2);
        result = data % 2;
        cout<<result<<endl;
    }

}
int menu(){
    int choice;
  
    while (choice != 15){
        cout<<"==Menu=="<<endl;
        cout<<"Binary(0)   Octal(1)   Hexadecimal(2)"<<endl;
        cout<<endl<<endl;
        cout<<"Exit(15)"<<endl;
        cin >> choice;

        switch(choice)
        {
            case 0:
                cout << "Decimal to Binary Converter" << endl;
                cout<<"Enter decimal (base10) Number"<<endl;
                int data;
                cin >> data;
                Dec_to_Bin(data);
                break;
            case 1:
                break;
        }
    }
    return 0;
}