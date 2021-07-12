#include<iostream>
using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        ll F[92];
        F[1]=F[2]=1;
        for(ll i=3;i<=92;i++){
            F[i]=F[i-1]+F[i-2];
        }
        ll n,x;
        cin >> n >> x;
        while(n>2){
            if(x<=F[n-2]) n-=2;
            else{
                x-=F[n-2];
                n-=1;
            }
        }
        if(n==1) cout << "0";
        else cout << "1";
        cout << endl;
    }
    return 0;
}