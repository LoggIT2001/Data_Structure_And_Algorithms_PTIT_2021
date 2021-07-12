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
#define reset(A) memset(A,true,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

bool chuaxet[10005];
vector<int> vt[10005];
int A[10005][2];
int sc=0,V,E;

/**********DTL**********/

void DFS(int u){
    chuaxet[u]=false;
    if(sc==E-1){
        return;
    }
    FOR(i,0,vt[u].size()){
        int y=vt[u][i];
        if(chuaxet[y]){
            sc++;
            A[sc][1]=u;
            A[sc][2]=y;
            if(sc==E-1){
                return;
            }else{
                DFS(y);
            }
        }
    }
}

void result(){
    FOR(i,1,sc+1){
        FOR(j,1,3){
            cout << A[i][j] <<" ";
        }
        cout << endl;
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int u;
        sc=0;
        FOR(i,0,10005){
            vt[i].clear();
        }
        cin >> V >> E >> u;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].pb(pt2);
            vt[pt2].pb(pt1);
        }
        reset(chuaxet);
        DFS(u);
        cout << sc << endl;
        if(sc<(E-1)){
            cout << "-1" << endl;
        }else{
            result();
        }
    }
    return 0;
}