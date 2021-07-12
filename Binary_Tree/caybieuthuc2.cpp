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
    string data;
    Node *l,*r;
    Node(string x){
        data=x;
        l=r=NULL;
    }
};

/**********DTL**********/

ll toNum(string s){
    ll ans=0;
    if(s[0]=='-'){
        s.erase(0,1);
        FOR(i,0,s.length()){
            ans=ans*10+(s[i]-'0');
        }
        return -ans;
    }
    FOR(i,0,s.length()){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

ll evalTree(Node *root){
    if(root->l==NULL && root->r==NULL){
        return toNum(root->data);
    }
    if(root->data=="+"){
        return evalTree(root->l)+evalTree(root->r);
    }
    if(root->data=="-"){
        return evalTree(root->l)-evalTree(root->r);
    }
    if(root->data=="*"){
        return evalTree(root->l)*evalTree(root->r);
    }
    return evalTree(root->l)/evalTree(root->r);
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        string s[n];
        FOR(i,0,n){
            cin >> s[i];
        }
        int p=0;
        Node *root= new Node(s[p]);
        queue<Node *> qe;
        qe.push(root);
        p=1;
        while(!qe.empty()){
            Node *first=qe.front();
            qe.pop();
            Node *left,*right;
            if(p!=n){
                left=new Node(s[p]);
                first->l=left;
                p++;
                qe.push(left);
            }else{
                first->l=NULL;
            }
            if(p!=n){
                right=new Node(s[p]);
                first->r=right;
                p++;
                qe.push(right);
            }else{
                first->r=NULL;
            }
        }
        cout << evalTree(root) << endl;
    }
    return 0;
}