#include <string>
#include <fstream>

using namespace std;

struct Node {
    int key;
    Node *prev;
    Node *left;
    Node *right;
};

class bintree {
    Node *root = 0;
public:
    Node *search(int x) {
        Node *curr = root;
        while (curr != 0 && x != curr->key) {
            if (x < curr->key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return curr;
    }

    bool exists(int x) {
        return search(x) != 0;
    }

    Node *next(int x) {
        Node *curr = root, *nextnode = 0;
        while (curr != 0) {
            if (curr->key > x) {
                nextnode = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return nextnode;
    }

    Node *prev(int x) {
        Node *curnode = root, *prevnode = 0;
        while (curnode != 0) {
            if (curnode->key < x) {
                prevnode = curnode;
                curnode = curnode->right;
            } else {
                curnode = curnode->left;
            }
        }
        return prevnode;
    }

    void insert(int x) {
        if (exists(x)) {
            return;
        }
        Node *newnode = new Node;
        newnode->key = x;
        newnode->prev = newnode->left = newnode->right = 0;
        Node *curr = root;
        while (curr != 0) {
            newnode->prev = curr;
            if (newnode->key > curr->key) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        if (newnode->prev == 0) {
            root = newnode;
        } else if (newnode->key < newnode->prev->key) {
            newnode->prev->left = newnode;
        } else {
            newnode->prev->right = newnode;
        }
    }

    void Delete(int x) {
        Node *delnode = search(x);
        if (delnode == 0)
            return;
        Node *a, *b;
        if (delnode->left == 0 || delnode->right == 0)
            a = delnode;
        else
            a = next(x);
        if (a->left != 0)
            b = a->left;
        else
            b = a->right;
        if (b != 0)
            b->prev = a->prev;
        if (a->prev == 0)
            root = b;
        else if (a == a->prev->left)
            a->prev->left = b;
        else
            a->prev->right = b;
        if (a != delnode)
            delnode->key = a->key;
        delete a;
    }
};

int main() {
    ifstream in("bstsimple.in");
    ofstream out("bstsimple.out");
    bintree tree;
    int mean;
    string command;
    while (in >> command >> mean) {
        if (command == "next") {
            Node *result = tree.next(mean);
            if (result == 0)
                out << "none\n";
            else
                out << result->key << "\n";
        }

        if (command == "prev") {
            Node *result = tree.prev(mean);
            if (result == 0)
                out << "none\n";
            else
                out << result->key << "\n";
        }
        if (command == "insert") {
            tree.insert(mean);
        }

        if (command == "delete") {
            tree.Delete(mean);
        }

        if (command == "exists") {
            if (tree.search(mean)) {
                out << "true\n";
            } else {
                out << "false\n";
            }
        }


    }

    return 0;
}