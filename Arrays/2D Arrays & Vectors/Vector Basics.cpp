// ------- 1D Vector ----------

int main(){
    vector <int> v(5, -1);
    cout << v.size() << endl;
    for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;


    // vector <int> arr;

    // arr.push_back(1);
    // arr.push_back(2);

    // cout << arr.empty() << endl;
}

// ------- 2D Vector ----------

int main(){
    // vector < vector <int> > arr;
    vector< vector<int> > arr(5, vector<int>(10, 2)); 
    for(int i=0; i < arr.size(); i++){
        for(int j=0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Jagged Array

int main(){
    vector<vector <int> > arr;
    vector<int> arr1(3,3);
    vector<int> arr2(5,5);
    vector<int> arr3(7,7);
    vector<int> arr4(9,9);

    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    arr.push_back(arr4);

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}
