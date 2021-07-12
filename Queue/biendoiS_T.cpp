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

void Solution(int s, int t){
    int a[20005];
    FOR(i,0,20000){
        a[i]=INT_MAX;
    }
    a[s]=0;
    queue<int> qe;
    qe.push(s);
    while(a[t]==INT_MAX){
        int x=qe.front();
        qe.pop();
        if(x-1 > 0 && a[x-1]==INT_MAX){
            a[x-1]==min(a[x]+1,a[x-1]);
            qe.push(x-1);
        }
        if(x*2 < 20000 && a[x*2]==INT_MAX){
            a[x*2]=min(a[x]+1,a[x*2]);
            qe.push(x*2);
        }
    }
    cout << a[t] << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int s,t;
        cin >> s >> t;
        Solution(s,t);
    }
    return 0;
}