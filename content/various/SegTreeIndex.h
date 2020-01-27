/**
 * Author: Alex Yu
 * License: CC0
 * Source: CppReference
 * Description: Data structure supporting
     1. deletion of elements in an array by index in initial array (or index in remaining array, using 2)
     2. conversion of indices in the remaining array to indices in the initial array
     each in O(logN) time. Build is O(N).
 * Status: tested on problem
 */
// to initialize: build(0, N, 1)
// to delete element v: upd(0, N, 1, v)
// to query original index of element v in remaining array: query(0, N, 1, v)
// where N is initial # elements

struct SegTreeIndex {
    int t[MAXN*4];

    void build(int l, int r, int p) {
        t[p] = r - l;
        if (r - l <= 1) return;
        int m = (l + r) >> 1;
        build(l, m, p<<1); build(m, r, (p<<1) | 1);
    }

    void upd(int l, int r, int p, int v) {
        --t[p];
        if (r - l <= 1) return;
        int m = (l + r) >> 1;
        if (v < m) upd(l, m, p<<1, v);
        else upd(m, r, (p<<1) | 1, v);
    }

    int query(int l, int r, int p, int v) {
        if (r - l <= 1) return l;
        int m = (l + r) >> 1;
        if (v < t[p<<1]) return query(l, m, p<<1, v);
        else return query(m, r, (p<<1) | 1, v - t[p<<1]);
    }
};
