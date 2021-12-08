#include <iostream>
#include <list>

using namespace std;



int main()
{   
    list<int>numto;
    list<int>o_numto;
    list<int>::const_iterator it;
    int data;
    int choice;
    int octalnum[50], i = 0;

    while(choice != 3)
    {
        
        cout <<"===Menu==="<<endl;
        cout <<"Binary (0) Octal(1)";
        cout <<endl<<endl;
        cout <<"Exit(3)"<<endl;
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Enter a Decimal Value to Convert to Binary:  ";
                cin>>data;
                for(int traverse = data ; traverse ; traverse >>=1)

                
        
                numto.push_front(traverse % 2);
                
                

                cout<< "Using std::List Binary number is: ";

                for(it=numto.begin() ; it!=numto.end(); ++it)
                cout<<*it;
                cout<<endl;

                break;
            case 1:

                cout<<"Enter a Decimal Value to Convert to Octal: ";
                cin>>data;   
                while(data != 0)
                {

                    o_numto.push_front(data % 8);
                    octalnum[i] = data % 8;
                    i++;
                    data = data/8;
                    o_numto.push_front(data/8);
            
                    /*o_numto.push_front(octalnum[i]);*/
                    
                }
                cout << "Using std::List Octal value is: ";
                for(it=o_numto.begin() ; it!=o_numto.end(); ++it)
           
                cout<<*it;
                cout<<endl;
           
                for(i=(i-1); i>=0; i--)
    
                    cout<<octalnum[i];
                    
                cout<<endl;
                break;
                
        }

        
    }
  
    return 0;
}