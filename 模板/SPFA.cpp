int dis[N], vis[N];
void SPFA(int s) {
	for(int i = 1; i <= n; i ++ ) {
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	queue<int> q; q.push(s);

	while(!q.empty()){
		int t = q.front(); q.pop();
		vis[t] = 0;
		for(auto [u, w]: G[t]) {
			if(dis[u] > dis[t] + w) {
				dis[u] = dis[t] + w;
				if(!vis[u]) q.push(u), vis[u] = 1;
			}
		}
	}
}