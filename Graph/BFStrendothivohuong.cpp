#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

vector<int> Ke[1005];
bool chuaxet[1005];

void BFS(int u){
    queue<int> qe;
    qe.push(u);
    chuaxet[u]=true;
    while(!qe.empty()){
        int top=qe.front();
        cout << top << " ";
        qe.pop();
        chuaxet[top]=true;
        for(int i=0;i<Ke[top].size();i++){
            if(!chuaxet[Ke[top][i]]){
                chuaxet[Ke[top][i]]=true;
                qe.push(Ke[top][i]);
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
        int V,E,u;
        cin >> V >> E >> u;
        for(int i=0;i<1001;i++){
            Ke[i].clear();
        }
        memset(chuaxet,false,sizeof(chuaxet));
        for(int i=1;i<=E;i++){
            int x,y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        BFS(u);
        cout << endl;
    }
    return 0;
}

/*****design by DTLong*****/