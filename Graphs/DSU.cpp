#include <iostream>
#include <vector>
using namespace std;

// DSU: Time (4α), where alpha is ~O(1) Constant time.
class DisjointSet{
  vector<int> rank;
  vector<int> parent;
  vector<int> size;
public:
  DisjointSet(int n){
    rank.resize(n + 1, 0);
    parent.resize(n + 1); // works for 0th and 1-based indexing
    for(int i = 0; i <= n; i++)
      parent[i] = i;
    
    size.resize(n + 1, 1);
  }

  int findUPar(int node) {
    if(node == parent[node])
      return node;
    return parent[node] = findUPar(parent[node]);
  }

  void UnionByRank(int u, int v)  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if(ulp_u == ulp_v)
      return; // they belong to the same component
    
    if(rank[ulp_u] < rank[ulp_v]) 
      parent[ulp_u] = ulp_v; // u will attach to v
    else if(rank[ulp_v] < rank[ulp_u])
      parent[ulp_v] = ulp_u; // v will attach to u
    else {
      parent[ulp_v] = ulp_u; // we can do either
      rank[ulp_u]++;
    }
  }

  void UnionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if(ulp_u == ulp_v)
      return; // they belong to the same component

    if(size[ulp_u] < size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }

  }

};


int main() {
  
  DisjointSet ds(7);

  // ds.UnionByRank(1, 2);
  // ds.UnionByRank(2, 3);
  // ds.UnionByRank(4, 5);
  // ds.UnionByRank(6, 7);
  // ds.UnionByRank(5, 6);
  // ds.UnionByRank(3, 7);

  ds.UnionBySize(1, 2);
  ds.UnionBySize(2, 3);
  ds.UnionBySize(4, 5);
  ds.UnionBySize(6, 7);
  ds.UnionBySize(5, 6);
  ds.UnionBySize(3, 7);

  if(ds.findUPar(3) == ds.findUPar(7))
    cout << "same parent" << endl;
  else 
    cout << "not same parent" << endl;

  return 0;
}
