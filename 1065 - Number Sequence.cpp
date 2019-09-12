#include<bits/stdc++.h>
#include <vector>
#define REP(i,n) for (ll i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
ll MOD = 1000000007,a,b;
const ll K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
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
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = b%MOD;
    F1[2] = a%MOD;
    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 1, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 0;
    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);
    
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int main()
{
    ll t, i, j, m,n;
    cin >> t;
    for(i=1; i<=t; i++){
        scanf("%lld%lld%lld%lld",&a, &b, &n, &m);
        ll p=1;
        for(j=1; j<=m; j++){
            p*=10;
            MOD = p;
        }
        //cout << p << endl;
        printf("Case %lld: %lld\n",i,fib(n));
    }
    return 0;
}
