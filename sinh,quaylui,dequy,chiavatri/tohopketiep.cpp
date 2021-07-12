#include<iostream>
using namespace std;

int n,k,a[100],i,j;
void genNext(){
    i=k;
    while(i>=0 && a[i]==n-k+i) i--;
    if(i>0){
        a[i]++;
        for(j=i-1;j<=k;j++){
            a[j]=a[i]+j-i;
        }
    }else{
        for(int i=1;i<=k;i++){
            a[i]=i;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=k;i++) cin >> a[i];
        genNext();
        for(int i=1;i<=k;i++) cout << a[i] <<" ";
        cout << endl;
    }
    return 0;
}