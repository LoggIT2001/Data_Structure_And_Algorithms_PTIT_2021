#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    vector<int> ke[100];
    int d[100][100];
    cin.ignore();
    for(int i=1;i<=n;i++){
        getline(cin,s);
        s+=" ";
        int j=0;
        int tmp=0;
        while(j<s.size()){
            if(s[j]>='0' && s[j] <='9'){
                tmp=tmp*10 + (int)(s[j]-'0');
            }else if(tmp>0){
                ke[i].push_back(tmp);
                tmp=0;
            }
            j++;
        }
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++){
        for(int j=0;j<ke[i].size();j++){
           if(!d[i][ke[i][j]] && !d[ke[i][j]][i]){
               cout << i << " " << ke[i][j] << endl;
           }
           d[i][ke[i][j]]=d[ke[i][j]][i]=1;
        }
    }
    return 0;
}