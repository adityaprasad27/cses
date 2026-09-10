given coins, and target sum, get count of ways to get that sum. 2+2+3 is not different from 2+3+2 


consider coins array, sorted. we'll walk that array through index i

f(s, i) = f(s-coins[i], i) + f(s, i-1) 
where given sum s, index i. either take that coin if possible (s > coins[i]), 

so we can do this using recrusion. or go the route of 2d dp , y axis index, x axis sum +1

or because that goes too big

we notice that we only really depend on i-1 index and so we can remove after that

we can just have next and prev array and swap and do stuff

```cpp
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

```

python is incredibly slow for this for whcih we developed numpy alog using an intresting concept

think this, 
given a sum, s = r + k * c

lets it count be n, like the number of ordere ways whatver, the final answer be n

now you know that f(r + (k+1) * c) >= n . atleast all the ways for r + kc would work for k+1, could be more ofc but yeah atleas tthat muhc

now we know, f(r + kc, c)  (c is the coin) = f(r+ (k-1)c, c) + f(r + kc, c[i-1]) , c[i-1] denotes take diferent coin

so imagine i -1 is prev, i is next

next[r+kc] = next[r+(k-1)c] + prev[r+kc]


and here you learn next[r+kc] = sum prev[r+jc] for all j 0 to k

and so you can do

`a[r::c] = np.cumsum(a[r::c])` or somethign like that and it vectorizes the whole thing



