//
// Created by bartl on 05/27/2019.
//

#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H

#include <vector>
#include "binaryTreeNode.h"

class BinaryTree
{
    BinaryTreeNode *root;
public:
    BinaryTree();

    ~BinaryTree();

    void buildTree(std::vector<int> &list); // helper function

    void traversePreOrderRecursive();

    void traverseInOrderRecursive();

    void traversePostOrderRecursive();

    void traversePreOrderNonRecursive();

    void traverseInOrderNonRecursive();

    void traversePostOrderNonRecursive();
};

#endif //TREE_BINARYTREE_H
