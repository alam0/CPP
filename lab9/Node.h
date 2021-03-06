#ifndef _NODE_H_
#define _NODE_H_

template<typename T> class LinkedList; // forward declaration of List

template<typename T>   // templated node type
class Node {

  friend class LinkedList<T>;    // make the main class a friend

 public:
  Node(const T &);     // constructor
  T getData() const;   // get function
  void setParent(Node<T> *, Node<T> *);

 private:
  int data;           // data for linked list node
  std::string label;
  Node<T> *left;    // pointer to left child 
  Node<T> *right;    // pointer to right child
};

// NOTE:  all of the functions are in the .h file to overcome issues with
//        templates and linking

// constructor, using member initialization list syntax
template<typename T>
Node<T>::Node(const T &info) :data(info),next(NULL) {}

// simple get function for our class (if friendship is not used)
template<typename T>
T Node<T>::getData(void) const { return data; }

template<typename T>
void Node<T>::setParent(Node<T> *left, Node<T> *right){
	if (left.data >= right.data){
		data = left->data;
		label = left->label;
	} else {
		Node<T> *parent;
		data = right->data;
		label = right->label;
	}
}


#endif

