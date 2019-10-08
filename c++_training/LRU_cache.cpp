#include <unordered_map>
#include <vector>
#include <algorithm>

class Node
{
public:
	int key
	Node* next;
	Node* prev;
	Node(int key_): key(key_){
		this.next = nullptr;
		this.prev = nullptr;
	}
	~Node();
	
};
class LRU_cache
{
public:
	Node* head;
	Node* tail;
	std::unordered_map<int, Node*> map;
	int size = 0;
	const int capacity;
	LRU_cache(const int capacity_) : capacity(capacity_)
	{
		this.head = nullptr;
		this.tail = nullptr;
	}
	~LRU_cache();

	int get(int key){
		auto it = map.find(key);
		if(it == map.end()){
			return -1;
		}else{
			//delete the node from the linkedlist
			Node* cur = it->second;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			//Insert this node to the front
			head->prev = cur;
			cur->next = head;
			cur->prev = nullptr;
			head = cur;
			return cur->key;
		}
	}

	void put(int key){
		
		Node* node = new Node(key);
		map.insert(std::make_pair(key, node));
		if(size == capacity){
			// delete the last node
			Node* last = tail;
			int last_key = last->key;
			tail=tail->prev;
			delete(last);
			map.erase(last_key);
		}else if(size == 0){
			head = node;
			node.prev = nullptr;
			node.next = nullptr;
			tail = node;
		}else{
			node.prev = tail;
			node.next = nullptr;
			tail = node;	
		}
		size++;
	}
	
};