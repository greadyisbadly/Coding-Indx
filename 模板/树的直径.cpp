void diam(int x, int fa) {
	for(auto y : G[x]) {
		if(y == fa) continue;
 		diam(y, x);
 		ans = max(ans, dp[x] + dp[y] + 1);
 		dp[x] = max(dp[x], dp[y] + 1);
 	}
}