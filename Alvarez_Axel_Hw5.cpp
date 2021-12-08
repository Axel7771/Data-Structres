/*Axel Alvarez HW 5*/
//Purpose: Create an adjacency list graph and deploy BFS DFS

#include <iostream>
#include <list>



using namespace std;


class graph
{
private:

    char data; //Number of Vertices
    list<char>* adj_list; //Adjacent list
    bool* visited;// true or false for visited vertice 

public:
    //constructors
    //graph(int data);
    void addEdge(char src, char targ);
    void BFS(char initial_state);
};

/*graph::graph(int vertices)
{
    data = vertices;
    adj_list = new list<char> [vertices];

}*/


void graph::addEdge(char src, char targ){

    adj_list[src].push_back(targ);
    adj_list[targ].push_back(src);


}

void graph::BFS(char initial_state){

    list<char> q;
    visited = new bool[data];
    q.push_front(initial_state);
    visited[initial_state] = true;

    while(!q.empty()){
        char curr = q.front();
        cout<< "Visited Vertice: " << curr;
        q.pop_front();
        cout<<endl;

        for(char adjv: adj_list[curr]){
            if(!visited[adjv]){
                q.push_front(adjv);
                visited[adjv] = true;
            }
        }

    }

}

int main()
{
    
    graph graph;
    
    //create graph
    /*graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,3);*/
    //create graph
    
    graph.addEdge('a','b');
    graph.addEdge('a','c');
    graph.addEdge('a','d');
    graph.addEdge('b','e');
    graph.addEdge('c','b');
    graph.addEdge('c','g');
    



    //BFS
    graph.BFS('a');

    //list
    /*
            
        0 : 1 2
        1 : 2
        2 : 3 
        

    */





    return 0;

}
