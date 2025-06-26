int in[N], out[N];
void Tupo() {
    queue<int> q;
    for(int i = 1; i <= n; i ++ ) {
        if (in[i] == 0){
            q.push(i);
        }
        while(!q.empty()) {
            ans ++;
            cnt = q.front(); q.pop();
            for(int i = 0; i <= res; i ++ ) {
                if(a[cnt][i] != 0) {
                    in[i] --;
                    if(in[i] == 0) q.push(i);
                }
            }
        }
    }
}