template<class T>
struct MaxFlow {
    struct Edge{
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };

    int n;
    vector<vector<int>> g;
    vector<Edge> e;
    vector<int> cur, h;

    MaxFlow() {};
    MaxFlow(int n) {
        init(n);
    }

    void init(int n) {
        this -> n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }

    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }

    bool bfs(int s, int t) {
        h.assign(n, -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);

        while(!q.empty()) {
            const int u = q.front(); q.pop();
            for(auto i : g[u]) {
                auto [v, c] = e[i];
                if(c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if(v == t) {
                        return true;
                    }
                    q.push(v);
                }  
            }
        }
        return false;
    }

    T dfs(int u, int t, T f) {
        if(u == t) {
            return f;
        }

        auto r = f;
        for(int &i = cur[u]; i < g[u].size(); i ++ ) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if(c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if(r == 0) return f;
            }
        }
        return f - r;
    }
    T flow(int s, int t) {
        T ans = 0;
        while(bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, numeric_limits<T>::max());
        }
        return ans;
    }
};

MaxFlow<int> G(n + 1);