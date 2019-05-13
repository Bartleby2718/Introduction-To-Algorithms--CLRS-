#include <stdio.h>
#include <limits.h>


struct result
{
    const int *const array;
    size_t from;
    size_t to;
};

struct result maximumCrossingSubarray(struct result r)
{
    const int *const array = r.array;
    size_t from = r.from;
    size_t to = r.to;
    size_t length = to - from + 1, mid = (length >> 1U) - 1;

    int i, sum;
    int leftSum = INT_MIN, rightSum = INT_MIN;
    size_t leftIndex = -1, rightIndex = -1;
    for (i = mid, sum = 0; i >= 0; --i)
    {
        sum += array[i];
        if (sum >= leftSum)
        {
            leftSum = sum;
            leftIndex = i;
        }
    }
    for (i = mid + 1, sum = 0; i < length; ++i)
    {
        sum += array[i];
        if (sum >= rightSum)
        {
            rightSum = sum;
            rightIndex = i;
        }
    }
    struct result a = {array, leftIndex, rightIndex};
    return a;
}

struct result maximumSubarray(struct result r)
{
    const int *const array = r.array;
    size_t from = r.from;
    size_t to = r.to;
    if (from == to)
    {
        return r;
    }
    int i, sumA = 0, sumB = 0, sumC = 0;
    size_t length = to - from + 1, start = 0, mid = (length >> 1U) - 1;


    struct result a = {array, start, mid};
    for (i = start; i < mid; ++i)
    {
        sumA += array[i];
    }
    struct result b = {array, mid + 1, length - 1};
    for (i = mid + 1; i < length - 1; ++i)
    {
        sumA += array[i];
    }
    struct result c = maximumCrossingSubarray(r);
    for (i = c.from; i <= c.to; ++i)
    {
        sumC += array[i];
    }
    if (sumA >= sumB >= sumC)
    {
        return a;
    } else
    {
        return (sumB >= sumC) ? b : c;
    }
}

int main()
{
    int arr[] = {8, -3, 2, -4, 5, -7, 1, -6};
    int *pInt = arr;
    struct result r = {pInt, 0, 7};
    struct result a = maximumSubarray(r);
    printf("expected 0~4, got %lu~%lu.\n", a.from, a.to);

    int arr2[] = {-8, -3, 2, -4, 5, 7, 1, -6};
    pInt = arr2;
    struct result r2 = {pInt, 0, 7};
    struct result b = maximumSubarray(r2);
    printf("expected 2~6, got %lu~%lu.\n", b.from, b.to);

    int arr3[] = {-8, 3, -2, 4, 5, 0, -1, 6};
    pInt = arr3;
    struct result r3 = {pInt, 0, 7};
    struct result c = maximumSubarray(r3);
    printf("expected 1~7, got %lu~%lu.\n", c.from, c.to);

    int arr4[] = {-1};
    pInt = arr4;
    struct result r4 = {pInt, 0, 0};
    struct result d = maximumSubarray(r4);
    printf("expected 0~0, got %lu~%lu.\n", d.from, d.to);

    return 0;
}