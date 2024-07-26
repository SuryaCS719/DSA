#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prim's algorithm - Greedy based
        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        > pq; 

        pq.push({0, {0, -1}}); // {{wt, {node, parent}}
        vector<int> vis(V, 0);
        int sum = 0;
        vector<pair<int, int>> nodeToParentMST;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            if(vis[node] == 1)
                continue; 
            
            vis[node] = 1;
            sum = sum + wt;

            if (parent != -1) // Do not include the first node with parent -1
              nodeToParentMST.push_back({parent, node}); // {parent, node} // To store the MST edges


            for(auto nbr : adj[node]){
                int adjNode = nbr[0];
                int adjWt = nbr[1];
                
                if(!vis[adjNode])
                    pq.push({adjWt, {adjNode, node}}); // {{wt, {node, parent}}
            }
        }

        // Output the MST edges
        cout << "Edges in MST:" << endl;
        for(auto &edge : nodeToParentMST){
            cout << edge.first << " - " << edge.second << endl;
        }
        
        cout << "Sum of weights of edges of MST: ";
        return sum;
    }
};



int main()
{
    Solution obj;
    int V = 5;
    // Array of 2D Vectors
    vector<vector<int>> adj[V];

    // Example graph
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    cout << obj.spanningTree(V, adj) << endl;

    return 0;
}


/*
(wt), V = 5

      0 -(6)- 3
      |     / (8)
      (2) /
      | /
      1 -(3)- 2
   (5) \     / (7)
          4


Output:

Edges in MST:
0 - 1
1 - 2
1 - 4
0 - 3
Sum of weights of edges of MST: 16 

*/






// same as above but uses 2D Vector of Pairs instead of Array of 2D vectors for input graph


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<pair<int, int>>> &adj)
    {
        // Prim's algorithm - Greedy based
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, -1}});
        vector<int> vis(V, 0);
        int sum = 0;
        vector<pair<int, int>> nodeToParentMST;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += wt;

            if (parent != -1)
                nodeToParentMST.push_back({parent, node});

            for (auto nbr : adj[node])
            {
                int adjNode = nbr.first;
                int adjWt = nbr.second;

                if (!vis[adjNode])
                    pq.push({adjWt, {adjNode, node}});
            }
        }

        cout << "Edges in MST:" << endl;
        for (auto &edge : nodeToParentMST)
        {
            cout << edge.first << " - " << edge.second << endl;
        }

        return sum;
    }
};

int main()
{
    Solution obj;
    int V = 5;
    // 2D Vector of Pairs
    vector<vector<pair<int, int>>> adj(V);  // Create a vector of vector of pairs with size V

    // Adding edges
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    cout << "Sum of weights of edges of MST: " << obj.spanningTree(V, adj) << endl;

    return 0;
}
