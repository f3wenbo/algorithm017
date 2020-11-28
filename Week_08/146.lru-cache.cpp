/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (28.23%)
 * Likes:    6635
 * Dislikes: 282
 * Total Accepted:    609.7K
 * Total Submissions: 1.8M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 * 
 * 
 * Follow up:
 * Could you do get and put in O(1) time complexity?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 3000
 * 0 <= value <= 10^4
 * At most 3 * 10^4 calls will be made to get and put.
 * 
 * 
 */

// @lc code=start
class LRUCache {

struct Node {
    int key, val;
    Node* prev;
    Node* next;
    Node(int key, int val, Node* prev, Node* next):key(key), val(val), prev(prev), next(next) {}
};

private:

    void move2Head(Node* cur) {
        if (cur == head) {
            head = head->prev;
            return;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->next = head->next;
        cur->next->prev = cur;
        head->next = cur;
        cur->prev = head;
    }

    Node *head = new Node(-1, -1, nullptr, nullptr);
    std::map<int, Node*> hash;

public:

    LRUCache(int capacity) {
        Node* cur = head;
        for (int i = 0; i < capacity - 1; ++i) {
            cur->next = new Node(-1, -1, cur, nullptr);
            cur = cur->next;
        }
        cur->next = head;
        head->prev = cur;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        Node* cur = hash[key];
        move2Head(cur);
        return cur->val;
    }

    void put(int key, int value) {
        if (hash.find(key) != hash.end()){
            Node* cur = hash[key];
            cur->val = value;
            move2Head(cur);
        } else {
            if (head->val != -1) hash.erase(head->key);
            head->key = key;
            head->val = value;
            hash[key] = head;
            head = head->prev;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

