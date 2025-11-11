int manacher(string s) {
    string t = "@#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = std::min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        ans = max(r[i] - 1, ans);
    }
    return ans;
}
