#include <iostream>
#include <vector>
/* Axel Alvarez Lab 12
Purpose: Use bubble sorting algorithm to 
sort a vector (array) of integer elements

Note: I implemented it with a vector after already 
doing it in C (last spring) with an array. I did this because
I wanted to use the new tools I learned for the final 
data structures lab
*/


using namespace std;


//utility function for bubble sort
void swap(int *x, int *y);
void bubblesort(vector<int>& arr);

int main()
{
    
    //call our vector and the iterator
    vector<int> v{65,22,28,33,21,55,43};
    vector<int>::iterator it;
    
    bubblesort(v);
    
    cout<< "Sorted Array: ";
    for(it = v.begin(); it != v.end(); ++it){

        cout<< *it << " ";

    }
    cout<<endl;


    return 0;

}
//swap elements by assigning a temp variable to hold our sorted elements
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}

void bubblesort(vector<int>& arr){
    int i, j;
    //iterate through the vector
    for(i = 0; i < arr.size(); i++){

        //Iterator vector through j
        for(j = 0; j < arr.size() - 1 ; j++)
        {
            
            //Comparing if neighbor is smaller
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                
            }
                
        }
    }
}


