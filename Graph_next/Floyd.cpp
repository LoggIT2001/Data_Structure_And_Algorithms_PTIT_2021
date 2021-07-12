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
int const MAXI =1e9;

/**********DTL**********/

int dp[1005][1005], ce[1005][1005];
int n,m,t;

/**********DTL**********/

void Floyd(){
    FOR(x,1,n+1){
        FOR(y,1,n+1){
            FOR(z,1,n+1){
                if(dp[y][z]>(dp[y][x]+dp[x][z])){
                    dp[y][z]=dp[y][x]+dp[x][z];
                    ce[y][z]=ce[x][z];
                }
            }
        }
    }
}

void init(){
    cin >> n >> m;
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            if(i==j){
                dp[i][j]=0;
            }else{
                dp[i][j]=MAXI;
            }
            ce[i][j]=i;
        }
    }
    FOR(i,1,m+1){
        int p1,p2,p3;
        cin >> p1 >> p2 >> p3;
        dp[p1][p2]=p3;
        dp[p2][p1]=p3;
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    init();
    Floyd();
    cin >> t;
    while(t--){
       int u,v;
       cin >> u >> v;
       vector<int> vt;
       int tmp=v;
       vt.push_back(tmp);
       while(tmp!=u){
           tmp=ce[u][tmp];
           vt.push_back(tmp);
       }
       cout << dp[u][v] << endl;
    }
    return 0;
}