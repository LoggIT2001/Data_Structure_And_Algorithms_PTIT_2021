#include<iostream>
using namespace std;

int a[100],x=0,n;
void Try(int value, int tmp){
    for(int i=value;i>0;i--){
        a[x]=i;
        x++;
        if(tmp-i==0){
            cout << "(";
            for(int j=0;j<x-1;j++){
                cout << a[j] <<" ";
            }
            cout << a[x-1] << ") ";
        }else
            if(tmp-i>0)
                Try(i,tmp-i);
        x--;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        Try(n,n);
        cout << endl;
    }
    return 0;
}