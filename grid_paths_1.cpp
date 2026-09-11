#include<iostream>
#include<string>

using namespace std;

int MOD = 1e9 + 7;

int dfs(int i, int j, vector<string> &v, int &n) {
    if(i >= n or j >= n or v[i][j] == '*')
        return 0;

    if(i == n-1 and j == n-1)
        return 1;

    return dfs(i+1, j, v, n) + dfs(i, j+1, v, n);
}

int solve(vector<string> &v, int n) {
    
    if (v.back().back() == '*')
        return 0;

    return dfs(0, 0, v, n);
}

int main(){
    int n;
    cin >> n;

    vector<string> v;

    for(int i = 0; i < n; i++) {
        string s;

        cin >> s;
        v.push_back(s);
    }

    cout << solve(v, n);
}