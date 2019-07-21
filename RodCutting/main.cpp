#include <cassert>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int getValueWithRecursion(const vector<int> &prices, int length)
{
    // base case
    if (length == 0)
    {
        return 0;
    }
    int value = 0;
    for (int i = 1; i <= length; ++i)
    {
        int afterCut = prices[i - 1] + getValueWithRecursion(prices, length - i);
        value = max(value, afterCut);
    }
    return value;
}

int getValueWithMemoizationAux(const vector<int> &prices, int length, vector<int> &values)
{
    if (length == 0)
    {
        return 0;
    }
    int value = values[length - 1];
    if (value >= 0) // calculated
    {
        return value;
    }
    for (int i = 1; i <= length; ++i)
    {
        int afterCut = prices[i - 1] + getValueWithMemoizationAux(prices, length - i, values);
        value = max(value, afterCut);
    }
    values[length - 1] = value;
    return values[length - 1];
}

int getValueWithMemoizationTopDown(const vector<int> &prices, int length)
{
    vector<int> values;
    for (int i = 0; i < prices.size(); ++i)
    {
        values.push_back(-1); // uncalculated
    }
    return getValueWithMemoizationAux(prices, length, values);
}

int getValueWithMemoizationBottomUp(const vector<int> &prices, int length)
{
    vector<int> values(length); // also zero-based
    for (int i = 1; i <= length; ++i) // rod length to examine
    {
        int value = prices[i - 1]; // uncut value
        for (int j = 1; j < i; ++j) // length to be cut out
        {
            value = max(value, prices[j - 1] + values[(i - j) - 1]);
        }
        values[i - 1] = value;
    }
    return values[length - 1];
}

void printChunkLengthsWithMemoizationBottomUp(const vector<int> &prices, int length)
{
    vector<int> chunks(length); // stores first piece to cut off for each length
    vector<int> values(length);
    for (int i = 1; i <= length; ++i) // rod length to examine
    {
        chunks[i - 1] = i;
        int value = prices[i - 1]; // uncut value
        for (int j = 1; j < i; ++j) // length to be cut out
        {
            int valueWhenDivided = prices[j - 1] + values[(i - j) - 1];
            if (valueWhenDivided > value)
            {
                value = valueWhenDivided;
                chunks[i - 1] = j;
            }
        }
        values[i - 1] = value;
    }
    int chunk = chunks[length - 1], price = prices[chunk - 1];
    cout << price << "(length " << chunk << ")";
    while (length -= chunk, length > 0)
    {
        chunk = chunks[length - 1], price = prices[chunk - 1];
        cout << "+" << price << "(length " << chunk << ")";
    }
    cout << endl;
}

long getNthFibonacci(int n)
{
    long sequence[n + 1];
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        sequence[i] = sequence[i - 2] + sequence[i - 1];
    }
    return sequence[n];
}

int main()
{
    vector<int> prices = {
            1, 5, 8, 9, 10,
            17, 17, 20, 24, 30,
            36, 43, 50, 55, 60,
            62, 71, 75, 80, 85,
            90, 92, 95, 96, 99,
            100, 101, 103, 109, 115,
    };
    int length = 30;
    assert(length <= prices.size());

    clock_t begin, end;

    // takes about 7 seconds for length 30 in my laptop
    begin = clock();
    cout << getValueWithRecursion(prices, length) << endl;
    end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    cout << getValueWithMemoizationTopDown(prices, length) << endl;
    end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    cout << getValueWithMemoizationBottomUp(prices, length) << endl;
    end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC << endl;

    /** #15.1-4 Return the actual solution for rod cutting */
    printChunkLengthsWithMemoizationBottomUp(prices, length);

    /** #15.1-5 Compute the Fibanocci number in O(n) */
    cout << getNthFibonacci(10) << endl;
    return 0;
}
