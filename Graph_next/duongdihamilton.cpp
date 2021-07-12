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

int V,E,check;
vector<int> vt[20];
bool chuaxet[20];

/**********DTL**********/

void Hamilton(int u, int dem){
    if(dem==V){
        check=1;
        return;
    }
    FOR(i,0,vt[u].size()){
        int y=vt[u][i];
        if(chuaxet[y]){
            chuaxet[y]=false;
            Hamilton(y,dem+1);
            chuaxet[y]=true;
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,20){
            vt[i].clear();
        }
        cin >> V >> E;
        FOR(i,1,E+1){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
            vt[pt2].push_back(pt1);
        }
        reset(chuaxet);
        check=0;
        FOR(i,1,V+1){
            chuaxet[i]=false;
            Hamilton(i,1);
            chuaxet[i]=true;
        }
        cout << check << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, check;
vector<int> vec[20];
bool chuaxet[20];

void halmiton(int u, int dem) {
    if (dem == n) {
        check = 1;
        return;
    }

    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i];
        if (chuaxet[v]) {
            chuaxet[v] = false;
            halmiton(v, dem + 1);
            chuaxet[v] = true;
        }
    }
}

int main() {
    int t, i, u, v;
    cin >> t;
    while (t--) {
        for (i = 0; i < 20; i++)
            vec[i].clear();
        
        memset(chuaxet, true, sizeof(chuaxet));
        cin >> n >> m;
        for (i = 1; i <= m; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        check = 0;
        for (i = 1; i <= n; i++) {
            chuaxet[i] = false;
            halmiton(i, 1);
            chuaxet[i] = true;
        }

        cout << check << '\n';
    }
    return 0;
}
*/