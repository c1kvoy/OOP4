#ifndef HM_H
#define HM_H

template <typename Key, typename Value>
class Map {
private:
    static const int CAP = 100;
    struct Node {
        Key k;
        Value v;
        bool occupied;
        Node() : occupied(false) {}
    };
    Node table[CAP];

    static int hash(Key k);

public:
    Map();
    void insert(Key key, Value value);
    bool find(Key key, Value& value);
    void remove(Key key);
};


template <typename Key, typename Value>
int Map<Key, Value>::hash(Key k) {
    return k % CAP;
}

template <typename Key, typename Value>
Map<Key, Value>::Map() {}

template <typename Key, typename Value>
void Map<Key, Value>::insert(Key key, Value value) {
    int index = hash(key);
    while (table[index].occupied && table[index].k != key) {
        index = (index + 1) % CAP;
    }
    table[index].k = key;
    table[index].v = value;
    table[index].occupied = true;
}

template <typename Key, typename Value>
bool Map<Key, Value>::find(Key key, Value& value) {
    int index = hash(key);
    int startIndex = index;

    while (table[index].occupied) {
        if (table[index].k == key) {
            value = table[index].v;
            return true;
        }
        index = (index + 1) % CAP;
        if (index == startIndex) break;
    }
    return false;
}

template <typename Key, typename Value>
void Map<Key, Value>::remove(Key key) {
    int index = hash(key);
    int startIndex = index;

    while (table[index].occupied) {
        if (table[index].k == key) {
            table[index].occupied = false;
            return;
        }
        index = (index + 1) % CAP;
        if (index == startIndex) break;
    }
}

#endif