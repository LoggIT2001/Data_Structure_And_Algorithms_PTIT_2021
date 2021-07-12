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
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int a,b,c,d,e,res;
int arr[6],mark[6],pre[6];
int opera[4];

/**********DTL**********/

bool testExpression(){
    int tmp;
    switch(opera[1]){
        case 1: {
            tmp=pre[1]+pre[2];
            break;
        }
        case 2: {
            tmp=pre[1]-pre[2];
            break;
        }
        case 3: {
            tmp=pre[1]*pre[2];
            break;
        }
    }
    FOR(i,2,4){
        switch(opera[i]){
            case 1: {
                tmp+=pre[i+1];
                break;
            }
            case 2: {
                tmp-=pre[i+1];
                break;
            }
            case 3: {
                tmp*=pre[i+1];
                break;
            }
        }
    }
    return tmp==23;
}

void MakeExpression(int i){
    if(res) return;
    FOR(j,1,3){
        opera[i]=j;
        if(i==4){
            if(testExpression()){
                res++;
                if(res){
                    return;
                }
            }
        }else{
            MakeExpression(i+1);
        }
    }
}

void MakePermutation(){
    FOR(i,1,5){
        switch(arr[i]){
            case 1: {
                pre[i]=a;
                break;
            }
            case 2: {
                pre[i]=b;
                break;
            }
            case 3: {
                pre[i]=c;
                break;
            }
            case 4: {
                pre[i]=d;
                break;
            }
            case 5: {
                pre[i]=e;
                break;
            }
        }
    }
}

void Premu(int i){
    if(res) return;
    FOR(j,1,5){
        if(res) return;
        if(!mark[j]){
            arr[i]=j;
            mark[j]=1;
            if(i==5){
                MakePermutation();
                MakeExpression(1);
            }else{
                Premu(i+1);
            }
            mark[j]=0;
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        res=0;
        cin >> a >> b >> c >> d >> e;
        Premu(1);
        if(res){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}