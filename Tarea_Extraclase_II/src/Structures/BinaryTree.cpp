#include "TreeNode.cpp"
using namespace std;

class BinaryTree {
    private:
        TreeNode *root;
        TreeNode * addRecursive(TreeNode *current, int value);
        // TreeNode * deleteRecursive(TreeNode *current, int value);
        void inorderRecursive(TreeNode *current);
        
    public:
        BinaryTree();
        void add(int value);
        // void deleteValue(int value);
        void inorder();

};

BinaryTree::BinaryTree(){
    root = NULL;
}

TreeNode * BinaryTree::addRecursive(TreeNode *current, int value) {
    if (current == NULL) {
        //se encontro el lugar para insertar el nodo
        return new TreeNode(value);
    } else if (current->getValue() > value) {
        current->setLeftChild(addRecursive(current->getLeftChild(), value));
    } else if (current->getValue() < value) {
        current->setRightChild(addRecursive(current->getRightChild(), value));
    } 
     //sino el elemento ya existe

     return current;
} 

void BinaryTree::add(int value) {
    root = addRecursive(root, value);
}

// TreeNode * deleteRecursive(TreeNode *current, int value) {
//     return NULL;
// }

// void BinaryTree::deleteValue(int value){
//     root = deleteRecursive(root, value);
// }

void BinaryTree::inorderRecursive(TreeNode *current) {
    if (current == NULL) {
        return;
    }
    inorderRecursive(current->getLeftChild());
    cout << current->getValue() << " ";
    inorderRecursive(current->getRightChild());
}

void BinaryTree::inorder() {
    inorderRecursive(root);

}

int main(int argc, char *argv[]) {
    BinaryTree *tree = new BinaryTree();

    tree->add(5);
    tree->add(51);
    tree->add(10);
    tree->add(5);
    tree->add(2);
    tree->add(1);

    tree->inorder();
    cout << "\n";
    
    return 0;
}

