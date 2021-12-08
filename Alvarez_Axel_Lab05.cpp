#include <iostream>
#include <queue>
using namespace std;
  
int main()
{   
    // Empty Queue
    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    // queue becomes 0, 1, 2
  
    q.pop();
    q.pop();
    // queue becomes 2
  
    // Printing content of queue
    while (!q.empty()) {
        cout << ' ' << q.front();
        q.pop();
    }

    return 0;
}