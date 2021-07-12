#include<iostream>
using namespace std;

void merge(int a[], int l, int m, int h){
    int k=1;
    int n1=m-l+1;
    int n2=h-m;
    int *L= new int[n1];
    int *R= new int[n2];
    // dua vao 2 mang L va R
    for(int i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=a[m+j+1];
    }
    // tron
    int i=0, j=0;
    while(i<n1 && j<n2){
        a[k++]= (L[i] <= R[j])?L[i++]:R[j++];
    }
    while(i<n1){
        a[k++]=L[i++];
    }
    while(j<n2){
        a[k++]=R[j++];
    }
}
void mergeSort(int a[], int l, int h){ // thuat toan sap xep tron
    if(l<h){
        // tim phan tu mid
        int m=l+(h-1)/2;
        mergeSort(a,l,m); // de quy nua dau mang
        mergeSort(a,m+1,h); // de quy nua sau mang
        merge(a,l,m,h); // tron 2 nua vao nhau
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n+5];
        for(int i=0;i<n;i++) cin >> a[i];
        mergeSort(a,0,n-1);   
        for(int i=0;i<n;i++){
            cout << a[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}