void insert(string s){
    q = 0; l = s.size();
    for (int i = 0; i <l; i++)
    {
        x = s[i] - 'a';
        if(!p[q][x]) p[q][x] = ++ idx;
        q = p[q][x];
    }
    vis[q] = 1;
}

int query(string s){
    q = 0; l = s.size();
    for (int i = 0; i < l; i++) {
       x = s[i] - 'a';
       if(!p[q][x]) return 0;
       q = p[q][x];
    }
    return vis[q];
}