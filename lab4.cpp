//use rbegin and rend to check if a string is a palindrome or not
//use .compare to check the difference between 2 strings
//empty to check if a string or array is empty or not

#include <iostream>
#include <string>

using namespace std;
//function returning IPV4 decimal ip addresses and returning the tokens

int *tokenize(string address) {
    int *data = new int[4];
    int value = 0,index = 0;
    int len = address.length();

    for (int i = 0; i < len; ++i) {
        if (address[i] != '.') {
            value *= 10;
            value += address[i]-'0';
        } else {
            data[index++] = value;
            value = 0;
        }
    }
    data[index] = value;
    return data;
}

int main(){
    string ip;
    getline(cin,ip);

    int *ip_address = tokenize(ip);
    cout<< "{";
    for (int i = 0; i < 4; ++i) {
        cout << ip_address[i] << " ";
       
    }
    cout << '}';

    delete ip_address;

    return 0;
}
