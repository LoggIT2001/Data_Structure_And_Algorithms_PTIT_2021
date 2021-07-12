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

void Solution(int a[], int b[], int n){
    stack<int> st;
    st.push(0);
    b[0]=1;
    FOR(i,1,n){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        if(st.empty()){
            b[i]=i+1;
        }else{
            b[i]=i-st.top();
        }
        st.push(i);
    }
    FOR(i,0,n){
        cout << b[i] << " ";
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
        int a[n+5],b[n+5];
        FOR(i,0,n){
            cin >> a[i];
        }
        Solution(a,b,n);
    }
    return 0;
}