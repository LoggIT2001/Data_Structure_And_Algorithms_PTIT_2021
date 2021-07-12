#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

// tim day con tang tu 1 den i
// tim day con giam tu i den n
// tim max cua phan tu day 1+2-a[i]

/*********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n+5];
        int tang[n+5]; // mang tang
        int giam[n+5]; // mang giam
        for(int i=1;i<=n;i++){
            cin >> a[i];
            tang[i]=a[i];
            giam[i]=a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<i;j++){
                if(a[i]>a[j]){
                    tang[i]=max(tang[i],tang[j]+a[i]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n;j>i;j--){
                if(a[i]>a[j]){
                    giam[i]=max(giam[i],giam[j]+a[i]);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            res=max(res,tang[i]+giam[i]-a[i]);
        }
        cout << res << endl;
    }
    return 0;
}

/******design by DTLong*****/ 