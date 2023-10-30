// 2. Raze in a Maze ; IMP Q


// 3 conditions to keep in mind:
// i. can't go out of bound
// ii. cant traverse through the blocked coordinates i.e 0 blocks ; closed path
// iii. can only visit each coordinate once 
// i.e already visted positions should be marked and not be traversed thorugh again
// so traverse only through unvisited blocks

// function that'll handle these above conditions
bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool> > &visited){
    if((newx >=0 && newx < row) && (newy >= 0 && newy < col)
    && maze[newx][newy] == 1 
    && visited[newx][newy] == false){

        return true;
    }
    else
        return false;
}


void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool> > &visited){

    //basecase: at destination; destination coordinates are [row-1], [col-1]
    if(srcx == row-1 && srcy == col-1){
        cout << output << endl;
        return;
    }

    // solve for 1 case and let recurison handle the rest

    // up
    int newx = srcx - 1;
    int newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        // backtracking -> while coming back from recursive calls mark it unvisited.
        output.pop_back();
        visited[newx][newy] = false;
    }

    // right
    newx = srcx;
    newy = srcy + 1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        // backtracking -> while coming back from recursive calls mark it unvisited.
        output.pop_back();
        visited[newx][newy] = false;
    }

    // down
    newx = srcx + 1;
    newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);
        // backtracking -> while coming back from recursive calls mark it unvisited.
        output.pop_back();
        visited[newx][newy] = false;
    }

    // left
    newx = srcx;
    newy = srcy - 1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);
        // backtracking -> while coming back from recursive calls mark it unvisited.
        output.pop_back();
        visited[newx][newy] = false;
    }

}


int main(){
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };

    int row = 4;
    int col = 4; 

    int srcX = 0;
    int srcY = 0;

    string output = "";

    // create visited 2D_Array
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    
    // one case where if source position itself is 0 then there is no answer
    if(maze[0][0] == 0)
        cout << "No path exists" << endl;
    else{
        visited[srcX][srcY] = true;
        printAllPath(maze, row, col, srcX, srcY, output, visited);
    }    

}
