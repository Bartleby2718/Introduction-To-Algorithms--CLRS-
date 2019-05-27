//
// Created by bartl on 05/27/2019.
//
#include <iostream>
#include <stack>
#include "binaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(int key) : key(key)
{
    left = nullptr;
    right = nullptr;
}

BinaryTreeNode::~BinaryTreeNode()
{
    delete left;
    delete right;
}

void BinaryTreeNode::printPreOrderRecursive()
{
    /** 10.4-2 recursive O(n) print */
    std::cout << ' ' << key;
    if (left != nullptr)
    {
        left->printPreOrderRecursive();
    }
    if (right != nullptr)
    {
        right->printPreOrderRecursive();
    }
}

void BinaryTreeNode::printInOrderRecursive()
{
    /** 10.4-2 recursive O(n) print */
    if (left != nullptr)
    {
        left->printInOrderRecursive();
    }
    std::cout << ' ' << key;
    if (right != nullptr)
    {
        right->printInOrderRecursive();
    }
}

void BinaryTreeNode::printPostOrderRecursive()
{
    /** 10.4-2 recursive O(n) print */
    if (left != nullptr)
    {
        left->printPostOrderRecursive();
    }
    if (right != nullptr)
    {
        right->printPostOrderRecursive();
    }
    std::cout << ' ' << key;
}

void BinaryTreeNode::printPreOrderNonRecursive()
{
    /** 10.4-3 non-recursive O(n) print */
    std::stack<BinaryTreeNode *> s;
    s.push(this);
    while (!s.empty())
    {
        BinaryTreeNode *current = s.top();
        std::cout << ' ' << current->key;
        s.pop();
        if (current->right != nullptr)
        {
            s.push(current->right);
        }
        if (current->left != nullptr)
        {
            s.push(current->left);
        }
    }
}

void BinaryTreeNode::printInOrderNonRecursive()
{
    /** 10.4-3 non-recursive O(n) print */
    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    std::stack<BinaryTreeNode *> s;
    BinaryTreeNode *current = this;
    while (current != nullptr)
    {
        s.push(current);
        current = current->left;
    }
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        std::cout << ' ' << current->key;
        current = current->right;
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
    }
}

void BinaryTreeNode::printPostOrderNonRecursive()
{
    /** 10.4-3 non-recursive O(n) print */
    // from https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
    std::stack<BinaryTreeNode *> s;
    BinaryTreeNode *current = this;
    do
    {
        while (current != nullptr)
        {
            if (current->right != nullptr)
            {
                s.push(current->right);
            }
            s.push(current);
            current = current->left;
        }
        current = s.top(); // has no left child
        s.pop();
        // determine whether a node and its right child were both pushed
        if (!s.empty() && (current->right == s.top()))
        {
            s.pop();
            s.push(current);
            current = current->right;
        }
        else
        {
            std::cout << ' ' << current->key;
            current = nullptr; // no need to go left
        }
    } while (!s.empty());
}
