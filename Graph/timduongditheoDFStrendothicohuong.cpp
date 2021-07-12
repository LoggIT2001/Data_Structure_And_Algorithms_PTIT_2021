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
#define reset(A) memset(A,true,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)
#define resett(A) memset(A,0,sizeof(A));

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

bool chuaxet[1005];
int truoc[1005];
vector<int> vt[1005];

/**********DTL**********/

void DFS(int u){
    reset(chuaxet);
    resett(truoc);
    stack<int> st;
    st.push(u);
    chuaxet[u]=false;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        FOR(i,0,vt[top].size()){
            int y=vt[top][i];
            if(chuaxet[y]){
                chuaxet[y]=false;
                st.push(top);
                st.push(y);
                truoc[y]=top;
                break;
            }
        }
    }
}

void DD(int s, int t){
    if(truoc[t]==0){
        cout << -1 << endl;
    }else{
        stack<int> st;
        st.push(t);
        int k=t;
        while(truoc[k]!=s){
            st.push(truoc[k]);
            k=truoc[k];
        }
        st.push(s);
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
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
        int V,E,s,t;
        cin >> V >> E >> s >> t;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
        }
        DFS(s);
        DD(s,t);
    }
    return 0;
}