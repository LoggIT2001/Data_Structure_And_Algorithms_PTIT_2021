#include<bits/stdc++.h>
using namespace std;

#define ll long long
long long const mod=1e9+7;

ll n,k;
ll x[10][10],y[10][10];
void Multiply(ll x[10][10], ll y[10][10]){
    ll tmp[10][10];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll Mul=0;
            for(ll l=0;l<n;l++){
                Mul+=(x[i][l] * y[l][j])%mod;
                Mul%=mod;
            }
            tmp[i][j]=Mul;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            x[i][j]=tmp[i][j];
        }
    }
}
void Pow(ll x[10][10], ll n){
    if(n<=1) return;
    Pow(x,n/2);
    Multiply(x,x);
    if(n&1) Multiply(x,y);
}
void result(){
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=x[i][0];
    }
    cout << sum%mod << endl;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> k;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin >> x[i][j];
                y[i][j]=x[i][j];
            }
        }
        Pow(x,k);
        result();
    }
    return 0;
}