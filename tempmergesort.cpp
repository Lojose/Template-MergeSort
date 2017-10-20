#include "List.h"

List::List () {
	Listfront = nullptr;
	Listback = nullptr;  
	n = 0, x = 0;
}
List::~List () {
}
 
bool List::empty() const {
	return Listfront == nullptr;
}

void List::push_back (int val) {
	Link *pt1 = new Link (val);
	if (empty()) {
		Listfront = Listback = pt1;
	} else {
		for (Link *cur1 = Listfront; cur1 != nullptr; cur1 = cur1->next) {
			if (cur1 == nullptr) Listback = cur1; 
			pt1 = Listback; 
		}
		Link *update1 = new Link(val); 
		Listfront->next = update1; 
		Listfront = update1; 
	}
	n++; 
}

void List::push_front(int val) {
	Link *pt2 = new Link(val); 
	if (empty ()) {
		Listback = Listfront = pt2; 
	}
	else {
		for (Link *cur2 = Listfront; cur2 != nullptr; cur2 = cur2->next) {
			if (cur2 == nullptr) Listfront = cur2; 
			cur2 = Listfront; 
		}
		Link *update2 = new Link(val); 
		Listback->next = update2; 
		Listback = update2; 
	}
	n++; 
}

void List::prepop_back(int val) {
		Link *pt3 = new Link(val);
		Listback->next = pt3;
		Listback = pt3;
		delete pt3;
	
}

void List::prepop_front(int val) {
	Link *pt5 = new Link(val);
	Listfront = pt5; 
	delete pt5;
}
void List::pop_back() {
	prepop_back(0); 
	++x; 
}

void List::pop_front() {
	prepop_front(0); 
	++x; 

}
int List::size() {
	int l  = n - x; 
	return l;
 }
Iterator List::begin() {
	return Iterator(Listfront); 
	//if (link = nullptr) return Iterator(nullptr); 
}





/* cout << a << endl; 
list<int> a;
for (list<int>::iterator i = Listback.begin(); i != Listfront.end(); ++i)
cout << *i << endl
*/
