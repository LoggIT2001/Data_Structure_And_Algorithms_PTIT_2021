#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int x,y,z;
        string X,Y,Z;
        cin >> x >> y >> z >> X >> Y >> Z;
        int dp[101][101][101];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                for(int k=1;k<=z;k++){
                    if(X[i-1]==Y[j-1] && Y[j-1]==Z[k-1]){
                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    }else{
                        dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                    }
                }
            }
        }
        cout << dp[x][y][z] << endl;
    }
    return 0;
}