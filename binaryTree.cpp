#include<iostream>

using namespace std;

class bTreeNode {
    int data;
    bTree *left;
    bTree *right;
};

class bTree {
    bTreeNode *head;

    public:
        bTree() { head = NULL; }

        void insertNode(int item) {
            if (head == nullptr) {
                head = new bTreeNode();
                return;                
            }

            // while (head->next != nullptr)
            //     head = head->next;
           
            if ()    
        }

};