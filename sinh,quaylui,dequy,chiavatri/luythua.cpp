#include<iostream>
using namespace std;

const long long mod=1e9+7;
long long Power(long long a, long long b){
    if(b==0) return 1;
    if(b==1) return a%mod;
    else{
        long long p=Power(a,b/2);
        p=p%mod;
        if(b%2==0) return (p%mod * p%mod)%mod;
        else return ((p%mod * p%mod)%mod * a%mod)%mod;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long a,b;
        cin >> a >> b;
        if(a==0 || b==0) break;
        long long result=Power(a,b);
        cout << result << endl;
    }
    return 0;
}