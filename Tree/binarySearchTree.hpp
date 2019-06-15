//
// Created by bartl on 06/15/2019.
//

#ifndef TREE_BINARYSEARCHTREE_HPP
#define TREE_BINARYSEARCHTREE_HPP

#include "BinarySearchTreeNode.hpp"

class BinarySearchTree
{
    BinarySearchTreeNode *root;
public:
    BinarySearchTree();

    void insert(BinarySearchTreeNode *newNode);

    void transplant(BinarySearchTreeNode *node1, BinarySearchTreeNode *node2);

    void remove(int value);

    void traverseInOrder() const;

    void find(int target) const;

    void printMinimum() const;

    void printMaximum() const;

    BinarySearchTreeNode *search(int target) const;

    BinarySearchTreeNode *getMinimum() const;

    BinarySearchTreeNode *getMaximum() const;

    bool nullOrNotInTree(BinarySearchTreeNode *node) const;

    BinarySearchTreeNode *getPredecessor(BinarySearchTreeNode *node) const;

    BinarySearchTreeNode *getSuccessor(BinarySearchTreeNode *node) const;
};

#endif //TREE_BINARYSEARCHTREE_HPP
