#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// data structure to store graph edges
struct Edge
{
    int src,dest;
};

class Graph
{
public:
//        adjacency list representation
        vector<vector<int>> adjList;
//         Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
//        N is the number of nodes in the graph
            adjList.resize(N);
//    for every source to dest ; an edge which exists we add it to the corresponding adjacency list
            for(auto &edge: edges)
            {
                adjList[edge.src].push_back(edge.dest);
                adjList[edge.dest].push_back(edge.src);
//                because it an undirected graphs the pushbacks are made at both edges
            }
    }

};

// Perform BFS on graph starting from vertex V

void BFS(Graph const &graph, int v, vector<bool> &discovered)
{
//    & means refer it by its address and hence no copy is made, it is so by design of this code
// create a queue to do BFS
queue<int> q;
// mark source vertex as discovered
discovered[v] = true;  //this happens iteratively
// push source vertex into queue
q.push(v);
while(!q.empty())
{
    v = q.front();
    q.pop();
    cout << v << "-->" ;
//    we just address the immediate children of v and push them into queue and the loop runs until all connected components have been traversed
for(int u : graph.adjList[v])
{
    if(!discovered[u])
    {
        q.push(u);
        discovered[u]=true;
    }
}




}

}


int main() {
vector<Edge> edges = {
        {1,2}, {1,3}, {1,4},{2,5},{2,6},
        {5,9}, {5,10}, {4,7}, {4,8}, {7, 11}, {7,12}
};
// number of nodes N        vertex 0,13,14 are single nodes
int N =15;
Graph graph(edges, N);    //create a graph from edges
vector<bool> discovered(N, false);
// if the edge is not discovered or visited yet, then further perform the BFS on it
for(int i = 0; i<N;i++)
{
    if(discovered[i]==false)
    {
//        perform BFS if node has not been visited yet
BFS(graph, i, discovered);
    }
}

    return 0;
}