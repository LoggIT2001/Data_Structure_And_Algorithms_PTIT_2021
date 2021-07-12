#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x[26][26];
    memset(x,0,sizeof(x));
    for(int i=0;i<=25;i++){
        x[i][0]=1;
        x[0][i]=1;
    }
    x[0][0]=0;
    for(int i=0;i<=25;i++){
        for(int j=0;j<=25;j++){
            if(i==0 || j==0) continue;
            x[i][j]=x[i-1][j]+x[i][j-1];
        }
    }
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        cout << x[n][m] << endl;
    }
    return 0;
}