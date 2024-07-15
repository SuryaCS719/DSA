// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// Adjaceny matrix:
// input: edges listL {u, v}
int main() {
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges" << endl;
    cin >> e;

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        // mark it as 1
        adjMatrix[u][v] = 1;
    }

    //print
    for(auto &i : adjMatrix){
        for(auto &j : i)
            cout << j << " ";
        cout << endl;
    }
}
/*
Enter the number of nodes
3
Enter the number of edges
6

0 1
1 0
1 2
2 1
0 2
2 0

0 1 1 
1 0 1 
1 1 0 
*/
