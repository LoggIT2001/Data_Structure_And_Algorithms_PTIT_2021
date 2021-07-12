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

vector<int> vt1[1005];
vector<int> vt2[1005];

/**********DTL**********/

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int V,E;
        FOR(i,0,1005){
            vt1[i].clear();
            vt2[i].clear();
        }
        cin >> V >> E;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt1[pt1].push_back(pt2);
            vt2[pt2].push_back(pt1);
        }
        int count=0;
        FOR(i,0,V){
            if(vt1[i].size()==vt2[i].size()){
                count++;
            }
        }
        if(count==V) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}