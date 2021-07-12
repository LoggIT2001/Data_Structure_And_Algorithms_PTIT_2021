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

typedef pair<ll,ll> pa;
long long const mod=1e9+7;
int const MAX=1e5+5;
ll const MAXL=1e12;

/**********DTL**********/

vector<pa> graph[MAX];
priority_queue<pa, vector<pa>, greater<pa> > min_heap;
ll a[MAX],f[MAX];
int n,m;

/**********DTL**********/

void init(){
    FOR(i,1,n+1){
        a[i]=MAXL;
    }
    a[1]=0;
    f[1]=1;
}

void Dijkstra(int u){
    min_heap.push(make_pair(0,u));
    while(!min_heap.empty()){
        ll topf=min_heap.top().first;
        ll tops=min_heap.top().second;
        min_heap.pop();
        FOR(i,0,graph[tops].size()){
            int y=graph[tops][i].first;
            if(a[y]==topf + graph[tops][i].second){
                f[y]+=f[tops];
                continue;
            }
            if(a[y] > topf + graph[tops][i].second){
                a[y]=topf + graph[tops][i].second;
                f[y]=f[tops];
                min_heap.push(make_pair(a[y],y));
            }
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        cin >> n >> m;
        while(m--){
            int p1,p2,p3;
            cin >> p1 >> p2 >> p3;
            graph[p1].push_back(make_pair(p2,p3));
            graph[p2].push_back(make_pair(p1,p3));
        }
        init();
        Dijkstra(1);
        cout << a[n] << " " << f[n];
    //}
    return 0;
}