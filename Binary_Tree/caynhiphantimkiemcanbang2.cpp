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
#define FOR(i,n,m) for(int i=n;i<m;++i)
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
    Node *l,*r;
};

/**********DTL**********/

Node *node(int val){
    Node *tmp=new Node;
    tmp->data=val;
    tmp->l=tmp->r=NULL;
    return tmp;
}

Node *CreatBTS(int* a, int start, int end){
    if(start>end) return NULL;
    int mid=(start+end)/2;
    Node *tmp=node(a[mid]);
    tmp->l=CreatBTS(a,start,mid-1);
    tmp->r=CreatBTS(a,mid+1,end);
    return tmp;
}

void PreOrder(Node *root){
    if(root){
        cout << root->data << " ";
        PreOrder(root->l);
        PreOrder(root->r);
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
        int a[n+5];
        FOR(i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        Node *root=CreatBTS(a,0,n-1);
        PreOrder(root);
        cout << endl;
    }
    return 0;
}