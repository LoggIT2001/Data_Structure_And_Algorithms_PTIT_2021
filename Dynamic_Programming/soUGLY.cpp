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
        int n;
        cin >> n;
        ll dp[n+5];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        // uoc cua 2 3 5
        ll i2=0, i3=0, i5=0;
        for(int i=1;i<=n;i++){
            dp[i]=min(dp[i2]*2, min(dp[i3]*3,dp[i5]*5));
            if(dp[i]==dp[i2]*2) i2+=1;
            if(dp[i]==dp[i3]*3) i3+=1;
            if(dp[i]==dp[i5]*5) i5+=1;
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}