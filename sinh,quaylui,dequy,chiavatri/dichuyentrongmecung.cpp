#include<iostream>
#include<cstring>
using namespace std;

long long a[100][100],b[100][100];
int n,ok;
char s[100];
void result(int m){
    for(int i=0;i<m;i++){
        cout << s[i];
    }
    cout << " ";
}
void Try(int i, int j, int m){
    if(i==n && j==n){
        result(m);
        ok=1;
    }else{
        if(a[i+1][j]==1 && b[i+1][j]==0 && i<n){
            b[i+1][j]=1;
            s[m]='D';
            Try(i+1,j,m+1);
            b[i+1][j]=0;
        }
        if(a[i][j-1]==1 && b[i][j-1]==0 && j>1){
            b[i][j-1]=1;
            s[m]='L';
            Try(i,j-1,m+1);
            b[i][j-1]=0;
        }
        if(a[i][j+1]==1 && b[i][j+1]==0 && j<n){
            b[i][j+1]=1;
            s[m]='R';
            Try(i,j+1,m+1);
            b[i][j+1]=0;
        }
        if(a[i-1][j]==1 && b[i-1][j]==0 && i>1){
            b[i-1][j]=1;
            s[m]='U';
            Try(i-1,j,m+1);
            b[i-1][j]=0;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a[i][j];
                b[i][j]=0;
            }
        }
        b[1][1]=1;
        if(a[1][1]==0){
            cout << "-1" << endl;
        }else{
            Try(1,1,0);
            cout << endl;
            if(!ok) cout << "-1" << endl;
        }
    }
    return 0;
}