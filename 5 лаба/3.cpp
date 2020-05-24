#include <vector>
#include <fstream>

using namespace std;

ifstream in("linkedmap.in");
ofstream out("linkedmap.out");
struct item {
    item *prev = NULL;
    item *prev_key = NULL;
    string key;
    string value;
    item *next_key = NULL;
    item *next = NULL;
};

vector<item *> a = vector<item *>(1000003);

item *CreateNode(string key, string value) {
    auto node = new item;
    node->prev = nullptr;
    node->prev_key = nullptr;
    node->key = key;
    node->value = value;
    node->next_key = NULL;
    node->next = NULL;
    return node;
}

item *AddNode(item *&tail, string key, string value) {
    item *node = CreateNode(key, value);
    node->prev = tail;
    tail->next = node;
    return node;
}

long long GetHash(const string& key) {
    const int p = 31;
    long long hash = 0, p_pow = 1;
    for (char i : key) {
        hash += (i - 'a' + 1) * p_pow;
        p_pow *= p;
    }

    long long m = 1000003;

    if (hash >= 0) {
        return hash % m;
    } else {
        return (m - abs(hash) % m) % m;
    }
}

item *Put(const string& key, string value, item *&LastKey) {
    item *head = a[GetHash(key)];
    if (head == NULL) {
        a[GetHash(key)] = CreateNode(key, value);
        a[GetHash(key)]->prev_key = LastKey;

        if (LastKey != NULL)
            LastKey->next_key = a[GetHash(key)];

        return a[GetHash(key)];
    } else {
        item *pointer = head;
        while (pointer->next != NULL) {
            if (pointer->key == key) {
                pointer->value = value;
                return NULL;
            }
            pointer = pointer->next;
        }

        if (pointer->key != key) {
            item *new_node = AddNode(pointer, key, value);
            new_node->prev_key = LastKey;
            if (LastKey != NULL)
                LastKey->next_key = new_node;
            return new_node;
        } else {
            pointer->value = value;
            return NULL;
        }
    }
}

void Delete(string key, item *&LastKey) {
    item *pointer = a[GetHash(key)];

    while (pointer != NULL) {
        if (pointer->key == key) {
            if (LastKey == pointer) {
                LastKey = pointer->prev_key;
            }
            if (pointer->prev_key != NULL) {
                pointer->prev_key->next_key = pointer->next_key;
            }
            if (pointer->next_key != NULL) {
                pointer->next_key->prev_key = pointer->prev_key;
            }
            if (pointer->prev != NULL) {
                pointer->prev->next = pointer->next;
            }
            if (pointer->next != NULL) {
                pointer->next->prev = pointer->prev;
            }
            if (pointer == a[GetHash(key)]) {
                a[GetHash(key)] = NULL;
            }
            free(pointer);
            return;
        }
        pointer = pointer->next;
    }

}

bool Get(const string& key) {
    item *pointer = a[GetHash(key)];

    while (pointer != NULL) {
        if (pointer->key == key) {
            out << pointer->value << "\n";
            return true;
        }
        pointer = pointer->next;
    }

    out << "none\n";
    return false;
}

item *Find(const string& key) {
    item *pointer = a[GetHash(key)];

    while (pointer != NULL) {
        if (pointer->key == key)
            return pointer;

        pointer = pointer->next;
    }

    return NULL;
}

void Prev(const string& key) {
    item *element = Find(key);
    if (element != NULL && element->prev_key != NULL)
        out << element->prev_key->value << "\n";
    else
        out << "none\n";
}

void Next(const string& key) {
    item *element = Find(key);
    if (element != NULL && element->next_key != NULL)
        out << element->next_key->value << "\n";
    else
        out << "none\n";
}

int main() {

    item *LastKey = NULL;
    string line;
    string key, value;

    while (in >> line) {
        in >> key;
        if (line == "put") {
            in >> value;
            item *pointer = Put(key, value, LastKey);
            if (pointer != NULL) LastKey = pointer;
        } else if (line == "delete") {
            Delete(key, LastKey);
        } else if (line == "get") {
            Get(key);
        } else if (line == "prev") {
            Prev(key);
        } else if (line == "next") {
            Next(key);
        }
    }

    return 0;
}