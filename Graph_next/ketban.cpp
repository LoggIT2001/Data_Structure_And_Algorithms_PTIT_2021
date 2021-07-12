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

class UFDS{
    private:
        vector<int> vt,rank,setSize;
        int numset;
    public:
        UFDS(int n){
            numset=n;
            rank.assign(n,0);
            vt.assign(n,0);
            FOR(i,0,n){
                vt[i]=i;
            }
            setSize.assign(n,1);
        }
        int findSet(int i){
            return (vt[i]==i)?i:vt[i]=findSet(vt[i]);
        }
        bool isSameSet(int i, int j){
            return findSet(i)==findSet(j);
        }
        void unionSet(int i, int j){
            if(!isSameSet(i,j)){
                int x=findSet(i);
                int y=findSet(j);
                if(rank[x]>rank[y]){
                    setSize[findSet(x)]+=setSize[findSet(y)];
                    vt[y]=x;
                }else{
                    setSize[findSet(y)]+=setSize[findSet(x)];
                    vt[x]=y;
                    if(rank[x]==rank[y]){
                        rank[y]++;
                    }
                }
                numset--;
            }
        }
        int sizeSet(int i){
            return setSize[findSet(i)];
        }
        int numDisjointset(){
            return numset;
        }
};

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        UFDS uf(n);
        int Max=1;
        FOR(i,1,m+1){
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            uf.unionSet(u,v);
            if(uf.sizeSet(u)>Max){
                Max=uf.sizeSet(u);
            }
        }
        cout << Max << endl;
    }
    return 0;
}