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

int n,k;

/**********DTL**********/

void solution(){
    cin >> n >> k;
    vector<int> vt(n);
    for(int &i : vt){
        cin >> i;
        i%=k;
    }
    vector<int> v1(k,INT_MIN),v2(k);
    v1[0]=0;
    for(int i : vt){
        FOR(j,0,k){
            v2[j]=max(v1[j],v1[(j-i+k)%k]+1);
        }
        v1.swap(v2);
    }
    cout << v1[0] << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        solution();
    }
    return 0;
}