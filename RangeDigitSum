//Digit dp for counting the sum of digit in range l to r inclusive

ll dp[19][2][174];
// upto 10^18 +1;

ll solve(ll idx, ll tight, ll sum, string& s) {

    if (idx >= s.size()) {
        return sum;
    }

    if (dp[idx][tight][sum] != -1)
        return dp[idx][tight][sum];

    ll ans = 0;
    ll limit = tight ? s[idx] - '0' : 9;

    for (int d = 0; d <= limit; d++) {
        ll newTight = tight & (d == limit);
        ans += solve(idx + 1, newTight, sum + d, s);
    }
    return dp[idx][tight][sum] = ans;
}

ll fun(ll& a, ll& b) {

    // for low => a-1;
    string l = to_string(a - 1);
    memset(dp, -1, sizeof(dp));
    ll x = solve(0, true, 0, l);

    // for high => b
    string r = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll y = solve(0, true, 0, r);

    return (y - x);
}
