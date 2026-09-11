#include<iostream>
#include<string>
#include<vector>

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

    vector<vector<int>> dp(n, vector<int>(n, 0));
    int val = 1;
    for(int i = n-1; i >= 0; i--){
        if (v[i][n-1] == '*')
            val = 0;
        
        dp[i][n-1] = val;
    }
    val = 1;
    for(int j = n-1; j >= 0; j--){
        if (v[n-1][j] == '*')
            val = 0;
        
        dp[n-1][j] = val;
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            if (v[i][j] == '*') 
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % MOD;
        }
    }
    return dp[0][0] % MOD;
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