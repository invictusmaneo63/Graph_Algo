//
// Created by Prem Kumar Tiwari on 11-12-2019.
//
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// data structure to store edges

struct Edge {
    int src, dest;
};

// an adjacency representation of graphs
class Graph {
public:
    vector<vector<int>> adjList;
    void show();
//    Now we create a constructor instance for the graph

    Graph(vector<Edge> const &edges, int N) {
        adjList.resize(N);
//      add edges to the graph
        for (auto &edge:edges) {
            adjList[edge.src].push_back(edge.dest);
        }

    }





};
// function to show elements of the grapph
void Graph ::show() {
    for(auto &elements : adjList){
        cout << (&elements) << "-->" ;
        for(int u : elements){
            cout << u << "-->" ;
        }
        cout << endl;
    }
}



void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    visited[v] = true;
    // mark current node as visited
    // for every node, visit
    for(int u: graph.adjList[v])
    {
        if(!visited[u])
        {
            DFS(graph, u,visited);
        }
    }
}
// function to check if the graph is strongly connected or not

bool check(Graph const &graph, int N)
{
    for(int i = 0;i <N ; i++)
    {
        vector<bool> visited(N);
        DFS(graph,i,visited);
        if( find(visited.begin(),visited.end(),false) != visited.end()) return false;


    }
    return true;
}


using namespace std;

int main()
{

    vector<Edge> edges = {
            {0,4}, {1,0}, {1,2}, {2,1},
            {2,4}, {3,1}, {3,2}, {4,3}
    };
    int N = 5;
    Graph graph(edges,N);
    cout << check(graph,N);
    cout <<endl;
    graph.show();
    return 0;
}

