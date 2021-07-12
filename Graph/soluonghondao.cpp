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
#define reset(A) memset(A,true,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={-1,1,-1,0,1,-1,0,1};
bool chuaxet[1005][1005];
int a[1005][1005];

/**********DTL**********/

void BFS(int u, int v){
    queue<pair<int,int> > qe;
    pair<int,int> p,pa;
    pa.first=u; pa.second=v;
    qe.push(pa);
    chuaxet[u][v]=false;
    while(!qe.empty()){
        p=qe.front(); qe.pop();
        FOR(i,0,8){
            int x=p.first + dx[i];
            int y=p.second + dy[i];
            if(chuaxet[x][y] && a[x][y]==1){
                chuaxet[x][y]=false;
                pa.first=x;
                pa.second=y;
                qe.push(pa);
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
        int n,m;
        cin >> n >> m;
        int count=0;
        reset(chuaxet);
        FOR(i,1,n+1){
            FOR(j,1,m+1){
                cin >> a[i][j];
            }
        }
        FOR(i,1,n+1){
            FOR(j,1,m+1){
               if(a[i][j]==1 && chuaxet[i][j]){
                   BFS(i,j);
                   count++;
               }
            }
        }
        cout << count << endl;
    }
    return 0;
}