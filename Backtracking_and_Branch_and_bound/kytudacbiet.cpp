/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define pb push_back
#define pa pair<int,int>
#define f first
#define s second
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

string s;
ll n;

/**********DTL**********/

char Solution(ll k, ll total){
    if(k<s.length()){
        return s[k];
    }
    if(k<total/2){
        return Solution(k,total/2);
    }else{
        return Solution((k-1)%(total/2),total/2);
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        cin >> s >> n;
        ll i=s.length();
        while(i<n){
            i*=2;
        }
        cout << Solution(n-1,i) << endl;
    }
    return 0;
}