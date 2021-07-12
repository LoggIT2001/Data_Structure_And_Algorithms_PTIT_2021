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
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

struct Node{
    int data;
    Node *l, *r;
    Node(int x){
        data=x;
        l=r=NULL;
    }
};

/**********DTL**********/

void GetLeafSum(Node *root, bool dir, int &sum){
    if(root==NULL) return;
    if(dir==true && !root->l && !root->r){
        sum+=root->data;
    }
    GetLeafSum(root->l,true,sum);
    GetLeafSum(root->r,false,sum);
}

int LeftNodeSum(Node *root){
    int sum=0;
    bool direction=true;
    GetLeafSum(root,direction,sum);
    return sum;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        map<int, Node *> mp;
        int n;
        cin >> n;
        Node *root=NULL;
        Node *child;
        while(n--){
            Node *parent;
            int n1,n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(mp.find(n1)==mp.end()){
                parent= new Node(n1);
                mp[n1]=parent;
                if(root==NULL){
                    root=parent;
                }
            }else{
                parent=mp[n1];
            }
            child=new Node(n2);
            if(c=='L') parent->l=child;
            else parent->r=child;
            mp[n2]=child;
        }
        cout << LeftNodeSum(root) << endl;
    }
    return 0;
}