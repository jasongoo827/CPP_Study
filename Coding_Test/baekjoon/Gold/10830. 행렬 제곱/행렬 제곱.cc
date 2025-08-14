#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

class Matrix
{
public:
    Matrix(int size): n(size)
    {
        mat.assign(n, vector<int>(n, 0));
    }
    static Matrix identity(int size)
    {
        Matrix I(size);
        for (int i = 0; i < size; ++i)
            I.mat[i][i] = 1;
        return I;
    }
    Matrix operator*(Matrix& other)
    {
        Matrix ret(n);
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    ret.mat[i][j] = (ret.mat[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % 1000;
        return ret;
    }
    Matrix cal(ll exp)
    {
        Matrix ret = Matrix::identity(n);
        Matrix base = *this;
        while (exp > 0)
        {
            if (exp & 1)
                ret = ret * base;
            base = base * base;
            exp /= 2;
        }
        return ret;
    }
    
    int n;
    vector<vector<int>> mat;
};

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll b;
    cin >> n >> b;
    
    Matrix a(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a.mat[i][j];
    
    Matrix ret = a.cal(b);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << ret.mat[i][j] << " ";
        cout << '\n';
    }
    
    return 0;
}
