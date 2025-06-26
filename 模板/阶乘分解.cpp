 for (int i = 0; i < cnt; i ++ ) {
       int p = primes[i]; //质数
       int s = 0;
       for (int j = n; j; j /= p) s += j / p;
       printf("%d %d\n", p, s);
 }