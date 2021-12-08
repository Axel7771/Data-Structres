#include <iostream>


using namespace std;

const int SIZE = 20;

class student{
    private:
        int admno;
        string stuname[SIZE];
        float eng;
        float math;
        float science;
        float total;

        float ctotal(){
           
            eng  = 99.9;
            math = 89.2;
            science = 70.1;
            total = eng + math + science;
            return total;
        }
    public:
        void takestudentdata(){
            ctotal();
            admno = 55;
            stuname[0] = {"Axel Alvarez"};

        }
        void outputstudentdata(){
            cout << "Admno is: " << admno << endl;
            cout << "Name is: " << stuname[0] << endl;
            cout << "Grade total is: " << total << endl;
        }
};

class book{
    private:
        int booknum;
        string booktitle[SIZE];
        float price;

        float total_price(int n){
            float result;
            result = price * n;
            return result;
        }

    public:

        void INPUT(){
            booknum = 1;
            booktitle[0] = "Data Structures 101";
            price = 100.50;
        }

        void PURCHASE(){
            int n;
            cout << "Enter Number of Copies" << endl;
            cin >> n;
            cout << "Book Number is: " << booknum << endl;
            cout << "Price per Copy is: " << price << endl;
            cout << "Total price is: " << total_price(n) << endl;
            cout << "Book purchased is: " << booktitle[0] << endl;
            

        }
};

class Distance{
    private:
        int feet;
        float inches;


    public:

        void set(int x, float y){
            this->feet = x;
            this->inches = y;
            
            
        }

        void display(){
            cout << "Distance is: " << this->feet << "Ft and " << this->inches << "In" << endl;
        }

        Distance add(Distance obj){
            Distance obj1,obj2,obj3;
            obj1.feet = this->feet + obj.feet;
            obj1.inches = this->inches + obj.inches;
          
           
            
            return obj1;
         

        }


};

int main(){
    cout << "==Question 1==" << endl;
    student stu;
    stu.takestudentdata();
    stu.outputstudentdata();
    cout << "==Question 2==" << endl;
    book book;
    book.INPUT();
    book.PURCHASE();
    cout << "==Question 3==" << endl;
    Distance obj1,obj2,obj3;

    int x,z;
    float y,w;

    cout << "Enter distance in feet: " << endl;
    cin >> x;
    cout << "Enter distance in inches: " << endl;
    cin >> y;
    cout << "Enter distance in feet: " << endl;
    cin >> z;
    cout << "Enter distance in inches: " << endl;
    cin >> w;

    obj1.set( x , y );
    obj2.set( z, w );
    obj1.display();
    obj2.display();

    obj3 = obj1.add(obj2);
    obj3.display();

    cout << "===End of Lab 2===" <<endl;   
    return 0;
}