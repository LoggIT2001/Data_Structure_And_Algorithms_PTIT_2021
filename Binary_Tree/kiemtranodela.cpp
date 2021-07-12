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

int height(struct Node *root){
    if(!root) return 0;
    return (1+max(height(root->l),height(root->r)));
}

bool check(Node *root, int level, int h){
    if(!root) return true;
    if(!root->l && !root->r && level<h) return false;
    return check(root->l,level+1,h) && check(root->r,level+1,h);
}

bool kt(Node *root){
    int h=height(root);
    return check(root,1,h);
}

void MakeNode(Node *root, int n1, int n2, char c){
    switch(c){
        case 'L': root->l=new Node(n2);
                break;
        case 'R': root->r=new Node(n2); 
                break;       
    }
}

void Insert(Node *root, int n1, int n2, char c){
    if(root==NULL) return;
    if(root->data==n1){
        MakeNode(root,n1,n2,c);
    }else{
        Insert(root->l,n1,n2,c);
        Insert(root->r,n1,n2,c);
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        Node *root=NULL;
        while(n--){
            int n1,n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(root==NULL){
                root=new Node(n1);
                MakeNode(root,n1,n2,c);
            }else{
                Insert(root,n1,n2,c);
            }
        }
        if(kt(root)){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}