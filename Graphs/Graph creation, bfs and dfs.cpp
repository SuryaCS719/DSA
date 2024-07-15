#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;


class Graph {
public:
    unordered_map<int, list<int>> adjList;
    
    void addEdge(int u, int v, bool direction) {
        // direction: 1 -> directed | 0 -> undirected
        if(direction == 1)
            adjList[u].push_back(v);
        else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        cout << "printing adjList " << endl;
        printAdjList();
        cout << endl;
    }


    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << " -> {";
            for(auto neighbor : i.second)
                cout << neighbor << ", ";
            cout << "}";
            cout << endl;
        }
    }
};

// Adjacency list - weighted graph
class Graph2 {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction) {
        if(direction == 1)
            adjList[u].push_back({v, wt});
        else {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        cout << "printing adjList " << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << " -> [ ";
            for(auto p : i.second) // instead of auto we couldve used: pair<int, int> p 
                cout << "{" << p.first << ", "<< p.second << "}, ";
            cout << "]";
            cout << endl;
        }
    }
};





// graph generic data type using TEMPLATE CONCEPT
template<typename T>

class Graph3 {
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction) {
        if(direction == 1)
            adjList[u].push_back({v, wt});
        else {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        cout << "printing adjList " << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << " -> [ ";
            for(auto p : i.second) // instead of auto we couldve used: pair<T, int> p 
                cout << "{" << p.first << ", "<< p.second << "}, ";
            cout << "]";
            cout << endl;
        }
    }


    void bfs(T src, unordered_map<T, bool> &visited) {
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()) { 
            T front = q.front();
            q.pop();
            
            cout << front << " ";

            for(auto neighbor : adjList[front]) {
                T neighborData = neighbor.first;
                if(visited[neighborData] == false) {
                    q.push(neighborData);
                    visited[neighborData] = true;
                }
            }
        }
    }


    void dfs(T src, unordered_map<T, bool> &visited) {
        visited[src] = true;
        cout << src << " ";

        for(auto neighbor : adjList[src]) {
            T neighborData = neighbor.first;
            if(visited[neighborData] == false)
                dfs(neighborData, visited);
        }
    }


};



int main() {

    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);

    // Graph2 g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(1, 2, 6, 1);
    // g.addEdge(0, 2, 7, 1);


    Graph3<char> g;
    g.addEdge('a', 'b', 5, 1);
    // g.addEdge('a', 'c', 6, 1);
    g.addEdge('c', 'd', 7, 1);
    // g.addEdge('c', 'e', 7, 1);
    // g.addEdge('d', 'e', 7, 1);
    // g.addEdge('e', 'f', 7, 1);
    
    // g.bfs('a', visited);  // -> BFS

    
    // Handling disconnected graphs as well.  // -> BFS

    // g.addEdge('a', 'b', 5, 1);
    // g.addEdge('b', 'c', 6, 1);


    // g.addEdge('d', 'e', 5, 1);

    // g.addEdge('f', 'f', 6, 1);
    
    // unordered_map<char, bool> visited;

    // for(char node = 'a'; node <= 'f'; node++) {
    //     if(visited[node] == false)
    //         g.bfs(node, visited);
    // }


    // DFS

    unordered_map<char, bool> visited;
    // g.dfs('a', visited);


    // Handling disconnected graphs as well.  // -> DFS

    int count = 0;

     for(char node = 'a'; node <= 'd'; node++) {
        if(visited[node] == false) {
            g.dfs(node, visited);
            count = count + 1;
        }
    }

    

    cout << endl << "no of disconnected components: " << count << endl;


    return 0;
}
