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
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

/**********DTL**********/

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int> vt(n);
        for(auto &x:vt) cin>>x;
        map<int,bool> mp;
        mp[vt[0]]=true;
        int isBST=1;
        FOR(i,1,n){
            if(vt[i]<vt[i-1]){
                isBST=0;
                break;
            }
            if(mp[vt[i]]==true){
                isBST=0;
                break;
            }
            mp[vt[i]]=true;
        }
        cout << isBST << endl;
    }
    return 0;
}