#include <iostream>

class TreeNode {
    private:
        int value;
        TreeNode *rightChild, *leftChild;

    public:
        TreeNode(int value);
        int getValue();
        void setValue(int value);
        TreeNode * getRightChild();
        void setRightChild(TreeNode *rightChild);
        TreeNode * getLeftChild();
        void setLeftChild(TreeNode *leftChild);

};

TreeNode::TreeNode(int value) {
    this->value = value;
    rightChild = NULL;
    leftChild = NULL;
}

int TreeNode::getValue() {
    return value;
}

void TreeNode::setValue(int value) {
    this->value = value;
}

TreeNode * TreeNode::getRightChild() {
    return rightChild;
}

void TreeNode::setRightChild(TreeNode * rightChild) {
     this->rightChild = rightChild;
}

TreeNode * TreeNode::getLeftChild() {
    return leftChild;
}

void TreeNode::setLeftChild(TreeNode * leftChild) {
     this->leftChild = leftChild;
}