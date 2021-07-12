#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int V,E;
        cin >> V >> E;
        vector<int> ke[V+5];
        for(int i=1;i<=E;i++){
            int x,y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for(int i=1;i<=V;i++){
            sort(ke[i].begin(),ke[i].end());
        }
        for(int i=1;i<=V;i++){
            cout << i << ": ";
            for(int j=0;j<ke[i].size();j++){
                cout << ke[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}