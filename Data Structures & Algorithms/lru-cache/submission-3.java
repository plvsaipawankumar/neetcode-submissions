public class Node{
    public int val;
    public int key;
    public Node next;
    public Node prev;

    public Node(){

    }
}
class LRUCache {

    private int cap;
    private Node  left;
    private Node  right;
    private HashMap<Integer,Node> cache;
    public LRUCache(int capacity) {
        cap=capacity;
        left = new Node();
        right = new Node();
        cache = new HashMap<>();
        left.next = right;
        right.prev = left;
    }
    public void insert( Node node){
        node.next = right;
        node.prev=right.prev;
        right.prev.next = node;
        right.prev= node;
    }
    public void remove(Node node){
        Node prev = node.prev;
        Node next = node.next;
        prev.next = next;
        next.prev=prev;
    }
    public int get(int key) {
        if(cache.containsKey(key)){
            Node node = cache.get(key);
            remove(node);
            insert(node);
            return node.val;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(cache.containsKey(key)){
            remove(cache.get(key));
        }
        Node node = new Node();
        node.key = key;
        node.val = value;
        cache.put(key,node);
        insert(node);

        if(cache.size()> cap){
            Node lru = left.next;
            remove(lru);
            cache.remove(lru.key);
        }

    }
}
