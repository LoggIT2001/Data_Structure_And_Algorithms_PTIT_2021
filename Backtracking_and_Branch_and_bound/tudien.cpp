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
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=3;

/**********DTL**********/

string dictionary[101], res[101];
int res_count = 0;

/**********DTL**********/

bool isWord(string& str, int length) {
    for (int i = 0; i < length; i++)
        if (str.compare(dictionary[i]) == 0)
            return true;

    return false;
}

void findWordsUntil(char boggle[MAX][MAX], int length,bool visited[MAX][MAX], int i,int j, string& str, int m, int n)
{
    visited[i][j] = true;
    str = str + boggle[i][j];

    if (isWord(str, length)) {
        res[res_count] = str;
        res_count++;
    }

    for (int row = i - 1; row <= i + 1 && row < m; row++)
        for (int col = j - 1; col <= j + 1 && col < n; col++)
            if (row >= 0 && col >= 0 && !visited[row][col])
                findWordsUntil(boggle, length, visited,
                                row, col, str, m, n);

    str.erase(str.length() - 1);
    visited[i][j] = false;
}

void findWords(char boggle[MAX][MAX], int m, int n) {
    bool visited[MAX][MAX] = { { false } };
    int length = sizeof(dictionary) / sizeof(dictionary[0]);
    string str = "";

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            findWordsUntil(boggle, length, visited,
                            i, j, str, m, n);
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test, k, m, n;
    string str;
    cin >> test;
    while (test--) {
        res_count = 0;
        cin >> k >> m >> n;
        for (int i = 0; i < k; i++)
            cin >> dictionary[i];
        char boggle[MAX][MAX];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> boggle[i][j];

        findWords(boggle, m, n);
        if (res_count == 0)
            cout << "-1";
        else {
            for (int i = 0; i < res_count; i++)
                cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}