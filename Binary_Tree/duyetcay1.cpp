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

/**********DTL**********/

int Search(int a[], int x, int n){
    FOR(i,0,n){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

void PrintPostorder(int Inorder[], int Preorder[], int n){
    int root=Search(Inorder,Preorder[0],n);
    if(root!=0){
        PrintPostorder(Inorder,Preorder+1,root);
    }
    if(root!=n-1){
        PrintPostorder(Inorder+root+1,Preorder+root+1,n-root-1);
    }
    cout << Preorder[0] << " ";
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int Inorder[n+5];
        int Perorder[n+5];
        FOR(i,0,n){
            cin >> Inorder[i];
        }
        FOR(i,0,n){
            cin >> Perorder[i];
        }
        PrintPostorder(Inorder,Perorder,n);
        cout << endl;
    }
    return 0;
}