#include<bits/stdc++.h>
using namespace std;
/*
void AequaB(string s1, string s2){
    while(s1.size()>s2.size()) s2='0'+s2;
    while(s1.size()<s2.size()) s1='0'+s1;
}
void Sum(string s1, string s2, int k){
    AequaB(s1,s2);
    int tmp=0;
    string s="";
    int len=s1.size();
    for(int i=len-1;i>=0;i--){
        int x=int(s1[i]-'0')+int(s2[i]-'0') +tmp;
        s=char(x%k +'0')+s;
        tmp=x/k;
    }
    if(tmp>0) s=char(tmp +'0')+s;
    cout << s << endl;
}
*/
int main(){
    int test;
    cin >>  test;
    while(test--){
        string s1,s2;
        int k;
        cin >> k >> s1 >> s2;
        //AequaB(s1,s2);
        //Sum(s1,s2,k);
        while(s1.size()>s2.size()) s2='0'+s2;
        while(s1.size()<s2.size()) s1='0'+s1;
        int tmp=0;
        string s="";
        int len=s1.size();
        for(int i=len-1;i>=0;i--){
            int x=int(s1[i]-'0')+int(s2[i]-'0') +tmp;
            s=char(x%k +'0')+s;
            tmp=x/k;
        }
        if(tmp>0) s=char(tmp +'0')+s;
        cout << s << endl;
    }
    return 0;
}