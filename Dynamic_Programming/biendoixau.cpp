#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

// dp[i][j] la so cach de bien doi i ky tu s1 thanh j ky tu s2
// neu dp[i][0] ta phai xoa di i ky tu
// neu dp[0][j] ta phai chen j ky tu
// neu i==0 va j==0 thi dp[i][j]=i+j

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        string s1,s2;
        cin >> s1 >> s2;
        int n=s1.size();
        int m=s2.size();
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0 || j==0) dp[i][j]=i+j;
                else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}