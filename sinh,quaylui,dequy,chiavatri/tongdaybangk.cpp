#include<bits/stdc++.h>
using namespace std;

int x[100],a[100];
int n,k;
vector< vector<int> > dp;
void Try(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n){
            int sum=0;
            for(int l=1;l<=n;l++){
                if(x[l]) sum+=a[l];
            }
            if(sum==k){
                vector<int> myvector;
                for(int l=1;l<=n;l++){
                    if(x[l]) myvector.push_back(a[l]);
                }
                dp.push_back(myvector);
            }
        }else{
            Try(i+1);
        }
    }
}
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    dp.clear();
    Try(1);
    if(dp.size()==0) cout << 0 ;
    else{
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << dp.size();
    }
    return 0;
}