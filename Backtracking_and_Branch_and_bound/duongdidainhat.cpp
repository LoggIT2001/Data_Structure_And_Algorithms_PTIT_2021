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

int res=1,ans=-1,n,m;
int a[30][30];

/**********DTL**********/

void DFS(int u, int tmp){
    ans=max(ans,tmp);
    FOR(i,0,n){
        if(a[u][i]==1){
            a[u][i]=a[i][u]=0;
            DFS(i,tmp+1);
            a[u][i]=a[i][u]=1;
        }
    }
}

void init(){
    cin >> n >> m;
    reset(a);
    FOR(i,0,m){
        int u,v;
        cin >> u >> v;
        a[u][v]=a[v][u]=1;
    }
}

void result(){
    ans=-1;
    FOR(i,0,n){
        DFS(i,0);
    }
    cout << ans << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        init();
        result();
    }
    return 0;
}