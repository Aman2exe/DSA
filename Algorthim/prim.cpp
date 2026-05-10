int prim(int n, vector<vector<pair<int,int>>>& adj) {
    int val = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> vis(n, 0);
    pq.push({0, 0});  
    while (!pq.empty()) {
        auto [wei, ver] = pq.top();
        pq.pop();
        if (vis[ver]) continue;
        vis[ver] = 1;
        val += wei;
        for (auto &edge : adj[ver]) {
            int next = edge.first;
            int w = edge.second;

            if (!vis[next]) {
                pq.push({w, next});
            }
        }
    }
    return val;
}