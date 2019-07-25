#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

using namespace std;

tuple<const vector<vector<int>>, const vector<vector<int>>> getMatrixChainOrder(const vector<int>& dimensions)
{
    int numMatrix = dimensions.size() - 1;
    vector<vector<int>> sums(numMatrix, vector<int>(numMatrix));
    vector<vector<int>> splits(numMatrix - 1, vector<int>(numMatrix));
    for (int i = 0; i < numMatrix; ++i)
    {
        sums[i][i] = 0;
    }
    for (int length = 2; length <= numMatrix; ++length)
    {
        for (int i = 0; i < numMatrix - length + 1; ++i)
        {
            int j = i + length - 1;
            sums[i][j] = numeric_limits<int>::max();
            for (int split = i; split < j; ++split)
            {
                int sum =
                        sums[i][split] + sums[split + 1][j] + dimensions[i] * dimensions[split + 1] * dimensions[j + 1];
                if (sum < sums[i][j])
                {
                    sums[i][j] = sum;
                    splits[i][j] = split;
                }
            }
        }
    }
    return make_pair(sums, splits);
}

void printOptimalParenthesization(const vector<vector<int>>& splits, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        printOptimalParenthesization(splits, i, splits[i][j]);
        printOptimalParenthesization(splits, splits[i][j] + 1, j);
        cout << ")";
    }
}

struct Matrix
{
    Matrix() = default;
};

inline Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
    return {};
}

Matrix matrixChainMultiply(const vector<Matrix>& matrices, const vector<vector<int>>& splits, int i, int j)
{
    if (i == j)
    {
        return matrices[i];
    }
    else
    {
        int splitIndex = splits[i][j];
        Matrix product1 = matrixChainMultiply(matrices, splits, i, splitIndex);
        Matrix product2 = matrixChainMultiply(matrices, splits, splitIndex + 1, j);
        return product1 * product2;
    }
}

int main()
{
    /** #15.2-1 Optimal parenthesization of a matrix-chain product */
    vector<vector<int>> sums;
    vector<vector<int>> splits;
    const vector<int> dimensions = {5, 10, 3, 12, 5, 50, 6};
    tie(sums, splits) = getMatrixChainOrder(dimensions);
    printOptimalParenthesization(splits, 0, dimensions.size() - 2);

    /** #15.2-2 Recursive algorithm that actually performs the optimal matrix-chain multiplication */
    vector<Matrix> matrices;
    matrixChainMultiply(matrices, splits, 0, dimensions.size() - 2);
    return 0;
}
