
const int MAXN =500;
const int m = 1e9 +7;
int factorial[MAXN], factorial_inv[MAXN], inv[MAXN];
void pre_computation(){
    factorial[0] = 1;
    factorial_inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = (m - (m/i)) * inv[m%i] % m;


    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
        factorial_inv[i] = factorial_inv[i - 1] * inv[i] % m;
}
}


long long binomial_coefficient(int n, int k) {
    if(n<0 || k< 0 || k>n) return 0;
    return ((factorial[n] * factorial_inv[k]) % m * factorial_inv[n - k] + m) % m;
}


