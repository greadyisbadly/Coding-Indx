int st[N], dist[N];
vector<P>G[N];
void dijkstra(int s){
    for (int i = 1; i <= n; i ++) {
        st[i] = 0;
        dist[i] = inf;
    }
    priority_queue<P,vector<P>,greater<P> >q;
    q.push({0, s});
    while(!q.empty()) {
        P t = q.top(); q.pop();
        if(dist[t.second] <= t.first) continue;
        dist[t.second] = t.first;
        for (auto [u, w] : G[t.second]) {
            if(dist[u] <= t.first + w) continue;
            q.push({t.first + w, u});
        }
    }
}
