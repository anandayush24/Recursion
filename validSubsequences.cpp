#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> &vec, int index, vector<int> &ds){
    if(index==vec.size()){
        for(auto itr: ds){ cout<<itr<<" "; }
        cout<<endl;
        return;
    }

    if(ds.size()==0){
        cout<<"{}"<<endl;
    }

    //when the element is picked
    ds.push_back(vec[index]);
    solution(vec, index+1, ds);
    ds.pop_back();

    //when the element is not piked
    solution(vec, index+1, ds);
}

int main(){
    int n;
    cin>>n;

    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int> ds;
    solution(vec, 0, ds);
    return 0;
}