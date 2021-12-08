#include <iostream>
#include <vector>
#define MAX 10

/* HW #6 Axel Alvarez */


using namespace std;

/*
Using Object Oriented approach I create a class sort to retain all the utitiliy
function and sorting algorithms within an object to manipulate an array with sorting
algorithms
*/
typedef struct Queue *qptr;
class Queue 
{
    public: 
        int data;
        qptr next;

};
qptr top[MAX], bottom[MAX];

class sort{

    public:
    //Queue
        void enqueue(int i, int data)
    {
        qptr temp = (qptr)malloc(sizeof(*temp));
        temp->next = NULL;
        temp->data = data;
        if (top[i])
            bottom[i]->next = temp;
        else
            top[i] = temp;
        bottom[i] = temp;
    }

    int dequeue(int i)
    {
        int data;
        qptr temp;
        temp = top[i];
       
        if (!temp)
            return -1;
        data = temp->data;
        top[i] = temp->next;
        delete temp;
        return data;
    }

    //utility functions
    void input_data(vector<int> &arr)
    {
        int input;
        char space;
        while (1)
        {
            scanf("%d%c", &input, &space);
            //Dynamically allocates an array on user input
            arr.push_back(input);
            if (space == '\n')
                break;
        }
        cout <<endl;
    }
    void printArray(vector<int> &arr)
    {
        vector<int>::iterator it;
        for(it =  arr.begin(); it != arr.end(); ++it ){
            cout << *it << " ";
        }
        cout << endl;
    }


    void swap(int *x, int *y)
    {
    int temp = *x;
    *x = *y;
    *y = temp;
    
    }
    int split(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
    
        for(int j = low; j <= high - 1; j++)
        {
            if(arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }

        }
        swap(&arr[i+1], &arr[high]);
        return(i + 1);

    }
    //Sorting Algorithms

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
                    swap(&arr[j], &arr[j+1]);
                
                }
                
            }
        }
    }

    void insertionSort(vector<int> &arr)
    {
        int temp, i, j;

        for (i = 1; i < arr.size(); i++)
        {
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j+1] = arr[j];
                j = j - 1;
            }
            arr[j+1] = temp;
        }

    }

    void selectionSort(vector<int> &arr)
    {
        int i, j, min;

        for (i = 0; i < arr.size(); i++ )
        {
            min = i;
            for(j = i + 1; j < arr.size(); j++)
            if(arr[j] < arr[min])
                min = j;
            
            swap(&arr[min], &arr[i]);
        }
    }

    void quickSort(vector<int> &arr, int low, int high)
    {
        if( low < high)
        {
            int index = split(arr, low, high);
            quickSort(arr, low, index - 1);
            quickSort(arr, index + 1, high);

        }
    }

    void radix_sort(vector<int> &arr)
    {
        int i, j, k, radix, digits, temp;
        int maxdata = arr[0];
        vector<int>::iterator it;

       
        if (arr.size() < 1)
            return;

        for (it = arr.begin(); it != arr.end(); ++it)
            maxdata = maxdata < *it ? *it : maxdata;

     
        for (radix = 1, digits = 0; maxdata >= radix; digits++, radix *= 10);

        for (i = 0, radix = 1; i < digits; i++, radix *= MAX)
        {
            for (j = 0; j < arr.size(); j++)
                enqueue((arr[j] / radix) % MAX, arr[j]);

     
            for (j = 0, k = 0; j < 10; j++)
                for (temp = dequeue(j); temp != -1; temp = dequeue(j), k++)
                    arr[k] = temp;
        }
    }
    
};


int main(){
    int choice, size;
    vector<int> arr1;
    sort s;

    
    while(choice != 6)
    {
        cout << "-----=====Menu=====-----\n";
        cout << "Input Data (0) Insertion Sort (1) Selection Sort(2)\n";
        cout << "Bubble Sort (3) Quick Sort (4) Radix Sort (5)\n";
        cout << "Exit (6)\n";

        cout << "\t\t\t Choose: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 0:
                arr1.clear();
                cout << "Creating array: ";
                s.input_data(arr1);
                s.printArray(arr1);
           
                break;
            case 1:
                cout << "Insertion Sort: ";
                s.insertionSort(arr1);
                s.printArray(arr1);
                break;
            case 2:
                cout << "Selection Sort: ";
                s.selectionSort(arr1);
                s.printArray(arr1);
                break;
            case 3:
                cout << "Bubble sort: " << endl;
                s.bubblesort(arr1);
                s.printArray(arr1);
                break;
            case 4:
                cout << "Quick sort: " << endl;
                s.quickSort(arr1, 0, arr1.size() + 1);
                s.printArray(arr1);

                break;
            case 5:
                cout << "Radix sort: " << endl;
                s.radix_sort(arr1);
                s.printArray(arr1);
                break;
            case 6:
                break;
        }

    }
    return 0;

}