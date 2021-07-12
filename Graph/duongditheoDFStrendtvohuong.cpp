/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define FOR(i,n,m) for(int i=(int)n;i<(int)m;i++)
#define FORD(i,n,m) for(int i=(int)m;i>=(int)n;i--)
#define reset(A) memset(A,false,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)
#define resett(A) memset(A,0,sizeof(A))

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
    chuaxet[u]=true;
    while(!st.empty()){
        int top=st.top(); st.pop();
        FOR(i,0,vt[top].size()){
            int y=vt[top][i];
            if(chuaxet[y]){
                chuaxet[y]=true;
                truoc[y]=top;
                st.push(top);
                st.push(y);
                break;
            }
        }
    }
}

void DuongDi(int s, int t){
    if(truoc[t]==0){
        cout << "-1";
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
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int V,E,s,t;
        FOR(i,0,1005){
            vt[i].clear();
        }
        cin >> V >> E >> s >> t;
        FOR(i,0,E){
            int pt1,pt2;
            cin >> pt1 >> pt2;
            vt[pt1].push_back(pt2);
            vt[pt2].push_back(pt1);
        }
        DFS(s);
        DuongDi(s,t);
        cout << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

bool chuaxet[MAX];
int truoc[MAX];
vector<int> arr[MAX];

void dfs(int u) {
    memset(chuaxet, true, sizeof(chuaxet));
    memset(truoc, 0, sizeof(truoc));

    int i, x, y;
    stack<int> st;
    st.push(u);
    chuaxet[u] = false;

    while (!st.empty()) {
        x = st.top(); st.pop();
        for (i = 0; i < arr[x].size(); i++) {
            y = arr[x][i];
            if (chuaxet[y]) {
                chuaxet[y] = false;
                truoc[y] = x;
                st.push(x);
                st.push(y);
                break;
            }
        }
    }
}

void duongDi(int s, int t) {
    if (truoc[t] == 0) {
        cout << "-1\n";
    }

    else {
        stack <int> st;
        st.push(t);
        int k = t;
        while (truoc[k] != s) {
            st.push(truoc[k]);
            k = truoc[k];
        }
        st.push(s);

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }

        cout << '\n';
    }
}

int main() {
    int test, v, e, s, t, tmp1, tmp2;
    cin >> test;
    while (test--) {
        for (int i = 0; i < MAX; i++)
            arr[i].clear();
        
        cin >> v >> e >> s >> t;

        for (int i = 0; i < e; i++) {
            cin >> tmp1 >> tmp2;
            arr[tmp1].push_back(tmp2);
            arr[tmp2].push_back(tmp1);
        }

        dfs(s);
        duongDi(s, t);
    }
    return 0;
}
*/