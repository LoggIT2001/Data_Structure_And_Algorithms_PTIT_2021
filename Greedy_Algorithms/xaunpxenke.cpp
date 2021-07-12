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

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int n;
vector<string> vt;

/**********DTL**********/

void sinh(){
    string s="";
    FOR(i,0,n){
        if(i%2==0){
            s+="0 ";
        }else{
            s+="1 ";
        }
    }
    vt.push_back(s);
    s="";
    FOR(i,0,n){
        if(i%2==0){
            s+="1 ";
        }else{
            s+="0 ";
        }
    }
    vt.push_back(s);
    FOR(i,0,vt.size()){
        cout << vt[i] << endl;
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        cin >> n;
        sinh();
    //}
    return 0;
}