
class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout;
    vector<int> prefix;
    int timer = 0;

    // Fenwick Tree supporting XOR updates
    vector<int> bit;

    void updateBIT(int idx, int val, int n) {
        while (idx <= n) {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }

    int queryBIT(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans ^= bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int node, int parent, string &s) {
        tin[node] = ++timer;

        up[0][node] = parent;

        for (int j = 1; j < LOG; j++) {
            up[j][node] = up[j - 1][up[j - 1][node]];
        }

        if (node == 0) {
            prefix[node] = getMask(s[node]);
        } else {
            prefix[node] = prefix[parent] ^ getMask(s[node]);
        }

        for (int child : adj[node]) {
            if (child == parent) continue;

            depth[child] = depth[node] + 1;
            dfs(child, node, s);
        }

        tout[node] = timer;
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    // Current root-to-node parity mask
    int getPrefix(int node) {
        return prefix[node] ^ queryBIT(tin[node]);
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        prefix.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Build Euler tour and initial prefix masks
        dfs(0, 0, s);

        vector<bool> ans;

        for (string &q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int change = getMask(s[u]) ^ getMask(c);

                // Update all root-prefix masks in u's subtree
                updateBIT(tin[u], change, n);
                updateBIT(tout[u] + 1, change, n);

                s[u] = c;
            } else {
                int v;
                ss >> v;

                int lca = LCA(u, v);

                int mask = getPrefix(u)
                         ^ getPrefix(v)
                         ^ getMask(s[lca]);

                // At most one character may have odd frequency
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
