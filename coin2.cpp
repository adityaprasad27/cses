#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const long long MOD = 1e9 + 7;

    int n;
    long long sum;
    cin >> n >> sum;

    vector<long long> choices(n);
    for (auto &c : choices) cin >> c;
    sort(choices.begin(), choices.end());

    vector<long long> prev(sum + 1, 0), nxt(sum + 1, 0);

    for (long long s = 0; s <= sum; s++) {
        if (s % choices[0] == 0) prev[s] = 1;
    }

    for (int i = 1; i < n; i++) {
        long long c = choices[i];
        nxt[0] = prev[0];
        for (long long s = 1; s <= sum; s++) {
            nxt[s] = prev[s];
            if (s >= c) {
                nxt[s] = (nxt[s] + nxt[s - c]) % MOD;
            }
        }
        prev = nxt;
    }

    cout << prev[sum] << endl;
    return 0;
}
