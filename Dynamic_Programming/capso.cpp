#include<bits/stdc++.h>
using namespace std;

// giong bai sap xep cong viec
// sap xep theo so a trong cap <a,b>
// neu a[i].first>a[j].second  dp[i]=max(dp[i],dp[j]+1)

struct data{
    int first,second;
};
bool compan(data a, data b){
    return a.first<b.first;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        data a[n+5];
        int dp[101];
        for(int i=1;i<=n;i++){
            cin >> a[i].first >> a[i].second;
            dp[i]=1;
        }
        sort(a+1,a+1+n,compan);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i].first>a[j].second) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}