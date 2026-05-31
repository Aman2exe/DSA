// Build segment tree
void build(vector<int>& a, int low, int high, int ind) {
    if (low==high){seg[ind]=a[low];  return;}
    int mid=(low+high)/2;
    build(a,low,mid, 2*ind);
    build(a, mid +1,high,2 *ind+1);
    seg[ind] = seg[2*ind]+seg[2*ind+1];
}

void push(int ind, int low, int high) {
    if (lazy[ind]!=0) {
        seg[ind]+=(high-low+1)*lazy[ind];
        if (low != high) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
}

// Range update (add val to [l, r])
void update(int low, int high, int l, int r, int ind, long long val) {
    push(ind, low, high);
    if (high<l || low>r) return;
    if (low>=l && high<=r) {
        lazy[ind] += val;
        push(ind, low, high);
        return;
    }
    int mid = (low + high) / 2;
    update(low, mid, l, r, 2*ind, val);
    update(mid + 1, high, l, r, 2*ind+1, val);
    seg[ind]=seg[2*ind] + seg[2*ind +1];
}

// Range sum query
long long query(int low, int high, int l, int r, int ind) {
    push(ind, low, high);
    if (high < l || low > r) return 0;
    if (low >= l && high <= r) return seg[ind];
    int mid = (low + high) / 2;
    return query(low, mid, l, r, 2 * ind) +
           query(mid + 1, high, l, r, 2 * ind + 1);
}
