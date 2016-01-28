#ifndef NODE_HPP
#define NODE_HPP
#include<memory>
#include<iostream>

struct Node{
	Node(){};
	~Node(){};
	Node(int val, std::shared_ptr<Node> n){
		if (val > 0 && val < 1000000){
			value = val;
		}
		next = n;
	};
	void print(std::shared_ptr<Node> &head);
	std::shared_ptr<Node> next;
	void setValue(int x);
	int getValue(){return value;}
	void insert(int x, std::shared_ptr<Node> head);
	void delNode(int x, std::shared_ptr<Node> head);

private:
	int value;
	

};


#endif