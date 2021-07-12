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
#define reset(A) memset(A,-1,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

struct canh{
    int dau,cuoi,ts;
};
int a[1000],n,m;

/**********DTL**********/

bool cmp(canh tmp1, canh tmp2){
    return tmp1.ts<tmp2.ts;
}

int Find(int x){
    if(a[x]==-1){
        return x;
    }
    return Find(a[x]);
}

void Union(int x, int y){
    int xset = Find(x);
    int yset = Find(y);
    if(xset!=yset){
        a[xset]=yset;
    }
}

bool chuTrinh(vector<canh> vt){
    reset(a);
    FOR(i,0,vt.size()){
        int d=Find(vt[i].dau);
        int c=Find(vt[i].cuoi);
        if(d==c){
            return true;
        }
        Union(d,c);
    }
    return false;
}

void Kruskal(canh dt[]){
    vector<canh> kc;
    sort(dt,dt+m,cmp);
    int kq=dt[0].ts;
    kc.push_back(dt[0]);
    FOR(i,1,m){
        kc.push_back(dt[i]);
        if(!chuTrinh(kc)){
            kq+=dt[i].ts;
        }else{
            kc.pop_back();
            continue;
        }
        if(kc.size()>n-1){
            break;
        }
    }
    cout << kq << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        canh dt[m];
        FOR(i,0,m){
            cin >> dt[i].dau >> dt[i].cuoi >> dt[i].ts;
        }
        Kruskal(dt);
    }
    return 0;
}