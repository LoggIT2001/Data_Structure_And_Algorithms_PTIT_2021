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

/**********DTL**********/

int solution(string s){
    int n=s.size();
    int L[n+5][n+5];
    FOR(i,0,n){
        L[i][i]=1;
    }
    FOR(k,2,n+1){
        FOR(i,0,n-k+1){
            int j=i+k-1;
            if(s[i]==s[j] && k==2){
                L[i][j]=2;
            }else if(s[i]==s[j]){
                L[i][j]=L[i+1][j-1]+2;
            }else{
                L[i][j]=max(L[i+1][j],L[i][j-1]);
            }
        }
    }
    return L[0][n-1];
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int n=s.size();
        cout << n-solution(s) << endl;
    }
    return 0;
}