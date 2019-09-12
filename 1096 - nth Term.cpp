#include<bits/stdc++.h>
#include <vector>
typedef long long ll;
#define REP(i,n) for (ll i = 1; i <= n; i++)
using namespace std;
typedef vector<vector<ll> > matrix;
ll MOD = 10007,a,b, c;
const ll K = 4;

matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

ll fib(ll N)
{
    vector<ll> F1(K+1);
    F1[1] = c%MOD;
    F1[2] = 0;
    F1[3] = 0;
    F1[4] = 1;
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = a, T[1][2] = 0, T[1][3] = b, T[1][4] = c;
    T[2][1] = 1, T[2][2] = 0, T[2][3] = 0, T[2][4] = 0;
    T[3][1] = 0, T[3][2] = 1, T[3][3] = 0, T[3][4] = 0;
    T[4][1] = 0, T[4][2] = 0, T[4][3] = 0, T[4][4]=1;
    if (N <=2)
        return 0;
    T = pow(T, N-3);
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return (res)%MOD;
}

int main()
{
    ll t, i, j, m,n;
    cin >> t;
    for(i=1; i<=t; i++){
        scanf("%lld%lld%lld%lld",&n,&a, &b, &c);

        printf("Case %lld: %lld\n",i,fib(n)%MOD);
    }
    return 0;
}
