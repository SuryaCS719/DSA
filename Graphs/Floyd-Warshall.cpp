#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

class Graph {
public:
  unordered_map<int, list<pair<int, int>>> adjList;
  void addEdge(int u, char v, int wt, bool direction) {
    // dir -> 0 : undirected, 1 -> directed
    if(direction == 0){
       adjList[u].push_back({v, wt});
       adjList[v].push_back({u, wt});
    }
    else  
      adjList[u].push_back({v, wt});
  }

  void printAdjList() {
    for(auto i : adjList) {
      cout << i.first << " -> [";
      for(auto j : i.second) 
        cout << "{ " << j.first << ", " << j.second << " }, ";
      cout << "]" << endl;
    }
  }


  // Floyd–Warshall algorithm - MSSP
  void floydWarshall(int V) {
    // V = adjList.size(); // optional since we are sending V as 4 anyway
    // init state
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX)); // can use INT_MAX instead of 1e9 but if we have to handle an **int_overflow condition
    
    // set all diagonals to 0 as a node to itself is 0 distance.
    for(int i = 0; i < V; i++)
      dist[i][i] = 0;
    
    // updating given weights of the graph into distArr.
    for(auto a : adjList){
      for(auto b : a.second) {
        int u = a.first;
        int v = b.first;
        int wt = b.second;
        dist[u][v] = wt;
      }  
    }

    // main logic - Helper 
    for(int helper = 0; helper < V; helper++) {
      for(int src = 0;  src < V; src++) {
        for(int dest = 0; dest < V; dest++)
            if(dist[src][helper] != INT_MAX && dist[helper][dest] != INT_MAX) // ** handling int_overflow case
             dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
      }
    }

    // print distanceArray
    for(auto &vec : dist) {
      for(auto &i : vec)
        cout << i << " ";
      cout << endl;
    }

  } 

};


int main() {
  Graph g;

  g.addEdge(0, 1, 3, 1);
  g.addEdge(1, 0, 2, 1);
  g.addEdge(0, 3, 5, 1);
  g.addEdge(1, 3, 4, 1);
  g.addEdge(3, 2, 2, 1);
  g.addEdge(2, 1, 1, 1);

  // g.printAdjList(); 

  int V = 4;
  g.floydWarshall(V);

  return 0;
}
