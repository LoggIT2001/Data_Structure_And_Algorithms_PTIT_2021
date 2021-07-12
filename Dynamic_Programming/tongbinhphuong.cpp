#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int dp[n+5];
        for(int i=0;i<=n;i++){
            dp[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}