/* Design and implement a hash table which uses chaining (linked lists)
to handle collisions.
*/
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

static const int TABLE_SIZE = 128;

// Hash node class template
template <typename K, typename V>
struct HashNode {
    K key;
    V value;
    HashNode *next;
    HashNode(const K& a, const V& b): key(a), value(b), next(NULL) {}
};


// Hash map class template
template <typename K, typename V>
class HashMap {
public:
    HashMap() {
        // construct zero initialized hash table of size
        table = new HashNode<K, V> *[TABLE_SIZE]();
    }
    
    ~HashMap() {
        // destroy all buckets one by one
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<K, V> *entry = table[i];
            while (entry != NULL) {
                HashNode<K, V> *pre = entry;
                entry = entry->next;
                delete pre;
            }
        }
        // destroy the hash table
        delete [] table;
    }
    
    unsigned long hashFunc(const K& key) const {
        return static_cast<unsigned long>(key) % TABLE_SIZE;
    }
    
    bool get(const K &key, V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];
        
        while (entry != NULL) {
            if (entry->key == key) {
                value = entry->value;
                return true;
            }
            entry = entry->next;
        }
        return false;
    }
    
    void put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *pre = NULL;
        HashNode<K, V> *entry = table[hashValue];
        
        while (entry != NULL && entry->key != key) {
            pre = entry;
            entry = entry->next;
        }
        
        if (entry == NULL) {
            entry = new HashNode<K, V>(key, value);
            if (pre == NULL) {
                // insert as first bucket
                table[hashValue] = entry;
            } else {
                pre->next = entry;
            }
        } else {
            // just update the value
            entry->value = value;
        }
    }
    
    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *pre = NULL;
        HashNode<K, V> *entry = table[hashValue];
        
        while (entry != NULL && entry->key != key) {
            pre = entry;
            entry = entry->next;
        }
        
        if (entry == NULL) {
            // key not found
            return;
        }
        else {
            if (pre == NULL) {
                // remove first bucket of the list
                table[hashValue] = entry->next;
            } else {
                pre->next = entry->next;
            }
            delete entry;
        }
    }
    
private:
    // hash table
    HashNode<K, V> **table;
};


int main()
{
	HashMap<int, string> hmap;
	hmap.put(1, "1");
	hmap.put(2, "2");
	hmap.put(3, "3");
    
	string value;
	bool result = hmap.get(2, value);
	assert(result);
	assert(value == "2");
    
	result = hmap.get(3, value);
	assert(result);
	assert(value == "3");
    
	hmap.remove(3);
	result = hmap.get(3, value);
	assert(!result);
    
	cout << "All tests passed!" << endl;
}


