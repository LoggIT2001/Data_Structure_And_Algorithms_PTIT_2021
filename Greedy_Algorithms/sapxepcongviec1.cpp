#include<bits/stdc++.h>
using namespace std;

struct data{
    int first,last;
};
data a[1005];
bool cmp(data x, data y){
    return x.last<y.last;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> a[i].last;
        }
        sort(a,a+n,cmp);
        int count=1,i=0;
        for(int j=1;j<n;j++){
            if(a[j].first >= a[i].last){
                count++;
                i=j;
            }
        }
        cout << count << endl;
    }
    return 0;
}