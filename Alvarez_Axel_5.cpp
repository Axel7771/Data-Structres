/*Alvarez Axel HW 5
Purpose: implement BFS and DFS in a graph
Notes: Used a hash map approach for my adj list and for my visited array
Included a vector and list*/

#include <iostream>
#include <list>
#include <map>
#include <vector>


using namespace std;

class Graph
{
public:
    map<char,vector<char> > adjList;
    map<char, bool> visited;
    void addEdge(char vert, char adjvert);
    void bfs(char src, char end);
    void dfs(char src, char end);
    void BFSC(char src, char end);

};

void Graph::addEdge(char vert, char adjvert)
{
    adjList[vert].push_back(adjvert);
    adjList[adjvert].push_back(vert);

}
void Graph::bfs(char src, char end)
{
    list<char> q;
    map<char, bool> visited;
    q.push_front(src);
    
    visited[src] = true;
    while(!q.empty())
    {
        char node = q.front();
        cout << "Visited Node: " << node;
        q.pop_front();
        cout << endl;
        
        for(char neighbor: adjList[node])
        {
            if(!visited[neighbor])
            {
                q.push_front(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    
}



void Graph::dfs(char src, char end){

    visited[src] = true;
    
    cout << "Visited Node: " << src << endl;
    
    vector<char>::iterator it;

    for(it = adjList[src].begin(); it != adjList[src].end(); ++it)
    {
        if(!visited[*it])
        {
            dfs(*it, end);
            
        }
      
    }
        
}
int main()
{
    int choice;
    char start, end;
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'B');
    g.addEdge('C', 'G');
    g.addEdge('D', 'C');
    g.addEdge('D', 'G');
    g.addEdge('E','C');
    g.addEdge('E','F');
    g.addEdge('F','C');
    g.addEdge('F','H');
    g.addEdge('G','F');
    g.addEdge('G','H');
    g.addEdge('G','I');
    g.addEdge('H','E');
    g.addEdge('H','I');
    g.addEdge('I','F');

    


    while(choice != 2)
    {
        cout<< "--========Menu=======--"<<endl;
        cout<< "BFS(0) DFS(1) Exit(2)"  <<endl;
        cin >> choice;

        switch(choice)
        {
            case 0:
                cout << "Enter Start and Ending Vertice: "<<endl;
                cin >> start;
                cin >> end;
                g.bfs(start, end);
                break;
            case 1:
                cout<< "Enter Start and Ending Vertice: "<<endl;
                cin >> start;
                cin >> end;
                g.dfs(start, end);
                break;
            case 2:
                
                break;

        }
    }

    return 0;
}