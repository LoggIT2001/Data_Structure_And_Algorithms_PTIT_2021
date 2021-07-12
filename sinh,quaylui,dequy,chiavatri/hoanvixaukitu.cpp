#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

string s;
int a[100];
bool chuaxet[100];
void result(){
    for(int i=1;i<=s.size();i++){
        cout << s[a[i]];
    }
    cout << " ";
}
void Try(int i){
    for(int j=0;j<s.size();j++){
        if(chuaxet[j]){
            a[i]=j;
            chuaxet[j]=false;
            if(i==s.size())
                result();
            else
                Try(i+1);
            chuaxet[j]=true;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        memset(chuaxet,true,sizeof(chuaxet));
        sort(s.begin(),s.end());
        Try(1);
        cout << endl;
    }
    return 0;
}