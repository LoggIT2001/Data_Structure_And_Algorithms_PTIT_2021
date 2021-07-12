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
#define FOR(i,n,m) for(long long i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

ll _MergeSort(ll a[], ll temp[], ll left, ll right);
ll Merge(ll a[], ll temp[], ll left, ll mid, ll right);

/**********DTL**********/

ll MergeSort(ll a[], ll n){
    ll temp[n];
    return _MergeSort(a,temp,0,n-1);
}

ll _MergeSort(ll a[], ll temp[], ll left, ll right){
    ll mid,countt=0;
    if(right>left){
        mid=(right+left)/2;
        countt+=_MergeSort(a,temp,left,mid);
        countt+=_MergeSort(a,temp,mid+1,right);
        countt+=Merge(a,temp,left,mid+1,right);
    }
    return countt;
}

ll Merge(ll a[], ll temp[], ll left, ll mid, ll right){
    ll i,j,k;
    ll countt=0;
    i=left;
    j=mid;
    k=right;
    while((i<=mid-1)&&(j<=right)){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            countt+=(mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(i=left;i<=right;i++){
        a[i]=temp[i];
    }
    return countt;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        ll a[n+5];
        FOR(i,0,n-1){
            cin >> a[i];
        }
        ll ans=MergeSort(a,n);
        cout << ans << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

long long _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right);

long long mergeSort(long long arr[], long long array_size) {
    long long temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

long long _mergeSort(long long arr[], long long temp[], long long left, long long right) {
    long long mid, inverse_count = 0;
    if (right > left) {
        // Chia ra thanh 2 phan, goi ham _mergeSort cho moi phan
        mid = (right + left) / 2;

        // Tinh tong cap nghich the o ben trai va phai
        inverse_count += _mergeSort(arr, temp, left, mid);
        inverse_count += _mergeSort(arr, temp, mid + 1, right);

        // Gop 2 phan
        inverse_count += merge(arr, temp, left, mid + 1, right);
    }
    return inverse_count;
}

long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
    long long i, j, k;
    long long inverse_count = 0;

    i = left;
    j = mid;
    k = left;
    
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inverse_count = inverse_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inverse_count;
}

int main() {
    int test;
    long long n;
    cin >> test;
    while (test--) {
        cin >> n;
        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];
        long long ans = mergeSort(arr, n);
        cout << ans << endl;
    }
    return 0;
}
*/