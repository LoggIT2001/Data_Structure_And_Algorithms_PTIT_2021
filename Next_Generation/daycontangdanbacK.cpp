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

int n,k,countt=0,ok=1;
int a[101],b[101];

/**********DTL**********/

void Init(){
    cin >> n >> k;
    FOR(i,1,n){
        cin >> b[i];
        a[i]=i;
    }
    ok=0;
}

void Result(){
    int check=0;
    FOR(i,1,k-1){
        if(b[a[i]]>b[a[i+1]]) check=1;
    }
    if(check==0) countt++; 
}

void GenNext(){
    int i=k;
    while(i>0 && a[i]==n-k+i){
        i--;
    }
    if(i==0) ok=1;
    else{
        a[i]++;
        FOR(j,i+1,k){
            a[j]=a[i]+j-i;
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        Init();
        while(!ok){
            Result();
            GenNext();
        }
        cout << countt;
    //}
    return 0;
}

