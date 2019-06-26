//
// Created by bartl on 06/26/2019.
//
#ifndef TREE_BSTWITHSUCCESSOR_HPP
#define TREE_BSTWITHSUCCESSOR_HPP

#include "BstNodeForSuccessor.hpp"

class BstWithSuccessor
{
    BstNodeForSuccessor *root;
public:
    BstWithSuccessor();

    void insert(int value);

    void transplant(BstNodeForSuccessor *node1, BstNodeForSuccessor *node2);

    void remove(int value);

    void traverseInOrder() const;

    const BstNodeForSuccessor *search(int target) const;

    const BstNodeForSuccessor *getMinimum() const;

    const BstNodeForSuccessor *getMaximum() const;

    void printMinMax() const;

    const BstNodeForSuccessor *getPredecessor(const BstNodeForSuccessor *node) const;

    const BstNodeForSuccessor *getParent(const BstNodeForSuccessor *node) const;

    /* test methods */
    void insert1Through7();

    void testGetPredecessor();
};

#endif //TREE_BSTWITHSUCCESSOR_HPP
