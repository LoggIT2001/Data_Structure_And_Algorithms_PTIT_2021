#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        int n;
        cin >> s >> n;
        int len=s.size();
        while(n>len) len*=2;
        while(len>s.size()){
            if(n>len/2){
                n-=len/2;
                if(n>1) n-=1;
                else n=len/2;
            }
            len/=2;
        }
        cout << s[n-1] << endl; 
    }
    return 0;
}