#include<bits/stdc++.h>
using namespace std;

long long const mod=1e9+7;
int main(){
    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        long long dp[n+5];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=min(i,k);j++){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}