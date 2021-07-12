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

int V,E;
vector<int> vt[1005];

/**********DTL**********/

void DFS(int u){
    
}

void KTketnoi(){

}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,1,1005){
            vt[i].clear();
        }
        cin >> V >> E;
        FOR(i,0,E){
            int a,b;
            cin >> a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
        }
    }
    return 0;
}