#include<iostream>
using namespace std;

int n,k,i,j,x[100];
void init(){
    for(i=1;i<=k;i++) x[i]=i;
}
bool stop(){
    for(i=1;i<=k;i++){
        if(x[i] != n-k+i) return false;
    }
    return true;
}
void genNext(){
    i=k;
    while(x[i]=n-k+i) i--;
    if(i>0){
        x[i]++;
        for(j=i+1;j<=k;j++){
            x[j]=x[i]+j-i;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        init();
        while(!stop){
            genNext();
            for(int i=1;i<=k;i++) cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}