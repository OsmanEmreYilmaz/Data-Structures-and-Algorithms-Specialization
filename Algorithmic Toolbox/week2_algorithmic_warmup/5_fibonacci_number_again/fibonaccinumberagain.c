#include <stdio.h>

void multiply(int F[2][2], int M[2][2], long long mod){
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x % mod;
    F[0][1] = y % mod;
    F[1][0] = z % mod;
    F[1][1] = w % mod;
}

void power(int F[2][2], int n,long long mod){
    if( n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};

    power(F, n/2,mod);
    multiply(F, F,mod);

    if (n%2 != 0)
        multiply(F, M,mod);
}

long long LastDigitofaLargeFibonacciNumber(long long n,long long mod){
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1,mod);
    return F[0][0];
}

int main(){
    long long n,m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    printf("%lld\n",LastDigitofaLargeFibonacciNumber(n,m));
    return 0;
}
