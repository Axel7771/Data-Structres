#include <iostream>
#include <numeric>


using namespace std;

char helloworld(){
  //simple hello world

  cout << "Hello Program!" << endl;

  return 0;
}

int takeaverage(){
  //function to take the average of 2 numbers
  cout << "==Take Average Function==\n";
  double x , y;
  double result;

  cout << "Enter two numbers X and Y\n";

  cin >> x ;
  cin >> y ;
  result = (x + y)/2;
  cout << "The average is: " << result << endl;

  return 0;
}


int takeseriessum(){
//function to take the sum of a series
cout << "==Take Sum of Series==\n";
int n;
cout << "Enter n Integers to loop through: \n";
cin >> n;
int sum;

for ( int i = 0; i <= n; i++){
  sum += i;
  cout << sum << endl;
}
cout << "Sum is:" << sum << endl;
return 0;
}

int nfactorial(){
  //calculate factorial of n
  cout << "==Calculate n! factorial==\n";
  cout << "Enter N\n";
  int n;
  int result = 1;
  cin >> n;

  for (int i = 1; i <= n; ++i){
    
    result *= i;
    cout << result << endl;

  }
  cout << "Factorial of n is: \n" << result << endl;
 
  return 0;
}

int sumofarray(){
  //function to take user input n and input n number of elements into array and sum the number of element inputs 
  cout << "=Take Sum of Array inputed elements=\n" << endl;
  int n = 5;
  int i = 0;
  int sum = 0;
  int myarray[n];
 
  for (i = 0; i < n; i++){
    
    cout << "Enter Element\n";
    cin >> myarray[i];
    
  }

  for (i = 0; i < n; i++){
    
    sum += myarray[i];
    
  }
    cout << "The sum of Elements is:\n";
    cout << sum << endl;

  return 0;
}

//Main Function
int main(){
  cout << "=====Welcome to Main==========\n";
  

  helloworld();
 
  takeaverage();
  
  takeseriessum();
  
  nfactorial();
  
  sumofarray();

  cout << "======End of Lab 1======" << endl;
  return 0;

}