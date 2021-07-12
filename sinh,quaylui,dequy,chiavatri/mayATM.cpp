#include<bits/stdc++.h>
using namespace std;

bool stop=false;
int c[50],a[50];
int n,k;
void GenNext(int s){
    int i=s;
    while(c[i]==n-s+i && i>=0) i--;
    if(i<=0) stop=true;
    else{
        c[i]++;
        for(int j=i+1;j<=s;j++){
            c[j]=c[j-1]+1;
        }
    }
}
int Dem(int n, int k){
    for(int i=1;i<=n;i++){
        stop=false;
        for(int j=1;j<=i;j++){
            c[j]=j;
        }
        while(!stop){
            int sum=0;
            for(int j=1;j<=i;j++){
                sum+=a[c[j]];
            }
            if(sum==k){
                return i;
            }
        }
        GenNext(i);
    }
    return (int)(-1);
}
int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        cout << Dem(n,k) << endl;
    }
    return 0;
}