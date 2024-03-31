// Raze in a Maze ; IMP Q ; Backtracking


// 3 Conditions to keep in mind:
// i. can't go out of bound
// ii. cant traverse through the blocked coordinates i.e 0 blocks ; closed path
// iii. can only visit each coordinate once 
// i.e already visted positions should be marked and not be traversed thorugh again
// so traverse only through unvisited blocks


#include <iostream>
#include <vector>
using namespace std;

// This function below handles all the possibilities
// 1. path closed 
// 2. out of bound
// 3. check if pos is already visited

bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>>& visited) {
  if(
    (newx >= 0 && newx < row) && 
    (newy >= 0 && newy < col) && 
    maze[newx][newy] == 1 && 
    visited[newx][newy] == false
    )
      return true;
  else  
    return false;
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited) {

  // Basecase -> at destination; destination coordinates are [row-1], [col-1]
  if(srcx == row - 1 && srcy == col - 1){
    cout << output << endl;
    return;
  }

  // Solving 1 case:
  // 1. Marked Visited
  // 2. Call RE
  // 3. Backtrack -> while coming back from recursive calls mark it unvisited.

  // UP
  int newx = srcx - 1;
  int newy = srcy;
  if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
    visited[newx][newy] = true;
    output.push_back('U');
    printAllPath(maze, row, col, newx, newy, output, visited);
    output.pop_back();
    visited[newx][newy] = false;
  }

  // RIGHT
  newx = srcx;
  newy = srcy + 1;
  if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
    visited[newx][newy] = true;
    output.push_back('R');
    printAllPath(maze, row, col, newx, newy, output, visited);
    output.pop_back();
    visited[newx][newy] = false;
  }

  // DOWN
  newx = srcx + 1;
  newy = srcy;
  if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
    visited[newx][newy] = true;
    output.push_back('D');
    printAllPath(maze, row, col, newx, newy, output, visited);
    output.pop_back();
    visited[newx][newy] = false;
  }

  // LEFT
  newx = srcx;
  newy = srcy - 1;
  if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
    visited[newx][newy] = true;
    output.push_back('L');
    printAllPath(maze, row, col, newx, newy, output, visited);
    output.pop_back();
    visited[newx][newy] = false;
  }

    
}

int main() {
  int maze[4][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {1,1,1,0},
    {1,1,1,1}};

  int row = 4, col = 4;
  int srcx = 0, srcy = 0;
  // destination coordinates are [row-1],[col-1]
  string output = "";
  // create a visited 2D array
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  // Check if src position is closed or not i.e. one case where if source position itself is 0 then there is no answer
  if(maze[0][0] == 0)
    cout << "No Path Exists" << endl;
  else{
    visited[srcx][srcy] = true;
    printAllPath(maze, row, col, srcx, srcy, output, visited);
  }
}
