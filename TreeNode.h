#ifndef _TREENODE_H_
#define _TREENODE_H_

template <typename T>
class LBTreeNode {
public:
    LBTreeNode(T data);
    virtual ~LBTreeNode();
    T getData();

    template <typename S>
    friend class LBBST;

private:
    T m_data;
    int m_leftDepth;
    int m_rightDepth;
    LBTreeNode<T>* m_left;
    LBTreeNode<T>* m_right;
};

template <typename T>
LBTreeNode<T>::LBTreeNode(T data) {
    m_data = data;
    m_left = NULL;
    m_right = NULL;
    m_leftDepth = 0;
    m_rightDepth = 0;
}

template <typename T>
LBTreeNode<T>::~LBTreeNode() {
    if (m_left != NULL) {
        delete m_left;
    }
    if (m_right != NULL) {
        delete m_right;
    }
}

template <typename T>
T LBTreeNode<T>::getData() {
    return m_data;
}

#endif