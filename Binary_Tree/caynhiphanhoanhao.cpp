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
    int data;
    Node *l, *r;
    Node(int x){
        data=x;
        l=r=NULL;
    }
};

/**********DTL**********/

int findADepth(Node *node){
    int i=0;
    while(node !=NULL){
        i++;
        node = node->l;
    }
    return i;
}

bool Perfect(struct Node* root, int n, int level){
    queue<Node*> qe;
    qe.push(root);
    int x=0,y=0;
    while(!qe.empty()){
        x=qe.size();
        if(x!=int(pow(2,y))){
            return false;
        }
        FOR(i,0,x){
            Node *t=qe.front();
            qe.pop();
            if(t->l) qe.push(t->l);
            if(t->r) qe.push(t->r);
        }
        y++;
    }
    return true;
}

bool isPerfect(Node *root){
    int i=findADepth(root);
    return Perfect(root,i,0);
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
            int n1, n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(root==NULL){
                root = new Node(n1);
                MakeNode(root,n1,n2,c);
            }else{
                Insert(root,n1,n2,c);
            }
        }
        if(isPerfect(root)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}