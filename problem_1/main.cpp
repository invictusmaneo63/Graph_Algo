#include <bits/stdc++.h>
using namespace std;
int longestPath;
int oddCities = 0;

class Graph
{

public:
    vector<vector<int>> adjList;
    int DFS(int src);
    int LongestPath();
    vector<bool> visited;
    // graph constructor
    Graph(vector<int> &T)
    {
        int N = T.size();
        //  converting the represenation into an adjacency list
        adjList.resize(N);
        visited.resize(N);

        for(int i=0;i<N;i++)
        {
            visited[i]=false;
            if(T[i]!=i) //because if they are equal this implies that there is a loop, which we do not consider
            {
                adjList[i].push_back(T[i]);
                adjList[T[i]].push_back(i);
            }
        }


    }
};

int Graph ::DFS(int src) {
//    make a usual depth first search but only for source node
        visited[src] = true;
        longestPath  +=1;
        if(src%2!=0){
            // increment the counter for odd cities
            oddCities +=1;

        }
        vector<int> neighbors ;
        for(int edge: adjList[src])
//        longestPath = 0;
        {
            longestPath=0;
            if((!visited[edge]) && oddCities<2)
            {
                Graph::DFS(edge);
//                currentPath+=1;
            }
        }

        oddCities = 0;
        for(int i =0 ; i<visited.size();i++)
        {
            visited[i] = false;
        }
        return longestPath;

}
//void printNode(Graph const& graph, int N)
//{
//    for(int i = 0; i<N;i++) {
//        cout << i << "->";
//        for (auto v : graph.adjList[i]) {
//            cout<< v << "->";
//        }
//        cout << endl;
//    }
//}

// now we find longest path in the graph through a DFS traversal with only one odd route
int Graph :: LongestPath()
{
    int maxPath=0;
//    int oddCities = 0;
//    the DFS is governed by constraint of the problem
//for(int edge)
maxPath= Graph::DFS(0);

    return maxPath;


}

int main() {
vector<int> A = {0,9,0,2,6,8,0,8,3,0};
//int big = *max_element(A.begin(),A.end());
int n = A.size();
//cout << n;
Graph graph(A);
//printNode(graph,n);
    int src = 3;
    if (src%2!=0)
    {
        cout << "odd" << endl;
    }
    return 0;
}
