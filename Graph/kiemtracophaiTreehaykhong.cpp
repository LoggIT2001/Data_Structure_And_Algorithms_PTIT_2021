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
#define reset(A) memset(A,false,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

/**********DTL**********/

void KTTree(queue<int> qe[], int n){
    queue<int> que;
    bool chuaxet[1005];
    reset(chuaxet);
    que.push(1);
    chuaxet[1]=true;
    int count=1;
    while(!que.empty()){
        int front=que.front();
        que.pop();
        while(!qe[front].empty()){
            int tmp=qe[front].front();
            qe[front].pop();
            if(!chuaxet[tmp]){
                que.push(tmp);
                chuaxet[tmp]=true;
                count++;
            }
        }
    }
    if(count != n){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        queue<int> qe[n+5];
        FOR(i,1,n){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            qe[pt1].push(pt2);
            qe[pt2].push(pt1);
        }
        KTTree(qe,n);
    }
    return 0;
}