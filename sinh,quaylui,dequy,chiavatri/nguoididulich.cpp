/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,false,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int n,a[100],b[100],c[100][100],dem=0;
int fort,cmin,can,x[100];

/**********DTL**********/

int MinMaxtrix(){
    int Min=INT_MAX;
    FOR(i,1,n){
        FOR(j,1,n){
            if(i!=j && Min > c[i][j]){
                Min=c[i][j];
            }
        }
    }
    return Min;
}

void init(){
    cin >> n;
    FOR(i,1,n){
        FOR(j,1,n){
            cin >> c[i][j];
        }
    }
    cmin=MinMaxtrix();
    fort=INT_MAX;
    can=0;
    x[1]=1;
    FOR(i,1,n){
        b[i]=1;
    }
}

void update(){
    int sum;
    sum=can+c[x[n]][x[1]];
    if(fort>sum){
        fort=sum;
    }
}

void Try(int i){
    FOR(j,2,n){
        if(b[j]){
            b[j]=0;
            x[i]=j;
            can+=c[x[i-1]][x[i]];
            if(i==n){
                update();
            }else if(can+(n-i+1)*cmin < fort){
                dem++;
                Try(i+1);
            }
            b[j]=1;
            can-=c[x[i-1]][x[i]];
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    init();
    Try(2);
    cout << fort;

    return 0;
}