//Lab 4 lecture notes
//use .compare from string lib to determine if palindrome
//get length of a string using .length
#include<iostream>
#include<string>
using namespace std;

bool check_Palindrome();
int *tokenize_IP(string address);


int main(){
    cout<<"=====Question 1=====" << endl;
    check_Palindrome();
    cout<<"===End Question 1===" << endl;
    cout<<endl<<endl;
    cout<<"=====Question 2=====" << endl;
    string ip;
    cout<<"Enter IP address to tokenize" << endl;
    getline(cin,ip);
    int *ip_address = tokenize_IP(ip);
    //ip is tokenized removing all the decimal '.'
    
    cout<< "tokenized IP address: {";
    //loop for each iteration data returning a token for each i
    for (int i = 0; i < 4; ++i) {
        cout << ip_address[i] << " ";
    }
    cout << '}' <<endl;

    delete ip_address; //free up allocated memory
    cout<<"===End Question 2===" <<endl;

    return 0;
}

bool check_Palindrome(){
        string str;
        cout<<"Enter String to Check if Palindrome"<<endl;
        getline(cin,str);
        if(str.empty() == 1){
            cout<<"String is empty Re-enter string"<<endl;
            getline(cin,str);
        }
        string temp,rev;
        int len, i;
        len = str.length();
        //standard loop to get rid of spaces
        for( i = 0 ; i < len ; i++)
        {
                if(str[i] !=' ')//accounting for sentence strings with spaces
                {
                        temp += str[i];//temp stores entered STR without spaces
                        //makes temp usable for .compare
                }
        }
        //loop to reverse the string stored in temp 
        for(i = temp.length()-1 ; i >= 0; i--)
            {
                rev = rev + temp[i];
            }
        
        cout<<"Entered String is: " << str <<endl;
        //comparing if temp string without any spaces is the same as str reversed which would make it a palindrome
        if(temp.compare(rev) == 0)
        {
            cout<<"Case 1: "<<endl;
            cout << "Original String: " << str << endl;
            cout << "Manipulated string without spaces: " << temp << endl;
            cout << "Strings are Palindrome";
            cout<<endl;
            return true;    
        }       
        else
        {   
            cout << "Case 2: \n String is not palindrome" <<endl;
            cout << "Original string is: " << str << endl;
            cout << "String Reversed is: " << rev << endl;
            
            return false;
        }
    
}
int *tokenize_IP(string address) {
    int *data = new int[4]; //alocate 4 elements in the array of tokens 
    int value = 0,index = 0;
    int len = address.length();

    for (int i = 0; i < len; ++i) {
        //if token
        if (address[i] != '.') {
            value *= 10;
            value += address[i]-'0';
        }else {
            //for every string ending in '.' token is taken 
            data[index++] = value;
            value = 0;
        }
    }
    data[index] = value;
    return data;
}