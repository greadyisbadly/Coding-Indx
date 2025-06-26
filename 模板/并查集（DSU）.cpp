int find(int k){
	return f[k] == k? k : f[k] = find(f[k]);
}