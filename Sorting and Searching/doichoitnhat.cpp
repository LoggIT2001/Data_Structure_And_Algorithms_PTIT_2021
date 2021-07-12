#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

/**********fuction**********/

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        ll a[n+5], b[n+5],res=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0;i<n;i++){
            if(b[i]!=a[i]){
                for(int j=i+1;j<n;j++){
                    if(b[i]==a[j]){
                        swap(a[i],a[j]);
                        res++;
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}