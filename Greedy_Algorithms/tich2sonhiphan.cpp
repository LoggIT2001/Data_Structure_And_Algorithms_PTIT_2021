#include<bits/stdc++.h>
using namespace std;

long long hex(string s){
    long long p=1,x=0;
    for(int i=s.size()-1,j=0;i>=0,j<s.size();i--,j++){
        x+=int(s[i]-'0')*p;
        p*=2;
    }
    return x;
}
void Mul2Binary(string s1, string s2){
    long long a=hex(s1);
    long long b=hex(s2);
    cout << a*b << endl;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        string s1,s2;
        cin >> s1 >> s2;
        Mul2Binary(s1,s2);
    }
    return 0;
}