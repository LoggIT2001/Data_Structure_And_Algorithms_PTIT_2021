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
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int V,E;
vector<int> vt[1005];

/**********DTL**********/

int check(){
    int count=0;
    FOR(i,1,V){
        if(vt[i].size()%2==1) count++;
    }
    if(count==0) return 2;
    if(count==2) return 1;
    return 0;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,1005){
            vt[i].clear();
        }
        cin >> V >> E;
        FOR(i,1,E){
            int pt1, pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
            vt[pt2].push_back(pt1);
        }
        cout << check() << endl;
    }
    return 0;
}