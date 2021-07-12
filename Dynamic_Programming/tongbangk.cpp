#include<bits/stdc++.h>
using namespace std;

long long const mod=1e9+7;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        int a[n+5];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        long long dp[n+5];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=k;i++){
            for(int j=0;j<n;j++){
                if(i>=a[j]){
                    dp[i]=(dp[i]+dp[i-a[j]])%mod;
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}