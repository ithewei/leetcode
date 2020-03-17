#include <stdio.h>
#include <map>
using std::map;

struct DListNode {
    int key;
    int value;
    DListNode* prev;
    DListNode* next;

    DListNode(int key = 0, int value = 0) {
        this->key = key;
        this->value = value;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head.next = &tail;
        tail.prev = &head;
    }

    ~LRUCache() {
        for (auto& pair : mp) {
            delete pair.second;
        }
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        moveToHead(key);
        return mp[key]->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            moveToHead(key);
            return;
        }
        if (size == capacity) {
            delTail();
            addToHead(key, value);
        }
        else {
            ++size;
            addToHead(key, value);
        }
    }

protected:
    void addToHead(int key, int value) {
        DListNode* node = new DListNode(key, value);
        node->prev = &head;
        node->next = head.next;
        head.next->prev = node;
        head.next = node;
        mp[key] = node;
    }

    void delTail() {
        DListNode* node = tail.prev;
        node->prev->next = &tail;
        tail.prev = node->prev;
        mp.erase(mp.find(node->key));
        delete node;
    }

    void moveToHead(int key) {
        DListNode* node = mp[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = &head;
        node->next = head.next;
        head.next->prev = node;
        head.next = node;
    }

private:
    int capacity;
    int size;
    map<int, DListNode*> mp;
    DListNode head;
    DListNode tail;
};

int main() {
    LRUCache obj(2);
    obj.put(1, 1);
    obj.put(2, 2);
    obj.put(3, 3);
    int v1 = obj.get(1);
    int v2 = obj.get(2);
    int v3 = obj.get(3);
    printf("%d %d %d\n", v1, v2, v3);
    return 0;
}
