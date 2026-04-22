#include <iostream>
#include <string>
#include <queue>
using namespace std;

class EmployeeInfo
{
private:
    int id;
    string name;

public:
    EmployeeInfo(int i = 0, string n = "") : id(i), name(n) {}

    int getID() const { return id; }
    string getName() const { return name; }

    bool operator<(const EmployeeInfo &other) const
    {
        return id < other.id;
    }

    bool operator>(const EmployeeInfo &other) const
    {
        return id > other.id;
    }

    bool operator==(const EmployeeInfo &other) const
    {
        return id == other.id;
    }

    friend ostream &operator<<(ostream &os, const EmployeeInfo &emp)
    {
        os << "[" << emp.id << " - " << emp.name << "]";
        return os;
    }
};

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

    EmployeeInfo *search(Node *node, int id)
    {
        if (node == nullptr)
            return nullptr;

        if (node->data.getID() == id)
            return &node->data;

        if (id < node->data.getID())
            return search(node->left, id);

        return search(node->right, id);
    }

    EmployeeInfo *search(int id)
    {
        return search(root, id);
    }
};

int main(int argc, char const *argv[])
{
    BinaryTree<EmployeeInfo> tree;

    tree.insert(EmployeeInfo(1021, "John Williams"));
    tree.insert(EmployeeInfo(1057, "Bill Witherspoon"));
    tree.insert(EmployeeInfo(2487, "Jennifer Twain"));
    tree.insert(EmployeeInfo(3769, "Sophia Lancaster"));
    tree.insert(EmployeeInfo(1017, "Debbie Reece"));
    tree.insert(EmployeeInfo(1275, "George McMullen"));
    tree.insert(EmployeeInfo(1899, "Ashley Smith"));
    tree.insert(EmployeeInfo(4218, "Josh Plemmons"));

    cout << "Employee Tree (Inorder by ID):\n";
    tree.printInorder();

    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    EmployeeInfo *result = tree.search(searchID);

    if (result != nullptr)
        cout << "Employee found: " << result->getName() << endl;
    else
        cout << "Employee not found.\n";

    return 0;
}
