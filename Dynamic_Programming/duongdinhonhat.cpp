#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

int main(){
    FastIO; IN; OUT;
    
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        int a[n+5][m+5];
        int dp[n+5][m+5];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1) dp[i][j] = a[i][j];
                else if(i==1) dp[i][j] = a[i][j] + dp[i][j-1];
                else if(j==1) dp[i][j] = a[i][j] + dp[i-1][j];
                else dp[i][j] = a[i][j] + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}