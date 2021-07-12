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

struct point{
    double x,y;
};
point p[MAX];
double res;

/**********DTL**********/

bool compare_X_point(const point& p1, const point& p2){
    return p1.x<p2.x;
}

bool compare_Y_point(const point& p1, const point& p2){
    return p1.y<p2.y;
}

void distance(const point& p1, const point& p2){
    double dist=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    if(dist<res){
        res=dist;
    }
}

void seaching(int left, int right){
    if(right<=left) return;
    if(right==left+1){
        distance(p[left],p[right]);
        if(!compare_Y_point(p[left],p[right])){
            swap(p[left],p[right]);
        }
        return;
    }
    int mid=(left+right)/2;
    double mid_X=p[mid].x;
    seaching(left,mid);
    seaching(mid+1,right);
    static point temp[MAX];
    merge(p + left, p + mid + 1, p + mid + 1, p + right + 1, temp, compare_Y_point);
    copy(temp, temp + right - left + 1, p + left);
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (abs(p[i].x - mid_X) < res) {
            for (int j = count - 1; j >= 0 && temp[j].y > p[i].y - res; j--)
                distance(p[i], temp[j]);
            temp[count++] = p[i];
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        FOR(i,0,n){
            cin >> p[i].x >> p[i].y;
        }
        res = 1E20;
        sort(p, p + n, compare_X_point);
        seaching(0, n - 1);

        cout << fixed << setprecision(6) << res << endl;
    }
    return 0;
}