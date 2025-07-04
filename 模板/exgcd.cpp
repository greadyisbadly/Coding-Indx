int exgcd(int a, int b, int &x, int &y)  {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
// 扩展欧几里得算法, 求x, y，使得ax + by = gcd(a, b)