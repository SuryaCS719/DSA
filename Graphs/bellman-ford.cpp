#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

class Graph {
public:
  unordered_map<char, list<pair<char, int>>> adjList;
  void addEdge(char u, char v, int wt, bool direction) {
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
  
  // Bellman-Ford Algo - SSSP
  void bellmanFord(int V, char src) {
    // initial state
    vector<int> dist(V, INT_MAX);
    dist[src - 'A'] = 0; // treat src as index i.e - 'A'.

    // relaxation: (N - 1) times
    // more optimization here to stop the loop early even before the n - 1 times if the values ain't getting updated
    
    for(int i = 0; i < V - 1; i++) {
      bool stopEarly = false;
      for(auto a : adjList) {
        for(auto b : a.second) {
          // char u = a.first; // WRONG
          // char v = b.first; // WRONG
          int u = a.first - 'A';
          int v = b.first - 'A';
          
          int wt = b.second;
          // slight optimization here can be done by checking if dist[u] is int_max or not.
          // cuz if it is then there's no point in adding extra to it as we'll get an int overflow
          if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            dist[v] = dist[u] + wt;
            stopEarly = true;
          }
        }
      }
      if(stopEarly == false)
        break;
    }
    
    // at this point, shortest distance will be ready
    // now to check for a -ve cycle i.e. whether it exists or not, we run the loop for 1 more time
    // if we see any values updated in this iteration then there exist a -ve cycle.

    bool valueUpdation = false;
      
    for(int i = 0; i < V - 1; i++) { // N - 1
      for(auto a : adjList) {
        for(auto b : a.second) {
          int u = a.first - 'A';
          int v = b.first - 'A';
          
          int wt = b.second;
          if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            valueUpdation = true;
            break;
            // dist[v] = dist[u] + wt; dont need to update it
          }
        }
      }
    }

    if(valueUpdation)
      cout << "Negative cycle present" << endl;
    else {
      cout << "Negative cycle not present" << endl;
      cout << "printing distance array: " << endl;
      for(auto i : dist) 
        cout << i << ", ";
      cout << endl; 
    } 
    
  }
    
};

int main() {
  Graph g;
  g.addEdge('A', 'B', -1, 1);
  g.addEdge('B', 'E', 2, 1);
  g.addEdge('E', 'D', -3, 1);
  g.addEdge('D', 'C', 5, 1);
  g.addEdge('A', 'C', 4, 1);
  g.addEdge('B', 'C', 3, 1);
  g.addEdge('B', 'D', 2, 1);
  g.addEdge('D', 'B', 1, 1);

  g.printAdjList();

  int V = 5;
  g.bellmanFord(V, 'A');



  return 0;
}
