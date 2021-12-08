
#include <iostream>
#include <queue>

using namespace std;

class stock_var{

        int price;
        int shares;
};


int main(){
    int price;
    int shares;
    int cost;
    int sell_cost;

    string buyorsell;
    cout << "Enter b or s for Buy stock or Sell Stock\n E for exit\n" << endl;
    while(getline(cin,buyorsell)){

    queue <int> q;
    
    if(buyorsell[0]=='b')
    {
    cout << "Enter shares and price\n";
    cin >> shares;
    cin >> price;
    q.push(shares);

    while(!q.empty()){
    cout << "You bought " << q.front() << " Shares ";
    q.pop();
    cout << "At $" << price << " Dollars" << endl;

    }

    cost = shares * price;
    cout << "Cost is: $" << cost;
    }
    if(buyorsell[0]=='s'){
    
    cout << "Enter shares and price\n";
    cin >> shares;
    cin >> price;
    q.push(shares);

    while(!q.empty()){
    cout << "You Sold " << q.front() << " Shares ";
    q.pop();
    cout << "At $" << price << " Dollars" << endl;

    }
    sell_cost = shares * price;
    

    
    }
    
    
    if(buyorsell[0]=='E'){
        return 0;
    }

    }
    int profit = cost - sell_cost;
    cout << "profit is: " << profit;

    return 0;
}