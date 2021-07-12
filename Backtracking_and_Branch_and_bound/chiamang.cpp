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

bool KT(int a[], int subsetSum[], bool taken[], int subset, int k, int n, int cur, int limit){
    if(subsetSum[cur]==subset){
        if(cur==k-2){
            return true;
        }
        return KT(a,subsetSum,taken,subset,k,n,cur+1,n-1);
    }
    FORD(i,limit,0){
        if(taken[i]) continue;
        int tmp=subsetSum[cur]+a[i];
        if(tmp<=subset){
            taken[i]=true;
            subsetSum[cur]+=a[i];
            bool nxt=KT(a,subsetSum,taken,subset,k,n,cur,i-1);
            taken[i]=false;
            subsetSum[cur]-=a[i];
            if(nxt){
                return true;
            }
        }
    }
    return false;
}

bool solution(int a[], int n, int k){
    if(k==1){
        return true;
    }
    if(n<k){
        return true;
    }
    int sum=0;
    FOR(i,0,n){
        sum+=a[i];
    }
    if(sum%k!=0){
        return false;
    }
    int subset=sum/k;
    int subsetSum[k];
    bool taken[n];
    FOR(i,0,k){
        subsetSum[i]=0;
    }
    FOR(i,0,n){
        taken[i]=false;
    }
    subsetSum[0]=a[n-1];
    taken[n-1]=true;
    return KT(a,subsetSum,taken,subset,k,n,0,n-1);
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        int a[n+5];
        FOR(i,0,n){
            cin >> a[i];
        }
        if(solution(a,n,k)){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

/*
    array           - chuoi nhap vao
    subsetSum array - chuoi luu tru tong gia tri cua tung chuoi con trong day
    taken           - chuoi boolean kiem tra phan tu co the dua vao tong cua partition
    K               - so tap con can chia
    N               - so phan tu cua day
    curIdx          - gia tri hien tai trong chuoi subsetSum
    limitIdx        - gia tri cuoi cung ma day nen nhan
    
bool isKPartitionPossibleRec(int arr[], int subsetSum[], bool taken[],
        int subset, int K, int N, int curIdx, int limitIdx)
{
    if (subsetSum[curIdx] == subset) {

        if (curIdx == K - 2)
            return true;

        return isKPartitionPossibleRec(arr, subsetSum, taken, subset,
                            K, N, curIdx + 1, N - 1);
    }

    for (int i = limitIdx; i >= 0; i--) {
        if (taken[i])
            continue;
        int tmp = subsetSum[curIdx] + arr[i];

        if (tmp <= subset) {
            taken[i] = true;
            subsetSum[curIdx] += arr[i];
            bool nxt = isKPartitionPossibleRec(arr, subsetSum, taken, subset,
                                    K, N, curIdx, i - 1);

            taken[i] = false;
            subsetSum[curIdx] -= arr[i];
            if (nxt)
                return true;
        }
    }
    return false;
}

bool isKPartitionPossible(int arr[], int N, int K) {
    if (K == 1)
        return true;

    if (N < K)
        return true;

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % K != 0)
        return false;

    int subset = sum / K;
    int subsetSum[K];
    bool taken[N];

    for (int i = 0; i < K; i++)
        subsetSum[i] = 0;

    for (int i = 0; i < N; i++)
        taken[i] = false;

    subsetSum[0] = arr[N - 1];
    taken[N - 1] = true;

    return isKPartitionPossibleRec(arr, subsetSum, taken,
                                subset, K, N, 0, N - 1);
}

int main() {
    int test, N, K;
    cin >> test;
    while (test--) {
        cin >> N >> K;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        if (isKPartitionPossible(arr, N, K))
            cout << "1\n";
        else 
            cout << "0\n";
    }
    return 0;
}
*/