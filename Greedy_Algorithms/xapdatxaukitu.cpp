#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        int d;
        cin >> d >> s;
        int a[100];
        int Max=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
            if(a[s[i]] > Max) Max=a[s[i]];
        }
        if((Max-1)*(d-1) <= s.size()-Max) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}