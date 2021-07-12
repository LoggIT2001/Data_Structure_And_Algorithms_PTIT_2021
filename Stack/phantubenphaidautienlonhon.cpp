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

void solution(int n, int a[]){
    stack<int> st;
    int res[n+5];
    FORD(i,n-1,0){
        while(!st.empty() && (st.top() <= a[i])){
            st.pop();
        }
        if(st.empty()){
            res[i]=-1;
        }else{
            res[i]=st.top();
        }
        st.push(a[i]);
    }
    FOR(i,0,n){
        cout << res[i] << " ";
    }
    cout << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n+5];
        FOR(i,0,n){
            cin >> a[i];
        }
        solution(n,a);
    }
    return 0;
}