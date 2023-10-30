// 1. Permutations of a string ; Backtracking

// Note: passing string as reference thus we use backtracking or else it'll give the wrong ans

void printPermutation(string &str, int i){
    // basecase
    if(i >= str.length()){
        cout << str << endl;
        return;
    }

    for(int j = i; j < str.length(); j++){
        swap(str[i], str[j]);
        // recursion
        printPermutation(str, i+1);
        // backtracking
        swap(str[i], str[j]);
    }
}

int main(){
    string str = "abc";
    int i = 0;  
    printPermutation(str, i);
}
