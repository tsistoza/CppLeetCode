#include <iostream>

using std::cout,std::cin,std::endl;

namespace Solution {
    class Node{
          public:
            int id;
            Node* left;
            Node* right;

            Node (int val = (int) NULL) {
                this->id = val;
                this->left = NULL;
                this->right = NULL;
            }
    };
    
    class BST {
        private:
            Node* insertRoot;
            void findInsertPoint(Node* root, int val);

        public:
            Node* root;
            void insert(Node* node);
            void readBST(Node* root);
            void destroyBST(Node* root);

            BST (int val = (int) NULL) {
                this->root = new Node(val);
            }
    };

    void BST::insert(Node* node) {
        this->findInsertPoint(this->root, node->id);
        if (node->id < this->insertRoot->id) this->insertRoot->left = node;
        else if (node->id >= this->insertRoot->id) this->insertRoot->right = node;
        return;
    }

    void BST::readBST(Node* root) {
        if (root->left != NULL) this->readBST(root->left);
        if (root->right != NULL) this->readBST(root->right);
        cout << root->id << " ";
        return;
    }

    void BST::destroyBST(Node* root) {
        if (root->left != NULL) this->destroyBST(root->left);
        if (root->right != NULL) this->destroyBST(root->right);
        delete root;
    }

    void BST::findInsertPoint(Node* root, int val) {
        if (val < root->id && root->left == NULL) {
            this->insertRoot = root;
            return;
        }
        if (val >= root->id && root->right == NULL) {
            this->insertRoot = root;
            return;
        }
        if (val < root->id && root->left != NULL) this->findInsertPoint(root->left, val);
        if (val >= root->id && root->right != NULL) this->findInsertPoint(root->right, val);
        return;
    }
}

int main() {
    using namespace Solution;
    BST* obj = new BST(5);
    obj->insert(new Node(1));
    obj->insert(new Node(6));
    obj->insert(new Node(2));    
    obj->insert(new Node(7));
    cout << "BST in sorted order: ";
    obj->readBST(obj->root);
    cout << endl;
    obj->destroyBST(obj->root);
    delete obj;
    return 0;
}