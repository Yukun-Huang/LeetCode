// 实际上即为Python的OrderedDict的实现: 双向链表+哈希表
// 注意!双向链表用来存储key-value对,而哈希表用来存储key-链表指针对。双向链表才是存储数据的那个！

class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator > hashMap;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (hashMap.count(key)){  // key存在
            pair<int, int> kv = *hashMap[key];
            cache.erase(hashMap[key]);  // 删除原节点
            cache.push_front(kv);   // 链表头插入新节点
            hashMap[key] = cache.begin();   // 重新指定节点位置
            return kv.second;
        }
        else  // key不存在
            return -1;
    }
    
    void put(int key, int value) {
        if (hashMap.count(key)){  // key存在,删除原数据,插入新数据放到链表头
            cache.erase(hashMap[key]);  // 删除原节点
            cache.push_front(make_pair(key, value));   // 链表头插入新节点
            hashMap[key] = cache.begin();   // 重新指定节点位置
        }
        else{  // key不存在,判断是否已满,删除旧数据,插入新数据
            if (cache.size() == cap){
                hashMap.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            hashMap[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
