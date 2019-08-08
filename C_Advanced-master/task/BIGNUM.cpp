void swap(long long *a, long long *b){
  long long tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

long long addmod(long long a, long long b, long long P){
    a = a % P;
    b = b % P;
    long long tmp = P - b;
    if (a>= tmp) return a - tmp;
    else return a + b ;
}

long long mulmod(long long a, long long b, long long P){
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b%P;
    if (b == 1) return a%P;
    if (a > b) swap(&a, &b);
    long long c = mulmod(a/2, b, P);
    c = addmod(c, c, P);
    if (a%2 == 0) return c;
    else return addmod(c, b, P);
}
