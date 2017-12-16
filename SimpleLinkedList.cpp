#include<iostream>
#include<vector>
#include<cstdlib>
#include<memory>
#include<string>
#include<sstream>

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

     void insert_front(T val)
     {
       Node<T> n;
       n.value = val;
       n.next = nullptr;

       if(head == nullptr)
       {
         head = std::make_shared<Node<T> >(n);
         return;
       }

       n.next = head;
       head = std::make_shared<Node<T> >(n);
     }

     void insert_back(T val)
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
       while(node->next != nullptr)
       {
         node = node->next;
       }

       node->next = std::make_shared<Node<T> >(n);
     }

     void delete_node(T val)
     {
       auto node = head;
       while (node->next != nullptr)
       {
         if(node->next->value == val)
         {
           node->next = node->next->next; 
         }
         node = node->next;
       }
     }

     void update_node(T toUpdate, T val)
     {
       auto node = head;
       if(node->value == toUpdate)
       {
         node->value = val; 
       }
       while (node->next != nullptr)
       {
         node = node->next;
         if(node->value == toUpdate)
         {
           node->value = val; 
         }
       }
     }

     std::string ToString()
     {
       std::stringstream ss;
       auto node = head;
       ss << "Head -> ";
       while(node != nullptr)
       {
         ss << node->value << " -> ";
         node = node->next;
       }
       ss << "nullptr";
       return ss.str();
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
  std::cout << "Inserting (front) 0 - 9. " << std::endl;
  for (int i = 0; i < 10; ++i)
  {
    l.insert_front(i);
  }

  std::cout << "Inserting (back) 0 - 9. " << std::endl;
  for (int i = 0; i < 10; ++i)
  {
    l.insert_back(i);
  }

  std::cout << "Deleting node (value = 4)." << std::endl;
  l.delete_node(4);
  std::cout << "Updating node (value = 3, to value = 20)." << std::endl;
  l.update_node(3, 20);
  auto s = l.ToString();
  std::cout << s << std::endl;

  linkedlist<std::string> strll;
  strll.insert_front("dave.");
  strll.insert_front(" is ");
  strll.insert_front(" name ");
  strll.insert_front(" my ");
  strll.insert_front("Hi, ");
  strll.update_node("dave.", "sierra.");
  std::cout << strll.ToString() << std::endl; 
  return EXIT_SUCCESS;
}
