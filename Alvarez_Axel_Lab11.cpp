/* Axel Alvarez Lab 11 
Purpose: Implement merge sort 
in this case I will be using std::vector instead of an array*/


#include <iostream>
#include <vector>

using namespace std;

//pre functions
//utility function to merge vectors 
void merge(vector<int>& vec, int begin, int mid, int end);
//merge sort recursively
void merge_sort(vector<int>& vec, int begin, int end);

int main()
{
    //Our Vector to sort 
    vector<int> vec = {10,8,2,11,19};
    int size = vec.size() -  1;
    int start = 0;
    vector<int>::iterator it;

    cout<< "Unsorted Vector : ";
  
    for(it = vec.begin(); it != vec.end(); ++it){
        cout<< *it << " ";
    }
    cout<<endl;
    
    //call merge sort to sort vector vec
    merge_sort(vec, start, size);

    cout<< "Merge Sorted Vector: ";
    
    for(it = vec.begin(); it != vec.end(); ++it){
       
        cout<< *it  << " ";
    }
    cout<<endl;

    return 0;

}

void merge(vector<int>& vec, int begin, int mid, int end){
    //temporary vector to store split vectors
    vector<int> temp_vec;

    int it, ij;
    //pointers to begining of the vector and end of the vector
    it = begin;
    ij = mid + 1;//accounts for a odd numbered vector

    while(it <= mid && ij <= end){

        if(vec[it] <= vec[ij]){
            temp_vec.push_back(vec[it]);
            ++it;
        }
        else {
            temp_vec.push_back(vec[ij]);
            ++ij;
        }
    }

    while (it <= mid)
    {
        temp_vec.push_back(vec[it]);
        ++it;
    }
    while (ij <= end) {
        temp_vec.push_back(vec[ij]);
        ++ij;
    }

   
    for(int i = begin; i <= end; ++i){
        vec[i] = temp_vec[i - begin];
    }
}

void merge_sort(vector<int>& vec, int begin, int end){
    if (begin < end){
        int mid = (begin + end) / 2;
        merge_sort(vec, begin, mid);
        merge_sort(vec, mid + 1, end);
        merge(vec, begin, mid, end);
    }
}