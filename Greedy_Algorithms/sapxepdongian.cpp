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
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

/**********DTL**********/

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        int n;
        cin >> n;
        int a[n+5];
        int b[n+5];
        reset(b);
        FOR(i,0,n){
            cin >> a[i];
        }
        FOR(i,0,n){
            b[a[i]]=b[a[i]-1]+1;
        }
        int m=0;
        FOR(i,0,n+1){
            m=max(m,b[i]);
        }
        cout << n-m << endl;
    //}
    return 0;
}