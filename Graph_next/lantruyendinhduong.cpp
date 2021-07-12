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

vector<int> vt[200005];
int n;
int a[200005];
ll dp[200005],sub[200005];

/**********DTL**********/

void DFS(int u){
    dp[u]=a[u];
    sub[u]=1;
    for(auto &i : vt[u]){
        DFS(i);
        dp[u] += dp[i];
        sub[u] += sub[i];
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        cin >> n;
        FOR(i,2,n+1){
            int x;
            cin >> x;
            vt[x].push_back(i);
            a[i]=a[x]+1;
        }
        DFS(1);
        FOR(i,1,n+1){
            cout << dp[i]-sub[i]*(a[i]-1) << " ";
        }
    //}
    return 0;
}