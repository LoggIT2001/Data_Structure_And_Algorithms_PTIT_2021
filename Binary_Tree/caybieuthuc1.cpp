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
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

struct Node{
    char data;
    Node *l, *r;
};

/**********DTL**********/

bool toantu(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%');
}

Node *node(char c){
    Node *p=new Node;
    p->l =p->r =NULL;
    p->data=c;
    return p;
}

void Duyet(Node *root){ 
    if(root!=NULL){
        Duyet(root->l);
        cout << root->data;
        Duyet(root->r);
    }
}

Node *Tree(string hauto){
    stack<Node*> st;
    Node *t,*t1,*t2;
    FOR(i,0,hauto.length()){
        if(!toantu(hauto[i])){
            t=node(hauto[i]);
            st.push(t);
        }else{
            t=node(hauto[i]);
            t1=st.top(); st.pop();
            t2=st.top(); st.pop();
            t->r=t1;
            t->l=t2;
            st.push(t);
        }
    }
    return st.top();
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        string hauto;
        cin >> hauto;
        Node *t=Tree(hauto);
        Duyet(t);
        cout << endl;
    }
    return 0;
}