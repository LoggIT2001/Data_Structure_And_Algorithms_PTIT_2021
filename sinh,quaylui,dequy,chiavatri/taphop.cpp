#include<bits/stdc++.h>
using namespace std;

int a[100];
int n,k,s;
bool check=false;
int res;
void init(){
    cin >> n >> k >> s;
    res=0;
    for(int i=1;i<=k;i++){
        a[i]=i;
    }
}
bool display(){
    for(int i=1;i<=k;i++){
        if(a[i]!=n-k+i) return false;
    }
    return true;
}
void Sum(){
    int sum=0;
    for(int i=1;i<=k;i++){
        sum+=a[i];
    }
    if(sum==k) res++;
}
void GenNext(){
    int i=k;
    while(i>=0 && a[i]==n-k+i) i--;
    if(i<=0) check=true;
    else{
        a[i]++;
        for(int j=1;j<=k;j++){
            a[j]=a[j-1]+1;
        }
    }
}
int main(){
    while(1){
        init();
        if(n==0 && k==0 && s==0) break;
        while(!display()){
            Sum();
            GenNext();
        }
        display();
        Sum();
        cout << res << endl;
    }
    return 0;
}