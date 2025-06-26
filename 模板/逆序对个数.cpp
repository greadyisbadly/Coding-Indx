#include <bits/extc++.h>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int Inversion(int a[]) {
	ordered_set st;
	int res = 0;
	for(int i = 1; i <= n; i ++ ) {
		ans += st.size() - st.order_of_key(a[i].second);
		st.insert(a[i].second);
	}
	return res ;
}