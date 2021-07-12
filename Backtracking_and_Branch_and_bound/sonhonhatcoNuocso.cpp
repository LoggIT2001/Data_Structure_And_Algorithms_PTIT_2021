/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
long long const Maximum=LONG_LONG_MAX;

/**********DTL**********/

ll p[20]={2,3,5,7,11,13,17,19,23,29};
ll n,res=Maximum;

/**********DTL**********/

void Back_Track(int i, ll a, int b){
    if(b>n) return;
    if(b==n){
        res=min(res,a);
    }
    for(int j=1;;j++){
        if(a*p[i]>res){
            break;
        }
        a*=p[i];
        if(a<0){
            break;
        }
        Back_Track(i+1,a,b*(j+1));
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        res=Maximum;
        cin >> n;
        Back_Track(0,1,1);
        cout << res << endl;
    }
    return 0;
}