#include<iostream>
#include<memory>

using namespace std;

template<typename T>
struct bTreeNode {
    public:
        T val;
        unique_ptr<bTreeNode<T>> left;      //bTree *left;
        unique_ptr<bTreeNode<T>> right;     //bTree *right;

        bTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

template<typename T>
class bTree {
    unique_ptr<bTreeNode<T>> head;          //bTreeNode *head;

    public:
        bTree() : head(nullptr) {}

        void insertNode(const T& val) {
            if (!head) {
                head =  make_unique<bTreeNode<T>>(val); //new bTreeNode(item);
                return;                
            }

            bTreeNode<T> *curr = head.get();

            while(curr) {
                if (val < curr->val) {
                    if (curr->left) {
                        curr = curr->left.get();
                    }
                    else {
                        curr->left = make_unique<bTreeNode<T>>(val);
                        return;
                    }
                }
                else {
                    if (curr->right) {
                        curr = curr->right.get();
                    }
                    else {
                        curr->right = make_unique<bTreeNode<T>>(val);
                        return;
                    }
                }
            }
        }

        void preOrderTraversal() const {
            cout << endl << "PreOrder Traversal: ";
            preOrderTraversal(head.get());
        }

        void inOrderTraversal() const {
            cout << endl << "InOrder Traversal: " << endl;
            inOrderTraversal(head.get(), 0);
        }

        void postOrderTraversal() const {
            cout << endl << "PostOrder Traversal: ";
            postOrderTraversal(head.get());
        }

        private:
            void preOrderTraversal(bTreeNode<T>* root) const {
                if (!root) return;

                cout << root->val << " ";
                preOrderTraversal(root->left.get());
                preOrderTraversal(root->right.get());
            }

            void inOrderTraversal(bTreeNode<T>* root, int depth) const {
                if (!root) return;

                inOrderTraversal(root->left.get(), depth + 1);
                for (int i = 0; i < depth; ++i) std::cout << " ";
                cout << root->val << endl;
                inOrderTraversal(root->right.get(), depth + 1);
            }

            void postOrderTraversal(bTreeNode<T>* root) const {
                if (!root) return;
                postOrderTraversal(root->left.get());
                postOrderTraversal(root->right.get());
                cout << root->val << " ";                
            }
};

int main () {
    bTree<int> bst;
    bst.insertNode(5);
    bst.insertNode(2);
    bst.insertNode(3);
    bst.insertNode(4);
    bst.insertNode(5);
    bst.insertNode(56);
    bst.insertNode(100);
    bst.insertNode(0);

    bst.preOrderTraversal();
    bst.inOrderTraversal();
    bst.postOrderTraversal();

    return 0;
}