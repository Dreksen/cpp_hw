#include <map>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

template<typename K, typename V>
class LruCache {
private:
    unordered_map<K, V> cache;
    unordered_map<K, typename list<K>::iterator> itrs;
    list<K> lst;
    size_t sz_;

public:
    explicit LruCache(size_t max_size) : sz_(max_size) {}

    void Put(const K &key, const V &value) {
        if (cache.contains(key)) {
            cache[key] = value;
            lst.erase(itrs[key]);
            lst.push_back(key);
            itrs[key] = --lst.end();
        } else {
            if (cache.size() >= sz_) {
                K last = lst.front();
                lst.pop_front();
                cache.erase(last);
                itrs.erase(last);
            }
            cache[key] = value;
            lst.push_back(key);
            itrs[key] = --lst.end();
        }
    }

    bool Get(const K &key, V *value) {
        if (cache.contains(key)) {
            *value = cache[key];
            lst.erase(itrs[key]);
            lst.push_back(key);
            itrs[key] = --lst.end();
            return true;
        }
        return false;
    }
};
