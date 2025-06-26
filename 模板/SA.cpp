struct SASA {
    string s;
    int m, n;
    int x[N], y[N];
    int rk[N], sa[N];
    int buc[N];

    bool cmp(int xa, int ya, int len) {
        return y[xa] == y[ya] && y[xa + len] == y[ya + len];
    }

    void SA() {
        m = 122;
        n = s.size();
        s = " " + s;

        for (int i = 1; i <= n; ++i) {
            rk[i] = s[i] - ' ';
            buc[rk[i]] ++;
        }

        for (int i = 1; i <= m; ++i)
            buc[i] += buc[i - 1];

        for (int i = n; i >= 1; --i)
            sa[buc[rk[i]] --] = i;

        for (int len = 1; len <= n; len <<= 1) {
            int num = 0;

            for (int i = n - len + 1; i <= n; ++i)
                y[++ num] = i;

            for (int i = 1; i <= n; ++i)
                if (sa[i] > len)
                    y[++ num] = sa[i] - len;

            for (int i = 1; i <= m; ++i)
                buc[i] = 0;

            for (int i = 1; i <= n; ++i) {
                x[i] = rk[y[i]];
                buc[x[i]] ++;
            }

            for (int i = 1; i <= m; ++i)
                buc[i] += buc[i - 1];

            for (int i = n; i >= 1; --i) {
                sa[buc[x[i]] --] = y[i];
                y[i] = 0;
            }

            swap(rk, y);
            rk[sa[1]] = 1, num = 1;

            for (int i = 2; i <= n; ++i) {
                if (cmp(sa[i], sa[i - 1], len))
                    rk[sa[i]] = num;
                else
                    rk[sa[i]] = ++ num;
            }

            if (num == n)
                break;

            m = num;
        }
    }
} S;