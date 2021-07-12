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
#define FORX(i,n,m) for(int i=n;i*i<=m;i++)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int a[1005]={0},p,n,s;
int x,result[1005],tmp;

/**********DTL**********/

void Output(){
    FOR(i,1,tmp-1){
        cout << result[i] << " ";
        if(i%n==0) cout << endl;
    }
}

void wtr(){
    FOR(i,1,n){
        result[tmp]=a[i];
        tmp++;
    }
}

bool checksum(){
    int temp=0;
    FOR(i,1,n){
        temp+=a[i];
    }
    if(temp==s) return true;
    return false;
}

bool Prime(int n){
    if(n<2) return false;
    if(n==2) return true;
    FORX(i,2,n){
        if(n%i==0) return false;
    }
    return true;
}

void Try(int i){
    FOR(j,a[i-1]+1,s-n+i){
        while(!Prime(j) && j<=s-n+i) j++;
        a[i]=j;
        if(i==n){
            if(checksum()){
                x++;
                wtr();
            }
        }else Try(i+1);
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        x=0;
        tmp=1;
        cin >> n >> p >> s;
        a[0]=p-1;
        Try(1);
        cout << x << endl;
        if(x) Output();
    }
    return 0;
}