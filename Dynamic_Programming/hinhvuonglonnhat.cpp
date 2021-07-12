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
        int result=0;
        int a[n+5][m+5];
        int dp[n+5][m+5];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                dp[i][j]=a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==0) continue;
                if(a[i][j]==a[i-1][j-1] && a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1]){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                result=max(result,dp[i][j]);
            }
        }
        cout << result << endl;
    }
    return 0;
}