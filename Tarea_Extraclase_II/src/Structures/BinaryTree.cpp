#include "TreeNode.cpp"

class BinaryTree {
    private:
        TreeNode *root;
        TreeNode * addRecursive(TreeNode *current, int value) {

        };
        TreeNode * deleteRecursive(TreeNode *current, int value) {

        };
        
    public:
        BinaryTree();
        void add(int value);
        void deleteValue(int value);
        void preorder();

};

BinaryTree::BinaryTree(){
    root = NULL;
}

void BinaryTree::add(int value) {
    root = addRecursive(root, value);
}

void BinaryTree::deleteValue(int value){
    root = deleteRecursive(root, value);
}
