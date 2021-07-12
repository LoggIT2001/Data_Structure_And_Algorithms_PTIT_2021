#include<bits/stdc++.h>
using namespace std;

int a[100],x=0,n;
vector<string> vt;

void Try(int value, int tmp){
    for(int i=value;i>0;i--){
        a[x]=i;
        x++;
        if(tmp-i==0){
            string s="";
            s+='(';
            for(int j=0;j<x-1;j++){
                s+=to_string(a[j]);
                s+=' ';
            }
            s+=to_string(a[x-1]);
            s+=')';
            vt.push_back(s);
        }else
            if(tmp-i>0)
                Try(i,tmp-i);
        x--;
    }
}
void result(){
    cout << vt.size() << endl;
    for(int i=0;i<vt.size();i++){
        cout << vt[i] << " ";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vt.clear();
        Try(n,n);
        result();
        cout << endl;
    }
    return 0;
}