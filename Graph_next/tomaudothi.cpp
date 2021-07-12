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

vector<int> vt[15];
int color[15];
int V,E,M;

/**********DTL**********/

bool check(int u, int c){
    FOR(i,0,vt[u].size()){
        if(c==color[vt[u][i]]){
            return false;
        }
    }
    return true;
}

bool result(int u){
    if(u==V+1){
        return true;
    }
    FOR(i,1,M+1){
        if(check(u,i)){
            color[u]=i;
            if(result(u+1)){
                return true;
            }
            color[u]=0;
        }
    }
    return false;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,15){
            vt[i].clear();
        }
        cin >> V >> E >> M;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
            vt[pt2].push_back(pt1);
        }
        if(result(1)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> vec[15];
int color[15], n, m, d;

bool check(int u, int c) {
    for (int i = 0; i < vec[u].size(); i++)
        if (c == color[vec[u][i]])
            return false;
    
    return true;
}

bool result(int u) {
    if (u == n + 1)
        return true;

    for (int c = 1; c <= d; c++) {
        if (check(u, c)) {
            color[u] = c;
            if (result(u + 1))
                return true;
            
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int t, i, u, v;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 15; i++)
            vec[i].clear();
        
        memset(color, 0, sizeof(color));
        cin >> n >> m >> d;

        for (i = 1; i <= m; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        if (result(1))
            cout << "YES\n";
        
        else 
            cout << "NO\n"; 
    }
    return 0;
}
*/