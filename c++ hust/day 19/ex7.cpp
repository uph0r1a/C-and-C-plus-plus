#include <iostream>
#include <queue>
using namespace std;

class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node *node, queue<int> &q)
    {
        if (node == nullptr)
            return;

        inorder(node->left, q);
        q.push(node->data);
        inorder(node->right, q);
    }

public:
    BST() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    queue<int> getSortedQueue()
    {
        queue<int> q;
        inorder(root, q);
        return q;
    }
};

int main(int argc, char const *argv[])
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    queue<int> q = tree.getSortedQueue();

    cout << "Values in ascending order:\n";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
