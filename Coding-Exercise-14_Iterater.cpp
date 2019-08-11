#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder_traversal(vector<Node<T>*>& result)
    {
        preTraversal_helper(result, this);
    }
    
    void preTraversal_helper(vector<Node<T>*>& result, Node* node) {
        // Exit criteria
        if (!node) {
            return;
        }
        // Preorder
        result.push_back(node);
        preTraversal_helper(result, node->left);
        preTraversal_helper(result, node->right);
    }
};
