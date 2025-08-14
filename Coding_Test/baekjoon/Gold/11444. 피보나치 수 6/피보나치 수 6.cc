#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using Matrix = vector<vector<ll>>;

const int MOD = 1000000007;

Matrix multiply(const Matrix& a, const Matrix& b)
{
    Matrix ret(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
            for (int j = 0; j < 2; ++j)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    return ret;
}

Matrix cal(Matrix base, ll exp)
{
    Matrix ret = {{1, 0}, {0, 1}};
    
    while (exp > 0)
    {
        if (exp & 1)
            ret = multiply(ret, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return ret;
}


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }
    
    Matrix base = {{1, 1}, {1, 0}};
    Matrix ret = cal(base, n - 1);
    
    cout << ret[0][0] << '\n';
    
    return 0;
}
