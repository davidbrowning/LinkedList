#ifndef DEFINE 'LIST_HPP'
#include<iostream>
#include<memory>
#include<cstdlib>
#include<fstream>
#include<string>
template <typename T>

struct node{
	node(){};
	node(std::shared_ptr<node<T>> p, T v){
		value = v;
		next = p;
	}
	~node(){};
	std::shared_ptr<node<T>> next;
	T value;
	
};
class linkedlist{
public:
	linkedlist();
	~linkedlist();
	void insert(int);
	void insert(char);
	void insert(std::string);
	void delNode(int);
	void print(int);
	std::shared_ptr<node<int>> headInt;
	std::shared_ptr<node<char>> headChar;
	std::shared_ptr<node<std::string>> headString;
};
#endif // !DEFINE 'LIST_HPP'


