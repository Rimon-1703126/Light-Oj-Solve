#include<bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;
#define REP(i,n) for (ll i = 1; i <= n; i++)
typedef vector<vector<ll> > matrix;
ll MOD = 1000000007;
const ll K = 6;
ll a1, b1, c1;
ll a2, b2, c2;
ll f0, f1, f2;
ll g0, g1, g2, res1, res2;

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
void fib(ll N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = f2%MOD;
    F1[2] = f1%MOD;
    F1[3] = f0%MOD;
    F1[4] = g2%MOD;
    F1[5] = g1%MOD;
    F1[6] = g0%MOD;

    matrix T(K+1, vector<ll>(K+1));
    for(ll i=1; i<=6; i++){
        for(ll j=1; j<=6; j++)
            T[i][j]=0;
    }
    T[1][1] = a1, T[1][2] = b1, T[1][6]=c1;
    T[2][1] = 1;
    T[3][2] = 1;
    T[4][3]=c2;
    T[4][4]=a2;
    T[4][5]=b2;
    T[5][4]=1;
    T[6][5]=1;
    T = pow(T, N-2);
    ll res = 0;
    res1=res2=0;
    REP(i, K)
    res1 = (res1 + T[1][i] * F1[i]) % MOD;
    REP(i, K)
    res2 = (res2 + T[4][i] * F1[i]) % MOD;
}

int main()
{
    ll i,j, n, p=2,m, t,a,b ;
    cin >> t;
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld%lld",&a1,&b1,&c1);
        scanf("%lld%lld%lld",&a2,&b2,&c2);
        scanf("%lld%lld%lld",&f0,&f1,&f2);
        scanf("%lld%lld%lld",&g0,&g1,&g2);
        scanf("%lld%lld",&MOD,&n);
        printf("Case %lld:\n", i);
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&a);
            if(a>2){
                fib(a);
                printf("%lld %lld\n",res1, res2);
            }
            else
            {
                if(a==0)
                {
                    printf("%lld %lld\n", f0%MOD, g0%MOD);
                }
                else if(a==1)
                {
                    printf("%lld %lld\n", f1%MOD, g1%MOD);
                }
                else
                    printf("%lld %lld\n", f2%MOD, g2%MOD);
            }
        }

    }
    return 0;
}
