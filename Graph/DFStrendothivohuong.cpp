#include<bits/stdc++.h>
using namespace std;

int V,E,u;
vector<int> Ke[1005];
bool chuaxet[1005];
/*void init(){
    cin >> V >> E >> u;
    for(int i=0;i<E;i++){
        int a,b;
        cin >> a >> b;
        Ke[a].push_back(b);
        Ke[b].push_back(a);
    }
    for(int i=0;i<1001;i++){
        chuaxet[i]=false;
    }
    for(int i=0;i<1001;i++){
        Ke[i].clear();
    }
}
*/
void DFS(int x){
    chuaxet[x]=true;
    cout << x << " ";
    for(int i=0;i<Ke[x].size();i++){
        if(!chuaxet[Ke[x][i]]){
            DFS(Ke[x][i]);
        }
    }
}
int main(){
    int test;
    cin >> test;
    while(test--){
        //init();
        cin >> V >> E >> u;
        for(int i=0;i<1001;i++){
            Ke[i].clear();
        }
        memset(chuaxet,false,sizeof(chuaxet));
        for(int i=1;i<=E;i++){
            int a,b;
            cin >> a >> b;
            Ke[a].push_back(b);
            Ke[b].push_back(a);
        }
        DFS(u);
        cout << endl;
    }
    return 0;
}