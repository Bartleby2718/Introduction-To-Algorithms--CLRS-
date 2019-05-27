//
// Created by bartl on 05/27/2019.
//

#ifndef TREE_BINARYTREENODE_H
#define TREE_BINARYTREENODE_H

class BinaryTreeNode
{
    int key;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
public:
    explicit BinaryTreeNode(int key);

    ~BinaryTreeNode();

    void printPreOrderRecursive();

    void printInOrderRecursive();

    void printPostOrderRecursive();

    void printPreOrderNonRecursive();

    void printInOrderNonRecursive();

    void printPostOrderNonRecursive();

    friend class BinaryTree;
};

#endif //TREE_BINARYTREENODE_H
