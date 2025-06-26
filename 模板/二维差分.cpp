int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

void _run(){
	for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
}

void init(){
	for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) { 
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {        
            insert(i, j, i, j, a[i][j]);
        }
    }
}



