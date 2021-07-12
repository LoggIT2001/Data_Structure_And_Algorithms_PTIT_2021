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

bool chuaxet[1005];
vector<int> vt[1005];

/**********DTL**********/

void BFS(int u){
    queue<int> qe;
    qe.push(u);
    chuaxet[u]=false;
    while(!qe.empty()){
        int front=qe.front();
        qe.pop();
        FOR(i,0,vt[front].size()){
            int y=vt[front][i];
            if(chuaxet[y]){
                chuaxet[y]=false;
                qe.push(y);
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
        reset(chuaxet);
        FOR(i,0,1005){
            vt[i].clear();
        }
        int V,E;
        cin >> V >> E;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
            vt[pt2].push_back(pt1);
        }
        int count=0;
        FOR(i,1,V+1){
            if(chuaxet[i]){
                count++;
                BFS(i);
            }
        }
        cout << count << endl;
    }
    return 0;
}