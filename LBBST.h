#ifndef LBBST_H
#define LBBST_H

#include <cstdlib>
#include <math.h>
#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
class LBBST {
public:
    LBBST();
    virtual ~LBBST();
    int getSize();
    void insert(T data);
    void remove(T data);
    bool contains(T data);
    void printTreeInOrder();
    void printTreePostOrder();
    T getMin();
    T getMax();

private:
    LBTreeNode<T>* m_root;
    int m_size;

    void insertHelper(LBTreeNode<T>*& subTreeRoot, T data);
    bool containsHelper(LBTreeNode<T>* subTreeRoot, T data);
    void printTreeInOrderHelper(LBTreeNode<T>* subTreeRoot);
    void printTreePostOrderHelper(LBTreeNode<T>* subTreeRoot);
    T getMinHelper(LBTreeNode<T>* subTreeRoot);
    T getMaxHelper(LBTreeNode<T>* subTreeRoot);
    void findTarget(T key, LBTreeNode<T>*& target, LBTreeNode<T>*& parent);
    LBTreeNode<T>* getSuccessor(LBTreeNode<T>* rightChild);
    void rebuildTree(LBTreeNode<T>*& subTreeRoot, T* values, int start, int end);
    void extractValuesInOrder(LBTreeNode<T>* subTreeRoot, T* values, int& index);
};

template <typename T>
LBBST<T>::LBBST() {
    m_root = NULL;
    m_size = 0;
}

template <typename T>
LBBST<T>::~LBBST() {
    // free memory
}

template <typename T>
int LBBST<T>::getSize() {
    return m_size;
}

template <typename T>
void LBBST<T>::insert(T data) {
    insertHelper(m_root, data);
    ++m_size;
}

template <typename T>
void LBBST<T>::insertHelper(LBTreeNode<T>*& subTreeRoot, T data) {
    if (subTreeRoot == NULL) {
        subTreeRoot = new LBTreeNode<T>(data);
    } else if (data < subTreeRoot->getData()) {
        insertHelper(subTreeRoot->m_left, data);
        ++subTreeRoot->m_leftDepth;
    } else if (data > subTreeRoot->getData()) {
        insertHelper(subTreeRoot->m_right, data);
        ++subTreeRoot->m_rightDepth;
    }

    // Check for imbalance and rebuild if necessary
    if (abs(subTreeRoot->m_leftDepth - subTreeRoot->m_rightDepth) > 1.5 * std::max(subTreeRoot->m_leftDepth, subTreeRoot->m_rightDepth)) {
        T* values = new T[m_size];
        int index = 0;
        // Extract values in sorted order
        extractValuesInOrder(subTreeRoot, values, index);
        // Rebuild the tree
        rebuildTree(subTreeRoot, values, 0, m_size - 1);
        delete[] values;
    }
}

template <typename T>
void LBBST<T>::extractValuesInOrder(LBTreeNode<T>* subTreeRoot, T* values, int& index) {
    if (subTreeRoot != NULL) {
        extractValuesInOrder(subTreeRoot->m_left, values, index);
        values[index++] = subTreeRoot->getData();
        extractValuesInOrder(subTreeRoot->m_right, values, index);
    }
}

template <typename T>
void LBBST<T>::rebuildTree(LBTreeNode<T>*& subTreeRoot, T* values, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        subTreeRoot = new LBTreeNode<T>(values[mid]);
        rebuildTree(subTreeRoot->m_left, values, start, mid - 1);
        rebuildTree(subTreeRoot->m_right, values, mid + 1, end);
    }
}

template <typename T>
bool LBBST<T>::contains(T data) {
    return containsHelper(m_root, data);
}

template <typename T>
bool LBBST<T>::containsHelper(LBTreeNode<T>* subTreeRoot, T data) {
    if (subTreeRoot == NULL) {
        return false;
    } else if (data == subTreeRoot->getData()) {
        return true;
    } else if (data < subTreeRoot->getData()) {
        return containsHelper(subTreeRoot->m_left, data);
    } else {
        return containsHelper(subTreeRoot->m_right, data);
    }
}

template <typename T>
void LBBST<T>::printTreeInOrder() {
    printTreeInOrderHelper(m_root);
}

template <typename T>
void LBBST<T>::printTreeInOrderHelper(LBTreeNode<T>* subTreeRoot) {
    if (subTreeRoot != NULL) {
        printTreeInOrderHelper(subTreeRoot->m_left);
        cout << subTreeRoot->getData() << endl;
        printTreeInOrderHelper(subTreeRoot->m_right);
    }
}

template <typename T>
void LBBST<T>::printTreePostOrder() {
    printTreePostOrderHelper(m_root);
}

template <typename T>
void LBBST<T>::printTreePostOrderHelper(LBTreeNode<T>* subTreeRoot) {
    if (subTreeRoot != NULL) {
        printTreePostOrderHelper(subTreeRoot->m_left);
        printTreePostOrderHelper(subTreeRoot->m_right);
        cout << subTreeRoot->getData() << endl;
    }
}

template <typename T>
T LBBST<T>::getMin() {
    return getMinHelper(m_root);
}

template <typename T>
T LBBST<T>::getMinHelper(LBTreeNode<T>* subTreeRoot) {
    if (subTreeRoot->m_left == NULL) {
        return subTreeRoot->getData();
    } else {
        return getMinHelper(subTreeRoot->m_left);
    }
}

template <typename T>
T LBBST<T>::getMax() {
    return getMaxHelper(m_root);
}

template <typename T>
T LBBST<T>::getMaxHelper(LBTreeNode<T>* subTreeRoot) {
    if (subTreeRoot->m_right == NULL) {
        return subTreeRoot->getData();
    } else {
        return getMaxHelper(subTreeRoot->m_right);
    }
}

template <typename T>
void LBBST<T>::findTarget(T key, LBTreeNode<T>*& target, LBTreeNode<T>*& parent) {
    while (target != NULL && target->getData() != key) {
        parent = target;
        if (key < target->getData()) {
            target = target->m_left;
        } else {
            target = target->m_right;
        }
    }
}

template <typename T>
LBTreeNode<T>* LBBST<T>::getSuccessor(LBTreeNode<T>* rightChild) {
    LBTreeNode<T>* successor = rightChild;
    while (successor->m_left != NULL) {
        successor = successor->m_left;
    }
    return successor;
}

template <typename T>
void LBBST<T>::remove(T data) {
    LBTreeNode<T>* target = m_root;
    LBTreeNode<T>* parent = NULL;
    findTarget(data, target, parent);

    if (target == NULL) {
        return;
    }

    // case 1: target has no children
    if (target->m_left == NULL && target->m_right == NULL) {
        if (parent == NULL) {
            m_root = NULL;
        } else if (parent->m_left == target) {
            parent->m_left = NULL;
        } else {
            parent->m_right = NULL;
        }
        delete target;
        --m_size;
    }
    // case 2: target has one child
    else if (target->m_left == NULL || target->m_right == NULL) {
        LBTreeNode<T>* child = target->m_left;
        if (target->m_right != NULL) {
            child = target->m_right;
        }

        if (parent == NULL) {
            m_root = child;
        } else if (parent->m_left == target) {
            parent->m_left = child;
        } else {
            parent->m_right = child;
        }
        delete target;
        --m_size;
    }
    // case 3: target has two children
    else {
        LBTreeNode<T>* successor = getSuccessor(target->m_right);
        T successorData = successor->getData();
        remove(successorData);
        target->m_data = successorData;
    }
}

#endif