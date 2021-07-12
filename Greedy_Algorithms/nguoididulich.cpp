#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

bool chuaxet[1000];
int c[100][100], x[1000],n;
int sum=0;
int Min=1000000,cmin=10000;
void Try(int i){
    if(sum+cmin*(n-i+1) >Min) return;
    for(int j=2;j<=n;j++){
        if(chuaxet[j]){
            x[i]=j;
            chuaxet[j]=false;
            sum+=c[x[i-1]][j];
            if(i==n){
                if(sum+c[x[n]][x[1]] <Min) Min=sum+c[x[n]][x[1]]; 
            }else Try(i+1);
            chuaxet[j]=true;
            sum-=c[x[i-1]][j];
        }
    }
}
int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        memset(chuaxet,true,sizeof(chuaxet));
        chuaxet[1]=false;
        x[1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> c[i][j];
                if(c[i][j]!=0) cmin=min(cmin,c[i][j]);
            }
        }
        Try(2);
        cout << Min << endl;
    }
    return 0;
}