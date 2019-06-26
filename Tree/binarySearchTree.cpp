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
    if (node1 == root)
    {
        if (node2 == node2->parent->left)
        {
            node2->parent->left = nullptr;
        }
        else if (node2 == node2->parent->right)
        {
            node2->parent->right = nullptr;
        }
        node2->parent = nullptr;
        root = node2;
    }
    else // node1 has a parent
    {
        if (node1 == node1->parent->left)
        {
            node1->parent->left = node2;
        }
        else
        {
            node1->parent->right = node2;
        }
        node2->parent = node1->parent;
    }
}

void BinarySearchTree::remove(int value)
{
    // skip if value not found in the tree
    BinarySearchTreeNode *nodeToRemove = search(value);
    if (search(value) == nullptr)
    {
        return;
    }

    if (nodeToRemove->left == nullptr)
    {
        transplant(nodeToRemove, nodeToRemove->right);
    }
    else if (nodeToRemove->right == nullptr)
    {
        transplant(nodeToRemove, nodeToRemove->left);
    }
    else // both children exist
    {
        // replace with the smallest descendant (guaranteed to exist and has no left child)
        BinarySearchTreeNode *smallest = nodeToRemove->right->getMinimum();
        if (smallest->parent != nodeToRemove)
        {
            transplant(smallest, smallest->right);
            smallest->right = nodeToRemove->right;
            smallest->right->parent = smallest;
        }
        transplant(nodeToRemove, smallest);
        smallest->left = nodeToRemove->left;
        smallest->left->parent = smallest;
    }
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
