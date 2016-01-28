#include"node.hpp"
#include<iostream>
#include<vector>
#include<memory>
#include<cstdlib>

void initialize(std::shared_ptr<Node> &head, std::vector<int> v);

int main(){
	std::vector<int> v{ 1, 4, 7, 9, 14, 15, 20, 35 };
	Node head = Node(v[0], nullptr);
	std::shared_ptr<Node> h = std::make_shared<Node>(head);
	initialize(h, v);
	head.print(h);
}

void initialize(std::shared_ptr<Node> &head, std::vector<int> v){
	std::shared_ptr<Node> p = head;
	for (int i = 1; i < v.size(); i++){
		p->next = std::make_shared<Node>(Node(v[i], nullptr));
		p = p->next;
	}
	return;
}