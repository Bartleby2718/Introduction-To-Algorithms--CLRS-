//
// Created by bartl on 06/15/2019.
//

#ifndef TREE_BINARYSEARCHTREENODE_HPP
#define TREE_BINARYSEARCHTREENODE_HPP

#endif //TREE_BINARYSEARCHTREENODE_HPP

class BinarySearchTreeNode
{
    int value;
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
    BinarySearchTreeNode *parent;
public:
    explicit BinarySearchTreeNode(int newValue);

    int getValue() const;

    void traverseInOrder();

    BinarySearchTreeNode *search(int target);

    BinarySearchTreeNode *getMinimum();

    BinarySearchTreeNode *getMaximum();

    BinarySearchTreeNode *getPredecessor();

    BinarySearchTreeNode *getSuccessor();

    friend class BinarySearchTree;
};
