//
// Created by bartl on 06/15/2019.
//
#include <iostream>
#include "binarySearchTree.hpp"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

void BinarySearchTree::insert(BinarySearchTreeNode *newNode)
{
    BinarySearchTreeNode *parentNode = nullptr;
    BinarySearchTreeNode *node = root;
    while (node != nullptr)
    {
        parentNode = node;
        node = (newNode->value < node->value) ? (node->left) : (node->right);
    }
    newNode->parent = parentNode;
    if (parentNode == nullptr)
    {
        root = newNode;
    }
    else
    {
        if (newNode->value < parentNode->value)
        {
            parentNode->left = newNode;
        }
        else
        {
            parentNode->right = newNode;
        }
    }
    cout << "Inserted " << newNode->value << " to the tree." << endl;
}

void BinarySearchTree::transplant(BinarySearchTreeNode *node1, BinarySearchTreeNode *node2)
{
    // TODO
}

void BinarySearchTree::remove(int value)
{
    // TODO
}

void BinarySearchTree::traverseInOrder() const
{
    root->traverseInOrder();
}

void BinarySearchTree::find(int target) const
{
    cout << target << " is " << ((search(target) == nullptr) ? "not " : "")
         << "in the tree." << endl;
}

void BinarySearchTree::printMinimum() const
{
    BinarySearchTreeNode *min = getMinimum();
    if (min != nullptr)
    {
        cout << "Current minimum value: " << min->value << endl;
    }
}

void BinarySearchTree::printMaximum() const
{
    BinarySearchTreeNode *max = getMaximum();
    if (max != nullptr)
    {
        cout << "Current maximum value: " << max->value << endl;
    }
}

BinarySearchTreeNode *BinarySearchTree::search(int target) const
{
    return root->search(target);
}

BinarySearchTreeNode *BinarySearchTree::getMinimum() const
{
    return root->getMinimum();
}

BinarySearchTreeNode *BinarySearchTree::getMaximum() const
{
    return root->getMaximum();
}

bool BinarySearchTree::nullOrNotInTree(BinarySearchTreeNode *node) const
{
    BinarySearchTreeNode *x = node;
    if (x == nullptr)
    {
        return true;
    }
    while (x->parent != nullptr)
    {
        x = x->parent;
    }
    return x != root;
}

BinarySearchTreeNode *BinarySearchTree::getPredecessor(BinarySearchTreeNode *node) const
{
    if (nullOrNotInTree(node))
    {
        return nullptr; // nullptr if the node is not in the tree
    }
    return node->getPredecessor();
}

BinarySearchTreeNode *BinarySearchTree::getSuccessor(BinarySearchTreeNode *node) const
{
    if (nullOrNotInTree(node))
    {
        return nullptr; // nullptr if the node is not in the tree
    }
    return node->getSuccessor();
}
