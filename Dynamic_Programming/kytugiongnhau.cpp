#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

// dp[i] la thoi gian can thiet de viet 1 ky tu
// dp[i]=dp[i-1]+insert thoi gian chen 1 ky tu
// dp[i]=dp[i/2]+copy thoi gian sao chep i ky tu (nhan doi)

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        int Insert,Delete,Copying;
        cin >> n >> Insert >> Delete >> Copying;
        int dp[n+5];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=Insert;
        for(int i=2;i<=n;i++){
            if(i&1) dp[i]=min(dp[i-1]+Insert, dp[(i+1)/2]+Copying+Delete);
            else dp[i]=min(dp[i-1]+Insert, dp[i/2]+Copying);
        }
        cout << dp[n] << endl;
    }
    return 0;
}

/*****design by DTLong*****/