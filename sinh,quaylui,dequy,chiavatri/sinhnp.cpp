#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
void init(){
    for(int i=1;i<=n;i++) a[i]=0;
}
bool display(){
    for(int i=1;i<=n;i++){
        if(a[i]!=1) return false;
    }
    return true;
}
bool kt(){
    for(int i=1;i<=n/2;i++){
        if(a[i]!=a[n-i+1]) return false;
    }
    return true;
}
void result(){
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void genNext(){
    int i=n;
    while(i>=0 && a[i]!=0){
        a[i]=0;
        i--;
    }
    if(i>0) a[i]=1;
}
int main(){
    cin >> n;
    init();
    while(!display()){
        if(kt()) result();
        genNext();
    }
    display();
    result();
    return 0;
}