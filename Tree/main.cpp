#include <vector>
#include "binaryTree.h"

int main()
{
    std::vector<int> sortedList = {1, 2, 3, 4, 5, 6, 7, 8};
    BinaryTree bt;
    bt.buildTree(sortedList);
    // In the slides, print() seems to be in the tree class,
    // but my print() functions are in the tree node class.
    // In the following functions, root calls print()
    bt.traversePreOrderRecursive();
    bt.traverseInOrderRecursive();
    bt.traversePostOrderRecursive();
    bt.traversePreOrderNonRecursive();
    bt.traverseInOrderNonRecursive();
    bt.traversePostOrderNonRecursive();
    return 0;
}

