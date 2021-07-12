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
    Node *r,*l;
    Node(int x){
        data=x;
        r=l=NULL;
    }
};

/**********DTL**********/

void Spiral(Node *root){
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    Node *temp;
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            temp=st1.top();
            cout << temp->data << " ";
            st1.pop();
            if(temp->r) st2.push(temp->r);
            if(temp->l) st2.push(temp->l);
        }
        temp=NULL;
        while(!st2.empty()){
            temp=st2.top();
            cout << temp->data << " ";
            st2.empty();
            st2.pop();
            if(temp->l) st1.push(temp->l);
            if(temp->r) st1.push(temp->r);
        }
    }
}

void MakeNode(Node *root,int n1, int n2, char c){
    switch(c){
        case 'L' : root->l =new Node(n2);
                break;
        case 'R' : root->r =new Node(n2);
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
        Spiral(root);
        cout << endl;
    }
    return 0;
}