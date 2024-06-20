#include <iostream>
#include <queue>
using namespace std;

class Info {
public:
  int data;
  int rowIndex;
  int colIndex;

  Info(int data, int rowIndex, int colIndex) {
    this->data = data;
    this->rowIndex = rowIndex;
    this->colIndex = colIndex;
  }
};

class customCompForMinHeap {
public:
  bool operator()(Info* a, Info* b) {
    return a->data > b->data;
  }
};

void mergeKSortedArrays(int arr[][4], int n, int k, vector<int>& ans) {
  priority_queue<Info*, vector<Info*>, customCompForMinHeap> pq;

  // step 1. process first k elements:
  for(int row = 0; row < k; row++) {
    Info* temp = new Info(arr[row][0], row, 0);
    pq.push(temp);
  }

  // handle the rest of the process:
  while(!pq.empty()) {

    // extract info of top ele of min heap.
    Info* infoOfTopOfMinHeap = pq.top();
    pq.pop(); 

    int topOfMinHeap = infoOfTopOfMinHeap->data;
    int topRowIndex = infoOfTopOfMinHeap->rowIndex;
    int topColIndex = infoOfTopOfMinHeap->colIndex;

    // store top of minheap in ans vector.
    ans.push_back(topOfMinHeap);

    // to insert another new element to replace the top. 
    // check whether a new element exists before insertion.
    if(topColIndex + 1 < n) {
      Info* newInfo = new Info(arr[topRowIndex][topColIndex + 1], topRowIndex, topColIndex + 1);
      pq.push(newInfo);
    }

    // Deallocate memory for infoOfTopOfMinHeap
    delete infoOfTopOfMinHeap;
  }
  
  // Clean up any remaining elements in the priority queue
    while (!pq.empty()) {
        Info* info = pq.top();
        pq.pop();
        delete info;
    }
}

int main() {
  int arr[3][4] = {
                  {1, 4, 8, 11},
                  {2, 3, 6, 10},
                  {5, 7, 12, 14}
  };

  int n = 4;
  int k = 3;

  vector<int> ans;
  mergeKSortedArrays(arr, n, k, ans);

  cout << "Printing ans arr: " << endl;
  for(auto i : ans)
    cout << i << " ";

  return 0;
}
