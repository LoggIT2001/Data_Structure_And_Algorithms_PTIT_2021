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
#define resett(A) memset(A,0,sizeof(A));

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

vector<int> vt[1005];
int V,E;
int color[1005];
bool chuaxet[1005];
bool check;

/**********DTL**********/

void DFS(int u, int t){
    chuaxet[u]=false;
    FOR(i,0,vt[u].size()){
        int y=vt[u][i];
        if(chuaxet[y]){
            if(color[y]==0){
                color[y]=3-color[u]; // lk so chieu cua y
            }
            DFS(y,u);
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,1005){
            vt[i].clear();
        }
        cin >> V >> E;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
            vt[pt2].push_back(pt1);
        }
        reset(chuaxet);
        resett(color);
        FOR(i,1,V+1){
            if(color[i]==0){
                color[i]=1;
                DFS(i,0);
            }
        }
        check=true;
        FOR(i,1,V+1){
            FOR(j,0,vt[i].size()){
                if(color[i]==color[vt[i][j]]){
                    check=false;
                }
            }
        }
        if(check){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}