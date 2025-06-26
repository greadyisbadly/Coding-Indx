int st[N][20];
void build(){
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j + (1 << i ) - 1<= n;j++){
            st[j][i] = max(st[j][i - 1],st[j + (1 << (i - 1) )][i - 1]);
        }
    }
}
 
int query(int l ,int r ){
    int k = log2(r - l + 1);
    return max(st[l][k],st[r - (1 << k) + 1][k]);
 }