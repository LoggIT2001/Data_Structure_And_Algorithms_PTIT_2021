#include<iostream>
#include<algorithm>
using namespace std;

int i,j,n,x[100],k;
void genNext(){
    i=n-1;
    while(i>=0 && x[i]>x[i+1]) i--;
    if(i>0){
        k=n;
        while(x[i]>x[k]) k--;
        int v=x[i];x[i]=x[k];x[k]=v;
        int r=i+1,l=n;
        while(r<=l){
            int tmp=x[r];x[r]=x[l];x[l]=tmp;
            r++;
            l--;
        }
    }else{
        for(int i=1;i<=n;i++){
            x[i]=i;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(i=1;i<=n;i++) cin >> x[i];
        genNext();
        for(int i=1;i<=n;i++) cout << x[i] <<" ";
        cout << endl;
    }
    return 0;
}