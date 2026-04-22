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

    int countLeafNodes(Node *node)
    {
        if (node == nullptr)
            return 0;

        if (node->left == nullptr && node->right == nullptr)
            return 1;

        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    int getLeafCount()
    {
        return countLeafNodes(root);
    }

    int treeHeight(Node *node)
    {
        if (node == nullptr)
            return 0;

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int getHeight()
    {
        return treeHeight(root);
    }
};

int main(int argc, char const *argv[])
{
    BinaryTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(15);
    tree.insert(25);

    cout << "Inorder Traversal: ";
    tree.printInorder();

    cout << "Height of tree: "
         << tree.getHeight() << endl;

    return 0;
}
