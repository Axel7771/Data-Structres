#include <iostream>
#include <array>
#include <vector>

using namespace std;

int lab_q1(){
    array<int, 10> array1 = {7,2,3,4,5,6,7,8,9,10};

    array<int, 10> array2;

    array2.fill(5);

    cout << "First element of 1st the array: " << array1.front() << endl;

    cout << "Last element of 1st the array: " << array1.back() << endl;
    
    cout << "First element of the 2nd array: " << array2.front() << endl;
    
    cout << "Last element of the 2nd array: " << array2.back() << endl;
    
    cout << "Size of the 1st array: " << array1.size() << " Elements" << endl;

    cout << "Size of the 2nd array: " << array2.size() << " Elements" << endl;

    cout << "swapping arrays: " << endl;

    array1.swap(array2);
    cout << "First element of the 1st array after swap: " << array1.front() << endl;

    cout << "Last element of the 1st array after swap: " << array1.back() << endl;

    return 0;
}

int main(){

    lab_q1();
    cout << "Lab question 2: " <<endl;
    int size;
    cin >> size;
    vector<int> vector1;
    vector<int> vector2;

    cout << "Size of V1: " << vector1.size(size);

    return 0;
}