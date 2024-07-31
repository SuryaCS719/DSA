#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;


// single source shortest path
// weighted directed graph 
// using DFS. Cannot be done using BFS cuz we need to check for all paths as they're of various weights.
// Time O(V + E) Space O(V + E)

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    unordered_map<int, bool> visited;

    void addEdge(int u, int v, int wt, bool direction) {
        if(direction == 1) // directed
            adjList[u].push_back({v, wt});
        else {
            // undirected
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << " -> [";
            for(auto nbg : i.second) 
                cout << "{" << nbg.first << ", " << nbg.second << "}, ";
            cout << "]" << endl;
        }
    }

    void topoOrderDFS(int src, stack<int> &st, unordered_map<int, bool> &visited) {
        visited[src] = true;
        for(auto nbgPair : adjList[src]) {
            int nbrNode = nbgPair.first;
            int nbrDist = nbgPair.second;
            if(!visited[nbrNode])
                topoOrderDFS(nbrNode, st, visited);
        }
        st.push(src);
    }

    void shortestPathDFS(int V, stack<int> &st) {
        vector<int> distArr(V, INT_MAX);

        // initially, fetching source i.e. whatever node's on top of topological sort.
        int src = st.top();

        distArr[src] = 0; // distance of source.

        // apply the same above concept for the rest of the elements in the toppoOrder stack.
        while(!st.empty()) {
            int src = st.top();
            st.pop();

            for(auto nbgPair : adjList[src]) {
                int nbrNode = nbgPair.first;
                int nbrDist = nbgPair.second;
                if(distArr[src] + nbrDist < distArr[nbrNode]){
                    distArr[nbrNode] = distArr[src] + nbrDist; // update
                }
            }
        }

        // distanceArr is ready
        for(auto i : distArr)
            cout << i << " ";

    }
};


int main() {

    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    // g.printAdjList();

    int src = 0;
    stack<int> st;
    unordered_map<int, bool> visited;

    g.topoOrderDFS(src, st, visited);

    // checking topological sort dfs: // verification of whether we obtained correct order
    // while(!st.empty()) {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    int V = 5;
    g.shortestPathDFS(V, st);

}
