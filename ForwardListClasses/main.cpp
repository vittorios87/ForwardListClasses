#include "Node.h"
#include "Node.cpp"
#include "SinglyLinkedList.h"
#include "SinglyLinkedList.cpp"
#include <forward_list>

using namespace std;
int main() 
{
	cout << "Test empty list constructor" << endl;
	SinglyLinkedList<char>* mySLList1 = new SinglyLinkedList<char>();
	mySLList1->printList();
	cout << endl;

	Node<char>* charNode1 = new Node<char>( 'Z');
	Node<char>* charNode2 = new Node<char>( 'e');
	Node<char>* charNode3 = new Node<char>( 'u');
	Node<char>* charNode4 = new Node<char>( 's');
	Node<char>* charNode5 = new Node<char>( '.');

	cout << "Test appendNode method" << endl;
	mySLList1->appendNode(charNode1);
	mySLList1->appendNode(charNode2);
	mySLList1->appendNode(charNode3);
	mySLList1->appendNode(charNode4);
	mySLList1->appendNode(charNode5);
	mySLList1->printList();
	cout << endl;

	cout << "Test copy constructor" << endl;
	SinglyLinkedList<char> mySLList2 = *mySLList1;
	mySLList2.printList();
	cout << endl;

	cout << "Test move constructor" << endl;
	SinglyLinkedList<char> mySLList3 = std::move(*mySLList1);
	mySLList3.printList();
	cout << endl;

	mySLList1->printList();
	cout << endl;
	cout << endl;

	cout << "Test constructor with size and values, then move constructor" << endl;
	size_t sz = 6;
	char prova = 'A';
	SinglyLinkedList<char> mySLList4 = std::move(*(new SinglyLinkedList<char>(sz,prova)));
	mySLList4.printList();
	cout << endl;

	cout << "Test constructor with size" << endl;
	SinglyLinkedList<char> mySLList5 = SinglyLinkedList<char>(sz);
	mySLList5.printList();
	cout << endl;

	
	cout << "Test push_front and pop_front on the same list." << endl;
	mySLList5.push_front('a');
	mySLList5.printList();
	mySLList5.pop_front();
	mySLList5.printList();
	mySLList5.pop_front();
	mySLList5.printList();
	cout << endl;

	cout << "Test iterators and insert_after (with lvalue reference and rvalue reference)." << endl;
	SinglyLinkedList<char>::iterator_t myIteratorBegin = mySLList5.begin();
	SinglyLinkedList<char>::iterator_t myIteratorEnd = mySLList5.end();
	char toAdd = 'V';
	mySLList5.insert_after(myIteratorBegin, toAdd);
	mySLList5.printList();
	mySLList5.insert_after(myIteratorEnd, 'S');
	mySLList5.printList();
	cout << endl;

	cout << "Test remove on empty list" << endl;
	SinglyLinkedList<char> mySLList6 = SinglyLinkedList<char>();
	mySLList6.remove('.');
	cout << endl;

	cout << "Test insert_after with a value to insert many times on empty list." << endl;
	SinglyLinkedList<char>::iterator_t myIteratorBegin3 = mySLList6.begin();
	cout << "1st insertion:" << endl;
	mySLList6.insert_after(myIteratorBegin3, 7, 'V');
	mySLList6.printList();
	cout << endl;

	cout << "Test insert_after with a value to insert many times on not - empty list." << endl;
	myIteratorBegin3 = ++mySLList6.begin();
	myIteratorBegin3 = ++myIteratorBegin3;
	cout << "1st insertion:" << endl;
	mySLList6.insert_after(myIteratorBegin3, 3, 'S');
	myIteratorBegin3 = mySLList6.end();
	cout << "2nd insertion:" << endl;
	mySLList6.insert_after(myIteratorBegin3, 4, 'R');
	myIteratorBegin3 = ++mySLList6.end();
	cout << "3rd insertion:" << endl;
	mySLList6.insert_after(myIteratorBegin3, 2, 'F');
	mySLList6.printList();
	cout << endl;

	cout << "Test remove (4 times) on not empty list" << endl;
	cout << " remove R" << endl;
	mySLList6.remove('R');
	mySLList6.printList();
	cout << " remove G" << endl;
	mySLList6.remove('G');
	mySLList6.printList();
	cout << " remove v" << endl;
	mySLList6.remove('v');
	mySLList6.printList();
	cout << " remove V" << endl;
	mySLList6.remove('V');
	mySLList6.printList();
	cout << endl;

	cout << "Test remove_if on not empty list" << endl;
	mySLList6.insert_after(mySLList6.begin(), 'a');
	mySLList6.insert_after(mySLList6.begin(), 'b');
	mySLList6.insert_after(mySLList6.begin(), 'c');
	mySLList6.insert_after(++mySLList6.begin(), 'd');
	mySLList6.printList();
	mySLList6.remove_if(islower);
	mySLList6.printList();
	cout << endl;

	cout << "Test reverse method" << endl;
	Node<char>* charNodeV  = new Node<char>('V');
	Node<char>* charNodeI1 = new Node<char>('i');
	Node<char>* charNodeT1 = new Node<char>('t');
	Node<char>* charNodeT2 = new Node<char>('t');
	Node<char>* charNodeO1 = new Node<char>('o');
	Node<char>* charNodeR  = new Node<char>('r');
	Node<char>* charNodeI2 = new Node<char>('i');
	Node<char>* charNodeO2 = new Node<char>('o');

	SinglyLinkedList<char> mySLList7 = SinglyLinkedList<char>();
	mySLList7.prependNode(charNodeV);
	mySLList7.prependNode(charNodeI1);
	mySLList7.prependNode(charNodeT1);
	mySLList7.prependNode(charNodeT2);
	mySLList7.prependNode(charNodeO1);
	mySLList7.prependNode(charNodeR);
	mySLList7.prependNode(charNodeI2);
	mySLList7.prependNode(charNodeO2);
	mySLList7.printList();
	mySLList7.reverse();
	mySLList7.printList();
	cout << endl;

	cout << "Test clear method" << endl;
	mySLList7.clear();
	mySLList7.printList();
	cout << endl;

	cout << "Test iterators and erase_after." << endl;
	SinglyLinkedList<char>::iterator_t myIteratorBegin2 = mySLList5.begin();
	mySLList5.erase_after(myIteratorBegin2);
	mySLList5.printList();
	cout << endl;

	cout << "Test erase_after with end pointer (tail) iterator." << endl;
	SinglyLinkedList<char>::iterator_t myIteratorEnd2 = mySLList5.end();
	mySLList5.erase_after(myIteratorEnd2);
	mySLList5.printList();
	cout << endl;

	cout << "Test erase_after with null pointer iterator obtained by pre-increment operator." << endl;
	++myIteratorEnd2;
	mySLList5.erase_after(myIteratorEnd2);
	mySLList5.printList();
	cout << endl;

	cout << "Test erase_after inside an interval, given by two iterators. The element pointed by the last iterator is not erased." << endl;
	mySLList5.erase_after(mySLList5.end(), myIteratorEnd2);
	mySLList5.printList();
	cout << endl;

	cout << "Test erase_after inside an interval, given by two iterators." << endl;
	mySLList5.erase_after(++(++mySLList5.begin()),nullptr);
	mySLList5.printList();
	cout << endl;











	/*
	std::forward_list<int> ciao;
	int c = 7;
	ciao.pop_front();
	*/
	while (true) {

	}

}