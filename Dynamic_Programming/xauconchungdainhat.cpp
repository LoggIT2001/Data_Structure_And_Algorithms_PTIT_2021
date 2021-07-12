#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1000][1000];
int output(string s1, string s2){
    int res=0;
    int n=s1.length(), m=s2.length();
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
            res=max(res,a[i][j]);
        }
    }
    return res;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        string s1,s2;
        cin >> s1 >> s2;
        cout << output << endl;
    }
    return 0;
}