#include<iostream>
using namespace std;

int n,k,i,x[100];
void genNext(){
    i=k;
    while(i>0 && x[i]==x[i-1]+1){
        x[i]=n-k+i;
        i--;
    }
    x[i]--;
    if(i<=0){
        for(i=1;i<=k;i++) x[i]=n-k+i;
    }
}
int main(){
    int t;
    while(t--){
        cin >> n >> k;
        for(i=1;i<=k;i++) cin >> x[i];
        genNext();
        for(i=1;i<=k;i++) cout << x[i] <<" ";
        cout << endl;
    }
    return 0;
}