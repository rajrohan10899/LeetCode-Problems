class MyHashMap {
    //Optimal Solution
    vector<list<pair<int, int>>> buckets;
    int size = 10000;

public:
    MyHashMap() { buckets.resize(size); }

    void put(int key, int value) { 
        int index = key % size;
        for (auto& it : buckets[index]) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        buckets[index].emplace_back(key, value);
    }

    int get(int key) {
        int index = key % size;
        for (auto& it : buckets[index]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = key % size;
        for(auto it = buckets[index].begin(); it != buckets[index].end(); it++) {
            if(it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */