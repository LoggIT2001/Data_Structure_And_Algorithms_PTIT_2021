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

void solution(string s){
    stack<int> st;
    int x=1;
    int n=s.size();
    FOR(i,0,n){
        if(s[i]=='('){
            st.push(x);
            x++;
        }else if(s[i]==')'){
            if(!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    //CIG;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        //getline(cin,s);
        //cout << s ;
        solution(s);
        cout << endl;
    }
    return 0;
}