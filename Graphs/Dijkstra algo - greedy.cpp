#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;


// Dijkstra Algorithm - Greedy based.

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    
    void addEdge(int u, int v, int wt, bool direction) {
        if(direction == 1)
            adjList[u].push_back({v, wt});
        else {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for(auto it : adjList) {
            cout << it.first << " -> [";
            for(auto neighborPair : it.second)
                cout << "{ " << neighborPair.first << ", " << neighborPair.second << "}, ";
            cout << "]" << endl;
        }
    }

    void dijkstraShortestDist(int V, int src, int dest) {
        vector<int> distance(V + 1, INT_MAX); // distance array
        set<pair<int, int>> greedyStorage;

        // initial state
        greedyStorage.insert({0, src}); // {distance, node}
        distance[src] = 0;

        // update distance for other nodes
        while(!greedyStorage.empty()) {
            auto topItem = greedyStorage.begin();
            pair<int, int> topPair = *topItem;
            int topDistance = topPair.first;
            int topNode = topPair.second;
            greedyStorage.erase(greedyStorage.begin()); // remove the topItem

            // now, update the distance for neighbor nodes
            for(pair<int, int> nbr : adjList[topNode]) {
                int nbrDist = nbr.second;
                int nbrNode = nbr.first;
                // check if topNode's distance + edge dist is < distance of neighborNode
                if(topDistance + nbrDist < distance[nbrNode]){
                    // here we found a new shorter distance so we update the: distance arr and current set's entry
                    // but before that we clear the previousEntry of the set:
                    auto previousEntry = greedyStorage.find({distance[nbrNode], nbrNode});
                    if(previousEntry != greedyStorage.end()) {
                        // previousEntry found in the set, so we delete it.
                        greedyStorage.erase(previousEntry);
                    }

                    distance[nbrNode] = topDistance + nbrDist; // i. distance arr
                    greedyStorage.insert({distance[nbrNode], nbrNode}); // ii. revised set's entry
                }
            }
        }

        cout << "Shortest distance from " << src << " Node to " << dest << " Node : " << distance[dest] << endl;
        
        // lets try to print the path as well
        
    }

};


int main() {

    Graph g;
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);
    

    int V = 6;
    int src = 6;
    int dest = 4;
    g.dijkstraShortestDist(V, src, dest);
}
