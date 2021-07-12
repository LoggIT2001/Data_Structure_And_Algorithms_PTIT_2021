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
int const MAXI=1e7;

/**********DTL**********/

int n,m;
int a[1005][1005];

/**********DTL**********/

int kt(){
    int d[n+1];
    FOR(i,1,n){
        d[i]=MAXI;
    }
    d[1]=0;
    FOR(i,2,n){
        FOR(j,1,n){
            FOR(k,1,n){
                if(d[k] > d[j]+a[j][k]){
                    d[k]=d[j]+a[j][k];
                }
            }
        }
    }
    int check=0;
    FOR(i,1,n){
        FOR(j,1,n){
            int x=d[i]+a[i][j];
            if(d[j]>x){
                check=1;
                break;
            }
        }
    }
    return check;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        FOR(i,0,n){
            FOR(j,0,n){
                a[i][j]=MAXI;
            }
        }
        FOR(i,1,m){
            int u,v,k;
            cin >> u >> v >> k;
            a[u][v]=k;
        }
        cout << kt() << endl;
    }
    return 0;
}