/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define pb push_back
#define pa pair<double, double>
#define f first
#define s second
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,-1,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

double co[105][105];
int n;
double ans=0;
bool mark[105];

struct edg{
    int u,v;
    double co;
    edg() {}
    edg(int U, int V, double c){
        u=U;
        v=V;
        co=c;
    }
};

vector<edg> vt;
int par[105];

/**********DTL**********/

double disk(pa a, pa b){
    return sqrt((a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s));
}

bool cmp(edg u, edg v){
    return u.co < v.co;
}

int root(int x){
    while(par[x]>0){
        x=par[x];
    }
    return x;
}

void merge(int x, int y){
    x=root(x);
    y=root(y);
    if(x==y){
        return;
    }
    if(par[x]<par[y]){
        par[x]+=par[y];
        par[y]=x;
    }else{
        par[y]+=par[x];
        par[x]=y;
    }
}

void kruskal(){
    sort(vt.begin(),vt.end(),cmp);
    FOR(i,0,vt.size()){
        int u=root(vt[i].u);
        int v=root(vt[i].v);
        if(u!=v){
            merge(u,v);
            ans+=vt[i].co;
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        reset(par);
        cin >> n;
        vector<pa> a(n+5);
        FOR(i,1,n+1){
            cin >> a[i].f >> a[i].s;
        }
        vt.clear();
        FOR(i,1,n){
            FOR(j,i+1,n+1){
                co[i][j]=disk(a[i],a[j]);
                vt.pb(edg(i,j,co[i][j]));
            }
        }
        ans=0;
        kruskal();
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}