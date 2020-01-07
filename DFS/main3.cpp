//
// Created by Prem Kumar Tiwari on 12-12-2019.
//
#include <bits/stdc++.h>
using namespace std;
struct  Edge
{
    int src;
    int dest;
};
class Graph
{
public:
    vector<vector<int>> adjList;
    void show();
//    constructor
    Graph(vector<Edge> const &edges, int N)
    {
        adjList.resize(N);
        for(auto edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }

};
void Graph ::show() {
    for(auto elements: adjList)
    {
        for(int i : elements)
        {
            cout<< i << "-->" ;
        }
        cout << "\n";
    }
}

int main()
{
vector<Edge> edges = {
        {0,4}, {1,0}, {1,2}, {2,1},
        {2,4}, {3,1}, {3,2}, {4,3}
};
Graph graph
(edges,5);

    return 0;
}
