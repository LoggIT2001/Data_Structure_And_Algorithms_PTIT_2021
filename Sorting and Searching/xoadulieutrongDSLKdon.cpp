#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

// nhap mang list neu khac x thi cho vao vector xong in vector

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        int n,x;
        cin >> n >> x;
        list<int> li;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            li.push_back(a);
        }
        while(!li.empty()){
            int top=li.front();
            if(top!=x){
                cout << top << " ";
            }
            li.pop_front();
        }
        //cout << endl;
    //}
    return 0;
}

/*****design by DTLong*****/