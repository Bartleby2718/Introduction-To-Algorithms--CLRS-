//
// Created by bartl on 06/26/2019.
//
#include <iostream>
#include "BstWithSuccessor.hpp"

using namespace std;

BstWithSuccessor::BstWithSuccessor()
{
    root = nullptr;
}

void BstWithSuccessor::insert(int value)
{
    if (root == nullptr)
    {
        root = new BstNodeForSuccessor(value);
    }
    else
    {
        root->insert(value);
    }
}

void BstWithSuccessor::transplant(BstNodeForSuccessor *node1, BstNodeForSuccessor *node2)
{
    // TODO
}

void BstWithSuccessor::remove(int value)
{
    // TODO
}

void BstWithSuccessor::traverseInOrder() const
{
    root->traverseInOrder();
}

const BstNodeForSuccessor *BstWithSuccessor::search(int target) const
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        return root->search(target);
    }
}

const BstNodeForSuccessor *BstWithSuccessor::getMinimum() const
{
    return (root == nullptr) ? nullptr : (root->getMinimum());
}

const BstNodeForSuccessor *BstWithSuccessor::getMaximum() const
{
    return (root == nullptr) ? nullptr : (root->getMaximum());
}

void BstWithSuccessor::printMinMax() const
{
    if (root != nullptr)
    {
        root->printMinMax();
    }
}

const BstNodeForSuccessor *BstWithSuccessor::getPredecessor(const BstNodeForSuccessor *node) const
{
    if (node->left == nullptr) // need to find the lowest "left ancestor"
    {
        const BstNodeForSuccessor *current = node;
        const BstNodeForSuccessor *parent = getParent(current);
        while (parent != nullptr && parent->left == current)
        {
            current = parent;
            parent = getParent(current);
        }
        return parent;
    }
    else // has a left child
    {
        return node->left->getMaximum();
    }
}

const BstNodeForSuccessor *BstWithSuccessor::getParent(const BstNodeForSuccessor *node) const
{
    // start from the root, as suggested in https://stackoverflow.com/a/32755803/4370146
    // because it is impossible to get the "left parent" from left, right, and successor
    if (root == nullptr || search(node->value) == nullptr) // ignore nodes that are not in the tree
    {
        return nullptr;
    }

    // node is in the tree and has a parent
    BstNodeForSuccessor *parent = nullptr;
    BstNodeForSuccessor *current = root;
    while (current->value != node->value)
    {
        parent = current;
        current = (node->value < current->value) ? (current->left) : (current->right);
    }
    return parent;
}

void BstWithSuccessor::insert1Through7()
{
    for (int i:{4, 2, 6, 1, 3, 5, 7}) // to make the tree balanced
    {
        insert(i);
        printMinMax();
    }
}

void BstWithSuccessor::testGetPredecessor()
{
    const BstNodeForSuccessor *node = getMaximum();
    node->printValue();
    while (getPredecessor(node) != nullptr)
    {
        node = getPredecessor(node);
        node->printValue();
    }
}
