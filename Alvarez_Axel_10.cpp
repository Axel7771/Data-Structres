#include <iostream>
#include <list>

using namespace std;


class graph
{
private:
    /* data */
    int data; //Number of Vertices
    list<int>* adj_list; //Adjacent list
    bool* vst_vertice; 


public:
    //constructors
    graph(int data);
    void addEdge(int src, int targ);
    void BFS(int initial_state);
};

graph::graph(int vertices)
{
    data = vertices;
    adj_list = new list<int> [vertices];

}


void graph::addEdge(int src, int targ){

    adj_list[src].push_back(targ);
    adj_list[targ].push_back(src);


}

void graph::BFS(int initial_state){

    vst_vertice = new bool[data];
    for(int i = 0; i < data ; i++ )
        vst_vertice[i] = false;
    list<int> queue;

    vst_vertice[initial_state] = true;
    queue.push_back(initial_state);
    //creating list iterorator it
    list<int>::iterator it;

    while(!queue.empty()){
        int curr = queue.front();
        cout << "Visited Vertex: " << curr << " ";
        queue.pop_front();
        cout<<endl;

        for(it = adj_list[curr].begin(); it != adj_list[curr].end(); ++it){
            int adjv = *it;
            if(!vst_vertice[adjv]){
                vst_vertice[adjv] = true;
                queue.push_back(adjv);
            }
        }
    }

    
}

int main()
{
    int root = 2;
    int n_ver = 4;


    graph graph(n_ver);
    
    //create graph
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    //BFS
    graph.BFS(root);

    //list
    /*
            
        0 : 1 2
        1 : 2
        2 : 3 
        

    */





    return 0;

}
