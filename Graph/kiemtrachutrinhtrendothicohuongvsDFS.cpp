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

vector<int> vt[1005];
int V,E;
bool chuaxet1[1005]; // kt trong stack hay k
bool chuaxet2[1005]; // kt tham dinh do hay chua

/**********DTL**********/

bool Solution(){
    reset(chuaxet1);
    reset(chuaxet2);
    stack<int> st;
    FOR(i,0,V){
        if(chuaxet2[i]){
            continue;
        }
        st.push(i);
        while(!st.empty()){
            int top=st.top();
            if(!chuaxet2[top]){
                chuaxet2[top]=true;
                chuaxet1[top]=true;
            }else{
                chuaxet1[top]=false;
                st.pop();
            }
            for(const auto &x : vt[top]){
                if(!chuaxet2[x]){
                    st.push(x);
                }else if(chuaxet1[x]){
                    return true;
                }
            }
        }
    }
    return false;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        FOR(i,0,1005){
            vt[i].clear();
        }
        cin >> V >> E;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
        }
        if(Solution()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}