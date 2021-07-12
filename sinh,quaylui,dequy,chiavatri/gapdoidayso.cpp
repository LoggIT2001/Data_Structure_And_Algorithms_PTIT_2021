#include<iostream>
using namespace std;

long long Mul(int n){
    if(n==0) return 1;
    if(n==1) return 2;
    long long p=Mul(n/2);
    if(n%2==0) return 2*p*p;
    else return p*p;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        long long tmp;
        if(n%2==0) tmp=Mul(n/2);
        else tmp=Mul(n-1)/2;
        while(1){
            if(n==1){
                cout << "1";
                break;
            }
            if(tmp==k){
                cout << n;
                break;
            }
            if(tmp<k) k=tmp-(k-tmp);
            n--;
            tmp/=2;
        }
        cout << endl;
    }
    return 0;
}