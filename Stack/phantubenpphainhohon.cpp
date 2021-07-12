#include<bits/stdc++.h>
using namespace std;

void Next_Greater(int n, int a[], int next_greater[]){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        if(st.empty()){
            next_greater[i]=-1;
        }else{
            next_greater[i]=st.top();
        }
        st.push(i);
    }
}

void Right_Small(int n, int a[], int right_small[]){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            right_small[i]=-1;
        }else{
            right_small[i]=st.top();
        }
        st.push(i);
    }
}

void solution(int n, int a[]){
    int next_greater[n],right_small[n];
    Next_Greater(n,a,next_greater);
    Right_Small(n,a,right_small);
    for(int i=0;i<n;i++){
        if(next_greater[i]!=-1 && right_small[next_greater[i]]!=-1){
            cout << a[right_small[next_greater[i]]] << " ";
        }else{
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n+5];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        solution(n,a);
    }
    return 0;
}