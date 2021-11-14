#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyValFreq; // <key, <val, freq>>
    unordered_map<int, list<int>> freqKey; // <freq, <key0, key1, key2...>>
    unordered_map<int, list<int>::iterator> keyIter; // <key, ptr of this key to freqKey>

public:
    LFUCache(int capacity) {
        // "this" is a pointer, using "->" not "."
        this->capacity = capacity;
    }

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end()) return -1;
        int freq = keyValFreq[key].second;
        freqKey[freq++].erase(keyIter[key]);
        freqKey[freq].emplace_front(key); // insert at beginning of linked list
        keyValFreq[key].second = freq;
        keyIter[key] = freqKey[freq].begin();


        if (freqKey[minFreq].empty()) minFreq = freq;
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        if (get(key) != -1) {
            keyValFreq[key].first = value;
            return;
        }

        // cache evict
        if (keyValFreq.size() == capacity) {
            int delKey = freqKey[minFreq].back();
            freqKey[minFreq].pop_back();
            keyValFreq.erase(delKey);
            keyIter.erase(delKey);
        }

        minFreq = 1;
        keyValFreq[key] = {value, minFreq};
        freqKey[minFreq].emplace_front(key);
        keyIter[key] = freqKey[minFreq].begin();
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

