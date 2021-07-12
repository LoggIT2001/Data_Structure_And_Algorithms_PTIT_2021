#include<bits/stdc++.h>
using namespace std;

long long a[100];
char day(int n, int k){
    if(n==1) return '0';
    if(n==2) return '1';
    if(k<=a[n-2]) return day(n-2,k);
    return day(n-1,k-a[n-2]);
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        a[1]=1;
        a[2]=1;
        for(int i=3;i<=92;i++){
            a[i]=a[i-1]+a[i-2];
        }
        cout << day(n,k) << endl;
    }
    return 0;
}