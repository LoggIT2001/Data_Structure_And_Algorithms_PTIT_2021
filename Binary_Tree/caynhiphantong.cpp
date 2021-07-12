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

int height(struct Node* root){
    if(!root) return 0;
    return (1+max(height(root->l),height(root->r)));
}

int sum(Node *root){
    int sumtotal=0;
    if(root==NULL) return 0;
    else{
        int left= sum(root->l);
        int right= sum(root->r);
        sumtotal=root->data + left + right;
    }
    return sumtotal;
}

bool isSumTree(Node* root){
	if(root==NULL) return 1;
	if(root->l==NULL && root->r==NULL) return 1;
	int left=sum(root->l);
	int right=sum(root->r);
	if(root->data==(left+right) && isSumTree(root->l) && isSumTree(root->r)){
		return 1;
	}
	return 0;
}

void MakeNode(Node *root, int n1, int n2, int c){
	switch(c){
		case 'L': root->l = new Node(n2);
				break;
		case 'R': root->r = new Node(n2);
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
        map<int, Node*> m;
        int n;
        cin >> n;
        Node *root =NULL;
        Node *child;
        while(n--){
            Node *parent;
            int n1,n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(m.find(n1)==m.end()){
                parent=new Node(n1);
                m[n1]=parent;
                if(root==NULL) root=parent;
            }else{
                parent=m[n1];
            }
            child = new Node(n2);
            if(c=='L') parent->l=child;
            else parent->r=child;
            m[n2]=child;
        }
        cout << isSumTree(root) << endl;
    }
    return 0;
}