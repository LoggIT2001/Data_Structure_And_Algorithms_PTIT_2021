#include<iostream>
#include<cmath>
using namespace std;

bool h[11],c[11],xuoi[22],nguoc[22];
int n,res,a[11],x[10][10];
void init(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> x[i][j];
        }
    }
    res=0;
    n=8;
    for(int i=0;i<11;i++){
        h[i]=c[i]=false;
    }
    for(int i=0;i<22;i++){
        xuoi[i]=nguoc[i]=false;
    }
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(!h[j] && !c[j] && !xuoi[i-j+n] && !nguoc[i+j-1]){
            a[i]=j;
            h[j]=c[j]=xuoi[i-j+n]=nguoc[i+j-1]=true;
            if(i==n){
                int ans=0;
                for(int l=1;l<=8;l++){
                    ans+=x[l][a[l]];
                }
                res=max(res,ans);
            }else
                Try(i+1);
            h[j]=c[j]=xuoi[i-j+n]=nguoc[i+j-1]=false;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        init();
        Try(1);
        cout << res << endl;
    }
    return 0;
}