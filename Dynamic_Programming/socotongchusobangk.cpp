#include<bits/stdc++.h>
using namespace std;

// dp[i][s] la so co i chu so va tong la s
// so co i chu so tao thanh bang cach ghep 1 so vao i-1
// dp[i][s] += dp[i-1][s-j] i-1 chu so co tong la s-j

long long const mod=1e9+7;

int main(){
    long long dp[105][50005];
    for(int i=0;i<101;i++) dp[i][0]=0;
    for(int i=0;i<50001;i++) dp[0][i]=0;
    for(int i=1;i<=9;i++) dp[1][i]=1;

    for(int i=1;i<=100;i++){
        for(int j=0;j<=9;j++){
            for(int s=j;s<=50000;s++){
                dp[i][s]=(dp[i][s]%mod + dp[i-1][s-j]%mod)%mod;
            }
        }
    }

    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}