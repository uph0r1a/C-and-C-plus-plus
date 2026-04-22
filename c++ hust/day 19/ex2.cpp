#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insert(Node *node, T value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T value)
    {
        root = insert(root, value);
    }

    void printInorder()
    {
        inorder(root);
        cout << endl;
    }

    void printPreorder()
    {
        preorder(root);
        cout << endl;
    }

    void printPostorder()
    {
        postorder(root);
        cout << endl;
    }

    int countNodes(Node *node)
    {
        if (node == nullptr)
            return 0;

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int getNodeCount()
    {
        return countNodes(root);
    }
};

int main(int argc, char const *argv[])
{
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);

    cout << "Inorder Traversal: ";
    tree.printInorder();

    cout << "Total number of nodes: "
         << tree.getNodeCount() << endl;

    return 0;
}
