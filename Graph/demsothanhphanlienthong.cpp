#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

vector<int> ke[1005];
bool chuaxet[1001];

void Matranke(int E){
    for(int i=1;i<=E;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u){
    chuaxet[u]=true;
    for(int i=0;i<ke[u].size();i++){
        if(!chuaxet[ke[u][i]]){
            DFS(ke[u][i]);
        }
    }
}

void TPLT(int V){
    int res=0;
    for(int i=1;i<=V;i++){
        if(!chuaxet[i]){
            res++;
            DFS(i);
        }
    }
    cout << res;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int V,E;
        cin >> V >> E;
        for(int i=0;i<1001;i++){
            ke[i].clear();
        }
        memset(chuaxet,false,sizeof(chuaxet));
        Matranke(E);
        TPLT(V);
    }
    return 0;
}