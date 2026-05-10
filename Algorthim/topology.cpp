bool dfs(int u, stack<int>& st, vector<int>& state, const vector<vector<int>>& adj) {
    state[u] = 1; 
    for (int v : adj[u]) {
        if (state[v] == 1) return false; 
        if (state[v] == 0) {
            if (!dfs(v, st, state, adj)) return false;
        }
    }
    state[u] = 2; 
    st.push(u);   
    return true;
}

vector<int> topology(int n, const vector<vector<int>>& adj) {
    stack<int> st;
    vector<int> state(n, 0);
    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (!dfs(i, st, state, adj)) {
                return {}; 
            }
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}