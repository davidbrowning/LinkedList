#include "list.hpp"


linkedlist::linkedlist(){
	headInt = nullptr;
	headChar = nullptr;
	headString = nullptr;
}


linkedlist::~linkedlist(){
}


void linkedlist::insert(int v){
	if (headInt == nullptr){ //If the head of the list is empty, the node becomes the head.
		node<int> h(nullptr, v);
		headInt = std::make_shared<node<int>>(h);
	}
	else{ //If it is not, iterate through full nodes until the end of the list.
		auto n = headInt;
		while (n->next != nullptr){
			n = n->next;
		}
		node<int> last(nullptr, v); //Create node given the input.
		n->next = std::make_shared<node<int>>(last); //Add it to the end of the list.
	}
}

void linkedlist::insert(char v){
	if (headChar == nullptr){ //If the head of the list is empty, the node becomes the head.
		node<char> h(nullptr, v);
		headChar = std::make_shared<node<char>>(h);
	}
	else{ //If it is not, iterate through full nodes until the end of the list.
		auto n = headChar;
		while (n->next != nullptr){
			n = n->next;
		}
		node<char> last(nullptr, v); //Create node given the input.
		n->next = std::make_shared<node<char>>(last); //Add it to the end of the list.
	}
}

void linkedlist::insert(std::string v){
	if (headString == nullptr){ //If the head of the list is empty, the node becomes the head.
		node<std::string> h(nullptr, v);
		headString = std::make_shared<node<std::string>>(h);
	}
	else{ //If it is not, iterate through full nodes until the end of the list.
		auto n = headString;
		while (n->next != nullptr){
			n = n->next;
		}
		node<std::string> last(nullptr, v); //Create node given the input.
		n->next = std::make_shared<node<std::string>>(last); //Add it to the end of the list.
	}
}



void linkedlist::print(int i){ //Print has a flag to determine which list to print.
	switch (i){
	case(1) : {auto n = headInt;
				std::cout << "\tHead:" << n->value << ", "; //Print head value.
				while (n->next != nullptr){
					n = n->next;
					std::cout << n->value << ", "; //Print subsequent values.
				}
				std::cout << "End of linked list.\n\n" << std::endl; }
		break;
	case(2) : {auto n = headChar;
			std::cout << "\tHead:" << n->value << ", "; //Print head value.
			while (n->next != nullptr){
				n = n->next;
				std::cout << n->value << ", "; //Print subsequent values.
			}
			std::cout << "End of linked list.\n\n" << std::endl; }
		break;
	case(3) : {auto n = headString;
			std::cout << "\tHead:" << n->value << ", "; //Print head value.
			while (n->next != nullptr){
				n = n->next;
				std::cout << n->value << ", "; //Print subsequent values.
			}
			std::cout << "End of linked list.\n\n" << std::endl; }
	}
	
}

void linkedlist::delNode(int s){
	if (headInt->value == s){
		headInt = headInt->next;
	}
	auto n = headInt;
	while (n->next != nullptr){
		if (n->next->value == s){
			n->next = n->next->next;
			std::cout << "deleted " << s << std::endl;
		}
		n = n->next;
	}
	std::cout << "End of linked list.\n\n" << std::endl;

}