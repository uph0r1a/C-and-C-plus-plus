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
};

int main(int argc, char const *argv[])
{
    BinaryTree<int> intTree;
    intTree.insert(50);
    intTree.insert(30);
    intTree.insert(70);
    intTree.insert(20);
    intTree.insert(40);

    cout << "Integer Tree (Inorder): ";
    intTree.printInorder();

    BinaryTree<double> doubleTree;
    doubleTree.insert(5.5);
    doubleTree.insert(2.2);
    doubleTree.insert(8.8);

    cout << "Double Tree (Inorder): ";
    doubleTree.printInorder();

    BinaryTree<string> stringTree;
    stringTree.insert("banana");
    stringTree.insert("apple");
    stringTree.insert("cherry");

    cout << "String Tree (Inorder): ";
    stringTree.printInorder();

    return 0;
}
