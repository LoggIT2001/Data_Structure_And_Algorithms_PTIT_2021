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
int const MAXI=1e9;
typedef pair<int,int> pa;

/**********DTL**********/

int n,m,start;
int d[1005],parent[1005];
vector<pa> vt[1005];
priority_queue<pa, vector<pa>, greater<pa> > pq;

/**********DTL**********/

void Dijkstra(int u){
    FOR(i,1,n+1){
        d[i]=MAXI;
        parent[i]=-1;
    }
    d[u]=0;
    while(!pq.empty()){
        pq.pop();
    }
    pq.push({0,u});
    while(!pq.empty()){
        int tops=pq.top().second;
        pq.pop();
        FOR(i,0,vt[tops].size()){
            int y=vt[tops][i].second;
            int topf=vt[tops][i].first;
            if(d[y] > d[tops] + topf){
                d[y]=d[tops] + topf;
                parent[y]=tops;
                pq.push({d[y],y});
            }
        }
    }
    FOR(i,1,n+1){
        cout << d[i] << " ";
    }
    cout << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,n+1){
            vt[i].clear();
        }
        cin >> n >> m >> start;
        FOR(i,1,m+1){
            int p1,p2,p3;
            cin >> p1 >> p2 >> p3;
            vt[p1].push_back({p3,p2});
            vt[p2].push_back({p3,p1});
        }
        Dijkstra(start);
    }
    return 0;
}