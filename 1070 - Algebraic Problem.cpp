#include<bits/stdc++.h>
#include <vector>
typedef unsigned long long  ll;
#define REP(i,n) for (ll i = 1; i <= n; i++)
using namespace std;
typedef vector<vector<ll> > matrix;
ll p,q, n;
const ll K = 2;

matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
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
    F1[1] = p;
    F1[2] = 2;
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = p, T[1][2] = -q;
    T[2][1] = 1, T[2][2] = 0;
    if (N == 1)
        return p;
    T = pow(T, N-1);
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]);
    return res;
}

int main()
{
    ll t, i, j, m=1, pp=2;
    cin >> t;
    for(i=1; i<=t; i++){
        cin >> p >> q >> n;
        printf("Case ");
        cout << i << ": ";
        if(n==0){
            printf("2\n");
        }
        else if(n==1){
            cout << p << endl;
        }
        else
        cout << fib(n)<< endl;
        }
    return 0;
}
