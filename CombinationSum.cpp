//combination sun (recursion)
#include <bits/stdc++.h>
using namespace std;
void solution(vector<int> &vec, int target, int index, vector<vector<int>> &ans, vector<int> &ds){
    if(index==vec.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    
    //when the index is selected
    if(vec[index]<=target){
        ds.push_back(vec[index]);
        solution(vec, target - vec[index], index, ans, ds);
        ds.pop_back();
    }
    
    //when the index is not selected
    solution(vec, target, index+1, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &vec, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    solution(vec, target, 0, ans, ds);

    return ans;
}

int main(){
    //size of vector
    int n;
    cin >> n;

    //input vector
    vector<int> vec(n);
    for (int i = 0; i < n; i++){ cin >> vec[i]; }

    //enter target
    int target;
    cin >> target;

    vector<vector<int>> ans = combinationSum(vec, target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}