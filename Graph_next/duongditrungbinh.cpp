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
ll const MAXL=1e9;

/**********DTL**********/

int n,m;
int a[105][105];
int connected[105];

/**********DTL**********/

void Floyd(){
    FOR(i,1,n){
        FOR(j,1,n){
            FOR(k,1,n){
                if(a[j][k] > a[j][i] + a[i][k]){
                    a[j][k]=a[j][i]+a[i][k];
                }
            }
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        reset(connected);
        cin >> n >> m;
        FOR(i,1,n){
            FOR(j,1,n){
                if(i==j){
                    a[i][j]=0;
                }else{
                    a[i][j]=MAXL;
                }
            }
        }
        FOR(i,1,m){
            int u,v;
            cin >> u >> v;
            connected[u]=connected[v]=1;
            a[u][v]=1;
        }
        Floyd();
        int ans=0,num=0;
        FOR(i,1,n){
            FOR(j,1,n){
                if(i!=j && connected[j] && a[i][j]<MAXL){
                    ans+=a[i][j];
                    num++;
                }
            }
        }
        cout << fixed << setprecision(2) << (double)ans/num << endl;
    }
    return 0;
}