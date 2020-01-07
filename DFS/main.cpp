#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//#define vector<vector<int>> vvi

// data structure to store graph edges
struct Edge
{
    int src,dest;
};

// a class to rerpresent graph object
class Graph
{
public:
    vector<vector<int>>  adjList;
    //    constructor
    Graph(vector<Edge> const &edges, int N)
    {
        adjList.resize(N);
//     add edges to adjacency list
        for(auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }

    }

};
// function to perform DFS traversal
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




int main() {
    vector<Edge> edges = {
            {0,4}, {1,0}, {1,2}, {2,1},
            {2,4}, {3,1}, {3,2}, {4,3}
    };
// number of nodes in the graph

int N = 5;
Graph graph(edges,N);

bool q = check(graph,N);
cout << q << endl;


return 0;
}
