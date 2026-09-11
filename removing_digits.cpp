#include<iostream>
#include<vector>
#include<deque>
using namespace std;
bool d_is_in_n(int n, int d) {
    while(n > 0) {
        if (n%10 == d)
            return true;
        n = n/10;
    }
    return false;
};

int solve(int n) {
    int res = 1;

    vector<vector<int>> adj(n+1);
    deque<int> q = {n};
    vector<bool> v(n+1, false);
    v[n] = true;

    int digits[9] = {1, 2, 3, 4, 5 , 6, 7, 8, 9};
    while (!q.empty()) {
        int node = q.front();
        q.pop_front();
        for (auto &d: digits) {
            if (d_is_in_n(node, d)) {
                if (node - d < 0)
                    continue;

                adj[node].push_back(node-d);

                if (node > d and not v[node-d]) {
                    q.push_back(node-d);
                    v[node-d] = true;
                }
            }
        };
    }

    q = {n};
    v.assign(v.size(), false);
    v[n] = true;
    while(not q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            int node = q.front();
            q.pop_front();
            for(auto nei: adj[node]) {
                if (nei == 0)
                    return res;

                if (not v[nei]) {
                    q.push_back(nei);
                    v[nei] = true;
                }
            }
        }
        res += 1;
    }

    return res;
}

int main(){
    int n;
    std::cin >> n;
    cout << solve(n);
}