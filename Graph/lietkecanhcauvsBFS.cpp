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

int V,E;
vector<int> vt[1005];
vector<int> edglist[50000];
bool chuaxet[1005];

/**********DTL**********/

int TPLT(){
    int count=0;
    reset(chuaxet);
    FOR(i,1,V){
        if(chuaxet[i]){
            count++;
            queue<int> qe;
            qe.push(i);
            chuaxet[i]=true;
            while(!qe.empty()){
                int x=qe.front();
                qe.pop();
                FOR(j,0,vt[x].size()-1){
                    int y=vt[x][j];
                    if(chuaxet[y]){
                        chuaxet[y]=true;
                        qe.push(y);
                    }
                }
            }
        }
    }
    return count;
}

int DD(int d1, int d2){
    int res=0;
    reset(chuaxet);
    FOR(i,1,V){
        if(chuaxet[i]){
            res++;
            queue<int> qe;
            qe.push(i);
            chuaxet[i]=true;
            while(!qe.empty()){
                int x=qe.front();
                qe.pop();
                FOR(j,0,vt[x].size()-1){
                    int y=vt[x][j];
                    if((x==d1 && y==d2) || (x==d2 && y==d1) || chuaxet[y]==true){
                        continue;
                    }else{
                        chuaxet[y]=false;
                        qe.push(x);
                        qe.push(y);
                    }
                }
            }
        }
    }
    return res;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,1005){
            vt[i].clear();
            edglist[i].clear();
        }
        cin >> V >> E;
        FOR(i,0,E-1){
            int tmp1,tmp2;
            cin >> tmp1 >> tmp2;
            vt[tmp1].push_back(tmp2);
            vt[tmp2].push_back(tmp1);
            edglist[i].push_back(tmp1);
            edglist[i].push_back(tmp2);
        }
        FOR(i,0,E-1){
            if(DD(edglist[i][0] , edglist[i][1]) > TPLT()){
                cout << edglist[i][0] << " " << edglist[i][1] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}