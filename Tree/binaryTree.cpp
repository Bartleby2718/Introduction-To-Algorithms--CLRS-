//
// Created by bartl on 05/27/2019.
//

#include <iostream>
#include "binaryTree.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    delete root;
}

void BinaryTree::buildTree(std::vector<int> &list)
{
    if (!list.empty())
    {
        root = new BinaryTreeNode(list.front());
    }
    for (int i = 1; i < list.size(); ++i)
    {
        std::vector<bool> remainders;
        int index = i;
        while (index > 0)
        {
            remainders.push_back((index - 1) % 2 == 0);
            index = (index - 1) / 2;
        }
        BinaryTreeNode *current = root;
        for (auto iterator = remainders.rbegin(); iterator + 1 != remainders.rend(); ++iterator)
        {
            bool goLeft = *iterator;
            current = (goLeft) ? (current->left) : (current->right);
        }
        int key = list.at(i);
        bool goLeft = remainders.front();
        ((goLeft) ? (current->left) : (current->right)) = new BinaryTreeNode(key);
    }
}

void BinaryTree::traversePreOrderRecursive()
{
    if (root != nullptr)
    {
        std::cout << "pre-order traversal (recursive):";
        root->printPreOrderRecursive();
        std::cout << std::endl;
    }
}

void BinaryTree::traverseInOrderRecursive()
{
    if (root != nullptr)
    {
        std::cout << "in-order traversal (recursive):";
        root->printInOrderRecursive();
        std::cout << std::endl;
    }
}

void BinaryTree::traversePostOrderRecursive()
{
    if (root != nullptr)
    {
        std::cout << "post-order traversal (recursive):";
        root->printPostOrderRecursive();
        std::cout << std::endl;
    }
}

void BinaryTree::traversePreOrderNonRecursive()
{
    if (root != nullptr)
    {
        std::cout << "pre-order traversal (non-recursive):";
        root->printPreOrderNonRecursive();
        std::cout << std::endl;
    }
}

void BinaryTree::traverseInOrderNonRecursive()
{
    if (root != nullptr)
    {
        std::cout << "in-order traversal (non-recursive):";
        root->printInOrderNonRecursive();
        std::cout << std::endl;
    }
}

void BinaryTree::traversePostOrderNonRecursive()
{
    if (root != nullptr)
    {
        std::cout << "post-order traversal (non-recursive):";
        root->printPostOrderNonRecursive();
        std::cout << std::endl;
    }
}
