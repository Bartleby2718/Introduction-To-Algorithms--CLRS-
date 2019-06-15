#include <iostream>
#include <vector>
#include "binaryTree.h"
#include "binarySearchTree.hpp"

using namespace std;

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

    BinarySearchTree bst;
    for (int i:{4, 2, 6, 1, 3, 5, 7})
    {
        auto newNode = new BinarySearchTreeNode(i);
        bst.insert(newNode);
        bst.printMinimum();
        bst.printMaximum();
    }
    for (int i = 0; i <= 8; ++i)
    {
        bst.find(i);
    }

    bst.traverseInOrder();

    auto eight = new BinarySearchTreeNode(8);
    BinarySearchTreeNode *beforeEight = bst.getPredecessor(eight);
    cout << "bst.getPredecessor(eight): "
         << ((beforeEight == nullptr) ? "Does not exist" : to_string(beforeEight->getValue())) << endl;

    BinarySearchTreeNode *seven = bst.getMaximum();
    BinarySearchTreeNode *afterSeven = bst.getSuccessor(seven);
    cout << "bst.getSuccessor(seven): "
         << ((afterSeven == nullptr) ? "Does not exist" : to_string(afterSeven->getValue())) << endl;
    return 0;
}
