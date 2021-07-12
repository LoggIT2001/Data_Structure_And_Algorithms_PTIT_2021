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
#define FOR(i,n,m) for(long long i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

vector<ll> vt1;
vector<ll> vt2;
ll n,l,r;

/**********DTL**********/

ll Power(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll p= Power(a,b>>1);
    if(b&1) return a*p*p;
    else return p*p;
}

void init(){
    cin >> n >> l >> r;
    vt1.clear();
}

void Solve(){
    while(n){
        vt1.pb(n);
        n>>=1;
    }
    int k=vt1.size()-1;
    int ans=0;
    FOR(i,l,r){
        if(i&1) ans++;
        else{
            ll val=i;
            while(val & (val-1)){
                int x=upper_bound(vt2.begin(),vt2.end(),val)-vt2.begin()-1;
                val-=vt2[x];
            }
            ans+=vt1[k-(lower_bound(vt2.begin(),vt2.end(),val)-vt2.begin())]&1; 
        }
    }
    cout << ans << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    FOR(i,0,49){
        vt2.pb(Power(2,i));
    }

    int test;
    cin >> test;
    while(test--){
        init();
        Solve();
    }
    return 0;
}