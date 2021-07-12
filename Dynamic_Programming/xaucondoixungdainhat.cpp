#include<bits/stdc++.h>
using namespace std;

int F[1001][1001];
int result(string s){
    int k,res=1;
    memset(F,0,sizeof(F));
    for(int i=0;i<s.size();i++) F[i][i]=1;
    for(int i=1;i<s.size();i++){
        for(int j=0;j<s.size()-i;j++){
            k=i+j;
            if(s[j]==s[k] && i>1) F[j][k]=F[j+1][k-1];
            else if(s[j]==s[k] && i==1) F[j][k]=1;
            else F[j][k]=0;
            if(F[j][k]) res=max(res,k-j+1);
        }
    }
    return res;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << result(s) << endl;
    }
    return 0;
}