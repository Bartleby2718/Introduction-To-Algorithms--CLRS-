//
// Created by bartl on 06/15/2019.
//
#include <iostream>
#include "BinarySearchTreeNode.hpp"

using namespace std;

BinarySearchTreeNode::BinarySearchTreeNode(int newValue)
{
    value = newValue;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

int BinarySearchTreeNode::getValue() const
{
    return value;
}

void BinarySearchTreeNode::traverseInOrder()
{
    BinarySearchTreeNode *node = getMinimum();
    while (node != nullptr)
    {
        cout << node->value << ' ';
        node = node->getSuccessor();
    }
    cout << endl;
}

BinarySearchTreeNode *BinarySearchTreeNode::search(int target)
{
    BinarySearchTreeNode *node = this;
    while (node != nullptr)
    {
        if (target < node->value)
        {
            node = node->left;
        }
        else if (target > node->value)
        {
            node = node->right;
        }
        else
        {
            return node;
        }
    }
    return nullptr;
}

BinarySearchTreeNode *BinarySearchTreeNode::getMinimum()
{
    BinarySearchTreeNode *node = this;
    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

BinarySearchTreeNode *BinarySearchTreeNode::getMaximum()
{
    BinarySearchTreeNode *node = this;
    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

BinarySearchTreeNode *BinarySearchTreeNode::getPredecessor()
{
    BinarySearchTreeNode *node = this;
    if (node->left == nullptr)
    {
        while (node->parent != nullptr && node->parent->value > node->value)
        {
            node = node->parent;
        }
        return (node->parent == nullptr) ? nullptr : node->parent;
    }
    else
    {
        return node->left->getMaximum();
    }
}

BinarySearchTreeNode *BinarySearchTreeNode::getSuccessor()
{
    BinarySearchTreeNode *node = this;
    if (node->right == nullptr)
    {
        while (node->parent != nullptr && node->parent->value < node->value)
        {
            node = node->parent;
        }
        return (node->parent == nullptr) ? nullptr : node->parent;
    }
    else
    {
        return node->right->getMinimum();
    }
}
