#include<iostream>
#include<cstring>
using namespace std;

void genNext(char s[]){
    int i=strlen(s)-1;
    while(i>=0 && s[i]=='1'){
        s[i]='0';
        i--;
    }
    if(i>=0) s[i]='1';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        char s[100];
        cin >> s;
        genNext(s);
        cout << s << endl;
    }
    return 0;
}