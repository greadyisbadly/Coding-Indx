for (int i = 0; i < maxnum; i++)st.insert(i);
	cin >> m;
	while (m--) {
		cin >> op;
		if (op == 0) { // 添加
			cin >> x;
			if (cot[x] == 0) {
				st.erase(x);
			}
			cot[x]++;
		}
		else if (op == 1) { // 查询
			cout << *st.begin() << endl;
		}
		else { // 删除
			cin >> x;
			if (cot[x] == 1) {
				st.insert(x);
			}
			cot[x]--;
		}
	}
