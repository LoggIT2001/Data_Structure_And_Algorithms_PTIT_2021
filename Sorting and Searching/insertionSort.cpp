#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+5];
    for(int i=0;i<n;i++) cin >> a[i];
    vector <int> b;
    for(int i=0;i<n;i++){
        b.push_back(a[i]);
        sort(b.begin(),b.end());
        cout << "Buoc " << i+1 << ": ";
        for(int j=0;j<b.size();j++) cout << b[j] <<" ";
        cout << endl;
    }
    return 0;
}