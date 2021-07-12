#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+5], b[n+5];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        bool ok=false;
        for(int j=0;j<n;j++){
            if(a[j] !=b[j]){
                ok=true;
                break;
            }
        }
        if(!ok) break;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
        cout << "Buoc " << i+1 <<": ";
        for(int j=0;j<n;j++) cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}