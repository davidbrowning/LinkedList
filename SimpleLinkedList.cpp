#include<iostream>
#include<vector>
#include<cstdlib>
#include<memory>

template<typename T>
struct Node{
  public:
    T value;
    std::shared_ptr<Node<T>> next;
};

template<typename T>
class linkedlist{
  public:
     linkedlist<T>(){}
     ~linkedlist<T>(){}

     void insert(T val)
     {
       Node<T> n;
       n.value = val;
       n.next = nullptr;

       if(head == nullptr)
       {
         head = std::make_shared<Node<T> >(n);
         return;
       }

       auto node = head;
       while (node->next != nullptr)
       {
        node = node->next;
       }
       node->next = std::make_shared<Node<T> >(n);
     }

     std::shared_ptr<Node<T> > get_head()
     {
       return head;
     }

  private:
     std::shared_ptr<Node<T>> head;
};

int main()
{
  linkedlist<int> l;
  for (int i = 0; i < 10; ++i)
  {
    l.insert(i);
  }
  auto n = l.get_head();

  do
  {
    std::cout << n->value << std::endl;
    n = n->next;
  }while(n != nullptr);
       
  return EXIT_SUCCESS;
}
