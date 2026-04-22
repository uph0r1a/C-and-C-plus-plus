#include <iostream>
#include <queue>
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

    int getWidth()
    {
        if (root == nullptr)
            return 0;

        queue<Node *> q;
        q.push(root);

        int maxWidth = 0;

        while (!q.empty())
        {
            int levelSize = q.size();
            maxWidth = max(maxWidth, levelSize);

            for (int i = 0; i < levelSize; i++)
            {
                Node *current = q.front();
                q.pop();

                if (current->left != nullptr)
                    q.push(current->left);

                if (current->right != nullptr)
                    q.push(current->right);
            }
        }

        return maxWidth;
    }

    Node *copyTree(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        Node *newNode = new Node(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);

        return newNode;
    }

    BinaryTree(const BinaryTree<T> &other)
    {
        root = copyTree(other.root);
    }

    BinaryTree<T> &operator=(const BinaryTree<T> &other)
    {
        if (this == &other)
            return *this;

        clear(root);

        root = copyTree(other.root);
        return *this;
    }

    void clear(Node *node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    ~BinaryTree()
    {
        clear(root);
    }
};

int main(int argc, char const *argv[])
{
    BinaryTree<int> tree1;

    tree1.insert(50);
    tree1.insert(30);
    tree1.insert(70);
    tree1.insert(20);
    tree1.insert(40);

    cout << "Tree1 (Inorder): ";
    tree1.printInorder();

    BinaryTree<int> tree2 = tree1;

    cout << "Tree2 (After Copy Constructor): ";
    tree2.printInorder();

    tree1.insert(90);

    cout << "Tree1 (After modification): ";
    tree1.printInorder();

    cout << "Tree2 (Should remain unchanged): ";
    tree2.printInorder();

    BinaryTree<int> tree3;
    tree3 = tree1;

    cout << "Tree3 (After Assignment): ";
    tree3.printInorder();

    return 0;
}
