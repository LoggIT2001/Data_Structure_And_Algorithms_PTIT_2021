/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define pb push_back
#define pa pair<int,int>
#define f first
#define s second
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int n,w,fopt;
int a[101],c[101],xopt[101],x[101];

/**********DTL**********/

void Init(){
    cin >> n >> w;
    FOR(i,1,n){
        cin >> c[i];
    }
    FOR(i,1,n){
        cin >> a[i];
    }
    fopt=0;
}

bool CheckWeight(){
    int sum=0;
    FOR(i,1,n){
        sum+=x[i]*a[i];
    }
    if(sum>w) return false;
    return true;
}

int TotalValue(){
    int weight=0;
    FOR(i,1,n){
        weight+=x[i]*c[i];
    }
    return weight;
}

void Update(int value){
    if(fopt<value){
        fopt=value;
        FOR(i,1,n){
            xopt[i]=x[i];
        }
    }
}

void Try(int i){
    FOR(j,0,1){
        x[i]=j;
        if(i==n){
            if(CheckWeight()){
                Update(TotalValue());
            }
        }else{
            Try(i+1);
        }
    }
}

void Result(){
    cout << fopt << endl;
    FOR(i,1,n){
        cout << xopt[i] << " ";
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        Init();
        Try(1);
        Result();
    //}
    return 0;
}
