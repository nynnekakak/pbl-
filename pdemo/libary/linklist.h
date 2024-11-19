#ifndef LinkList_h
#define LinkList_h

template<typename T>
class LinkedList {
private:
	struct node {
		T data;
		node* next;
		node(T d) : data(d), next(nullptr) {}
	};
	node* root;
	node* n;
	node* current;
	node* createnode(T data);
	int size_ll;
	
public:
	LinkedList();
	void add(T data);
	T& operator[](int location);
	void del(int location);
	int size();
};


#endif