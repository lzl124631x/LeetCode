class LFUCache {
private:
    typedef pair<int, int> KV;
    struct Node;
    typedef list<Node>::iterator NodeIter;
    typedef list<KV>::iterator ListIter;
    struct Node {
        int cnt;
        ListIter first, last;
    };
    list<KV> vals;
    map<int, pair<ListIter, NodeIter>> m;
    list<Node> nodes;
    int capacity;
public:
    LFUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (!m.count(key)) return -1; // not found;
        auto p = m[key];
        auto listIter = p.first;
        auto nodeIter = p.second;
        KV kv = *listIter;
        int cnt = nodeIter->cnt + 1;
        if (nodeIter->first == nodeIter->last) {
            nodeIter = nodes.erase(nodeIter);
        } else if (listIter == nodeIter->first) nodeIter->first++;
        else if (listIter == nodeIter->last) nodeIter->last--;
        vals.erase(listIter);
        if (nodeIter == nodes.begin() || prev(nodeIter)->cnt > cnt) {
            if (nodeIter == nodes.begin()) {
                vals.push_front(kv);
                listIter = vals.begin();
            } else {
                listIter = next(prev(nodeIter)->last);
                listIter = vals.insert(listIter, kv);
            }
            nodeIter = nodes.insert(nodeIter, { cnt, listIter, listIter });
        } else {
            nodeIter--;
            listIter = vals.insert(nodeIter->first, kv);
            nodeIter->first = listIter;
        }
        m[key] = { listIter, nodeIter };
        return kv.second;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (m.count(key)) {
            get(key);
            m[key].first->second = value;
        } else {
            NodeIter nodeIter;
            ListIter listIter;
            if (vals.size() >= capacity) {
                nodeIter = prev(nodes.end());
                if (nodeIter->first == nodeIter->last) nodes.erase(nodeIter);
                else nodeIter->last--;
                listIter = prev(vals.end());
                int key = vals.back().first;
                vals.pop_back();
                m.erase(key);
            }
            nodeIter = prev(nodes.end());
            if (nodes.empty() || nodeIter->cnt != 1) {
                vals.push_back({ key, value });
                listIter = prev(vals.end());
                nodes.push_back({ 1, listIter, listIter });
                nodeIter = prev(nodes.end());
            } else {
                listIter = vals.insert(nodeIter->first, { key, value });
                nodeIter->first = listIter;
            }
            m[key] = { listIter, nodeIter };
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */