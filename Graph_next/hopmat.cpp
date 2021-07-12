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

int n,m,k;
vector<int> vt1;
vector<int> vt2[1005];
int dem[1005];
int check[1005];

/**********DTL**********/

void Read(){
    cin >> k >> n >> m;
    int ps;
    FOR(i,1,k+1){
        cin >> ps;
        vt1.push_back(ps);
    }
    FOR(i,1,m+1){
        int a,b;
        cin >> a >> b;
        vt2[a].push_back(b);
    }
    FOR(i,1,n+1){
        dem[1005]=0;
    }
}

void init(){
    FOR(i,1,n+1){
        check[i]=0;
    }
}

void Loang(int u){
    FOR(i,0,vt2[u].size()){
        int y=vt2[u][i];
        if(check[y]==0){
            check[y]=1;
            dem[y]++;
            Loang(y);
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        Read();
        FOR(i,0,vt1.size()){
            init();
            check[vt1[i]]=1;
            dem[vt1[i]]++;
            Loang(vt1[i]);
        }
        int result=0;
        FOR(i,1,n+1){
            if(dem[i]==k){
                result++;
            }
        }
        cout << result;
    //}
    return 0;
}