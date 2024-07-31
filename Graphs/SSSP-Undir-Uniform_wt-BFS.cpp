#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;


class Graph {
public:
    unordered_map<int, list<int>> adjList;
    
    void addEdge(int u, int v, bool direction) {
        if(direction == 1) // directed graph 
            adjList[u].push_back(v);
        else if(direction == 0) {
            // dir == 0, undirected graph
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << " -> {";
            for(auto child : i.second) {
                cout << child << ", ";
            }
            cout << "}" << endl;
        }
    }


    void shortestPathBFS(int src, int dst) {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for(auto nbr : adjList[frontNode]) {
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
            }
        }

        // parent array formed.
        vector<int> ans;
        while(dst != -1){
            ans.push_back(dst);
            dst = parent[dst];
        }
        reverse(ans.begin(), ans.end());
        // print shortest path
        for(auto i : ans)
            cout << i << "-";

    }

};


/* 
input graph:

   1 - 2 
 /       \ 
0 -  3 -  5
 \       /
  4 -  6
*/

// shortest path undirected graph using BFS
// Time O(V + E) Space O(V + E)


int main() {
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(0, 4, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(6, 5, 0);

    // int V = 8;
    int source = 0;
    int destination = 5;

    g.shortestPathBFS(source, destination);


}








