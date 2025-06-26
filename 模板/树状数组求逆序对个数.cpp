int tr[N], a[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i)) {
		tr[i] += y;
	}
}

int get(int x) {
	int sum = 0;
	for(int i = x; i; i -= lowbit(i)) {
		sum += tr[i];
	}
	return sum;
}

int cal() {
	for(int i = 1; i <= n; i ++ ) {
		ans += i - get(a[i]) - 1;
		add(a[i], 1);
	} 
	return ans;
}
