int kadane(vector<int> vec, int n) {
    int ans = vec[0], curr = vec[0];
    for (int i = 1; i < n; i++) {
        curr = max(curr + vec[i], vec[i]);
        ans = max(curr, ans);
    }
    return ans;
}
