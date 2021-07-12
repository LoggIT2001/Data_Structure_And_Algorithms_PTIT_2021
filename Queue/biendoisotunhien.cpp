#include<bits/stdc++.h>
using namespace std;

int solution(int n){
    set<int> myset;
    queue<pair<int,int> > qe;
    qe.push({n,0});
    myset.insert(n);
    while(!qe.empty()){
        pair<int,int> pa=qe.front();
        qe.pop();
        if(pa.first == 1) return pa.second;
        if(pa.first-1==1) return pa.second+1;
        if(myset.find(pa.first - 1)==myset.end()){
            qe.push({pa.first-1, pa.second+1});
            myset.insert(pa.first-1);
        }
        for(int i=2;i*i<=pa.first;i++){
            if(pa.first %i ==0){
                if(myset.find(pa.first / i)==myset.end()){
                    qe.push({pa.first/i,pa.second+1});
                    myset.insert(pa.first/i);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << solution(n);
        cout << endl;
    }
    return 0;
}