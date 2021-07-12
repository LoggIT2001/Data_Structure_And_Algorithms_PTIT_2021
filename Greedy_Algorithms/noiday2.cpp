#include<bits/stdc++.h>
using namespace std;
long long const mod=1e9+7;

void noiday(long long a[], long long n){
    priority_queue<long long, vector<long long>, greater<long long> > p(a,a+n);
    long long sum=0;
    while(p.size() >1){
        long long first=p.top();
        p.pop();
        long long second=p.top();
        p.pop();
        long long x=(first+second)%mod;
        sum+= x;
        sum%=mod;
        p.push(x);
    }
    cout << sum << endl;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        long long n;
        cin >> n;
        long long a[n+5];
        for(int i=0;i<n;i++) cin >> a[i];
        noiday(a,n);
    }
    return 0;
}