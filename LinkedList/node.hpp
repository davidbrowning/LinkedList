#ifndef NODE_HPP
#define NODE_HPP
#include<memory>

struct Node{
	Node(){};
	~Node(){};
	Node(int val, std::shared_ptr<Node> n){
		value = val;
		next = n;
	};
	int value;
	std::shared_ptr<Node> next;
};


#endif