#include"node.hpp"

void Node::print(std::shared_ptr<Node> &head){
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
	return;
}

void Node::insert(int x, std::shared_ptr<Node> head){
	std::shared_ptr<Node> p = head;
	if (p == nullptr){
		std::cout << "Empty List. " << std::endl << "Initializing..." << std::endl;
		Node toInsert(x, nullptr);
		return;
	}
	while ((p->next != nullptr) && (p->next->getValue() < p->getValue())){
		p = p->next;
	}
	Node toInsert(x, p->next);
	std::shared_ptr<Node> pt = std::make_shared<Node>(toInsert);
	p->next = pt;
	std::cout << "Inserting value:  " << x << std::endl << "After value: " << p->getValue() << std::endl;
	p = p->next;
	std::cout << "and before value: " << p->next->getValue() << std::endl << std::endl;
	return;
}

void Node::delNode(int x, std::shared_ptr<Node> head){
	if (head == nullptr){
		std::cout << "Empty list" << std::endl;
		return;
	}
	std::shared_ptr<Node> pt = head;
	while (pt != nullptr && pt->next->getValue() < pt->getValue()){
		if (pt->next->getValue() == x){
			std::shared_ptr<Node> q = pt->next;
			pt->next = q->next;
			std::cout << "Value to be Deleted: " << x << std::endl << "Value found after: " << pt->getValue() << std::endl;
			std::cout << "Value found before: " << pt->next->getValue() << std::endl;
		}
		pt = pt->next;
	}
	std::cout << "hit " << std::endl;
	return;
}