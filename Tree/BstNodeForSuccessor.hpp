//
// Created by bartl on 06/26/2019.
//
#ifndef TREE_BSTNODEFORSUCCESSOR_HPP
#define TREE_BSTNODEFORSUCCESSOR_HPP

class BstNodeForSuccessor
{
    const int value;
    BstNodeForSuccessor *left;
    BstNodeForSuccessor *right;
    BstNodeForSuccessor *successor;
public:
    explicit BstNodeForSuccessor(int value);

    void printValue() const;

    const BstNodeForSuccessor *getMinimum() const;

    const BstNodeForSuccessor *getMaximum() const;

    void printMinMax() const;

    void traverseInOrder() const;

    const BstNodeForSuccessor *search(int target) const;

    BstNodeForSuccessor *insert(int target);

    friend class BstWithSuccessor;
};

#endif //TREE_BSTNODEFORSUCCESSOR_HPP
