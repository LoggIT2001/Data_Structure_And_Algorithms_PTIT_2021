/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)
#define FODX(i,n,m) for(ll i=n;i*i*i<=m;i++)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

string toString(ll n){
    string s="";
    while(n>0){
        s=char(n%10 + '0') + s;
        n/=10;
    }
    return s;
}

vector<string> pc(ll n){
    vector<string> vt;
    FODX(i,1,n){
        ll x=i*i*i;
        string st=toString(x);
        vt.push_back(st);
    }
    return vt;
}

string solution(ll n){
    vector<string> vtr = pc(n);
    string str =toString(n);
    FORD(i,vtr.size()-1,0){
        string x = vtr[i];
        ll index=0;
        FOR(j,0,str.size()){
            if(str[j]==x[index]){
                index++;
            }
        }
        if(index==x.size()){
            return x;
        }
    }
    return "-1";
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        string res=solution(n);
        cout << res << endl;
    }
    return 0;
}