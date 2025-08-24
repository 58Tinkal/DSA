void binary_lifting(int node, int par, vector<int> adj[],
                    vector<vector<int>>& dp, vector<int>& level, int l = 0) {
    dp[node][0] = par;
    for (int i = 1; i <= 16; i++) {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    level[node] = l;
    for (auto& it : adj[node]) {
        if (it == par)
            continue;
        binary_lifting(it, node, adj, dp, level, l + 1);
    }
}

int getKpar(int node, int k, vector<vector<int>>& dp) {
    for (int i = 16; i >= 0; i--) {
        if ((k >> i) & 1) {
            node = dp[node][i];
        }
    }
    return node;
}

int lca(int u, int v, vector<vector<int>>& dp, vector<int>& level) {
    if (level[u] > level[v])
        swap(u, v);

    // u is at lesser level
    int k = level[v] - level[u];
    v = getKpar(v, k, dp);
    // now both u, v are at same level

    if (u == v)
        return u;

    for (int i = 16; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return dp[u][0];
}
