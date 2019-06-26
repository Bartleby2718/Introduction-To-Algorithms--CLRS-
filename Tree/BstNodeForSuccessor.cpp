//
// Created by bartl on 06/26/2019.
//
#include <iostream>
#include "BstNodeForSuccessor.hpp"

using namespace std;

BstNodeForSuccessor::BstNodeForSuccessor(int value)
        : value(value), left(nullptr), right(nullptr), successor(nullptr)
{
}

void BstNodeForSuccessor::printValue() const
{
    cout << value << ' ';
}

const BstNodeForSuccessor *BstNodeForSuccessor::getMinimum() const
{
    const BstNodeForSuccessor *node = this;
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

const BstNodeForSuccessor *BstNodeForSuccessor::getMaximum() const
{
    const BstNodeForSuccessor *node = this;
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

void BstNodeForSuccessor::printMinMax() const
{
    cout << "Min: " << getMinimum()->value << ", Max: " << getMaximum()->value << endl;
}

void BstNodeForSuccessor::traverseInOrder() const
{
    const BstNodeForSuccessor *node = getMinimum();
    while (node != nullptr)
    {
        cout << node->value << ' ';
        node = node->successor;
    }
}

const BstNodeForSuccessor *BstNodeForSuccessor::search(int target) const
{
    if (value == target)
    {
        return this;
    }
    else if (target < value)
    {
        return (left == nullptr) ? nullptr : left->search(target);
    }
    else // target > value
    {
        return (right == nullptr) ? nullptr : right->search(target);
    }
}

BstNodeForSuccessor *BstNodeForSuccessor::insert(int target)
{
    if (target < value)
    {
        if (left == nullptr)
        {
            return (left = new BstNodeForSuccessor(target));
        }
        else
        {
            return left->insert(target);
        }
    }
    else if (target > value)
    {
        if (right == nullptr)
        {
            return (right = new BstNodeForSuccessor(target));
        }
        else
        {
            return right->insert(target);
        }
    }
    else
    {
        return this;
    }
}
