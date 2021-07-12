#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n+5];
        for(int i=0;i<n;i++) cin >> a[i];
        int Max=a[0], Min=a[0];
        for(int i=0;i<n;i++){
            Max=max(Max,a[i]);
            Min=min(Min,a[i]);
        }
        cout  << (Max-Min+1) -n << endl;
    }
    return 0;
}