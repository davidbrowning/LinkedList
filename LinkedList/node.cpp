#include"node.hpp"

void Node::print(std::shared_ptr<Node> head){
	std::shared_ptr<Node> temp = head;
	while (temp != nullptr){
		std::cout << temp->getValue() << std::endl;
		temp = temp->next;
	}
}

void Node::setValue(int val){
	if (val > 0 && val < 1000000){
		value = val;
	}
}