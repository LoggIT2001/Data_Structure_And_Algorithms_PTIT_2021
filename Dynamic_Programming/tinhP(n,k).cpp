#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0);
long long const mod=1e9+7;

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        ll res=1;
        if(n<k) res=0;
        else{
            for(int i=n-k+1;i<=n;i++){
                res=(res*i)%mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}
