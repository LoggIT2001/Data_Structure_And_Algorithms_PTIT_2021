#include<iostream>
#include<cstring>
using namespace std;

char x[20];
int i;
void genNext(){
    i=strlen(x)-1;
    while(i>=0 && x[i]=='0'){
        x[i]='1';
        i--;
    }
    if(i>=0){
        x[i]='0';
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> x;
        genNext();
        cout << x << endl;
    }
    return 0;
}