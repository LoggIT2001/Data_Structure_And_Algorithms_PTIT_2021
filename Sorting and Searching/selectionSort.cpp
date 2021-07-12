#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+5];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++){
        int index=i+1;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[index]) index=j;
        }
        if(a[i]>a[index]) swap(a[i],a[index]);
        cout << "Buoc " << i+1  << ": ";
        for(int j=0;j<n;j++) cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}