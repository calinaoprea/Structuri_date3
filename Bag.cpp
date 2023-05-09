#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

//best case: O(1)
//worst case: O(cp) - cp is the capacity of the bag
//overall case: O(cp)
Bag::Bag() {
	//TODO - Implementation
	first = -1;
	for(int i=0; i<cp-1; i++)
		nextLink[i] = i+1;
	nextLink[cp-1] = -1;
	firstEmpty = 0;
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
int Bag::allocate(){
	int i = firstEmpty;
	firstEmpty = nextLink[firstEmpty];
	return i;
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
void Bag::deallocate(int i){
	nextLink[i] = firstEmpty;
	firstEmpty = i;
}

//best case: O(1)
//worst case: O(cp) - cp is the capacity of the bag
//overall case: O(cp)
int Bag::createNode(TElem elem){
	int i = allocate();
	if(i != -1){
		this->e[i] = elem;
		nextLink[i] = -1;
	}
	return i;
}

//best case: O(1)
//worst case: O(cp) - cp is the capacity of the bag
//overall case: O(cp)
void Bag::add(TElem elem) {
	//TODO - Implementation
	int i = this->createNode(elem);
	if(i!=-1){
		nextLink[i] = first;
		first = i;
	}
}

//best case: O(1)
//worst case: O(n) - n is the number of elements in the bag
//overall case: O(n)
bool Bag::remove(TElem elem) {
	//TODO - Implementation
	bool found = false;
	int current = this->first;
	int previous = -1;
	while(current != -1 && !found){
		if (this->e[current] == elem)
			found = true;
		else {
			previous = current;
			current = this->nextLink[current];
		}
	}
	if (!found){
		return false;
	}
	else {
		if (previous == -1)
			this->first = this->nextLink[this->first];
		else
			this->nextLink[previous] = this->nextLink[current];
	}
	deallocate(current);
	return true;
}

//best case: O(1)
//worst case: O(n) - n is the number of elements in the bag
//overall case: O(n)
bool Bag::search(TElem elem) const {
	//TODO - Implementation
	bool found = false;
	int current = this->first;
	while (current != -1 && !found) {
		if (this->e[current] == elem)
			found = true;
		else
			current = this->nextLink[current];
	}
	return found;
}

//best case: O(1)
//worst case: O(n) - n is the number of elements in the bag
//overall case: O(n)
int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	int n = 0;
	int current = this->first;
	while (current != -1){
		if (this->e[current] == elem)
			n++;
		current = this->nextLink[current];
	}
	return n;
}

//best case: O(1)
//worst case: O(n) - n is the number of elements in the bag
//overall case: O(n)
int Bag::size() const {
	//TODO - Implementation
	int n = 0;
	int current = this->first;
	while (current != -1) {
		n++;
		current = this->nextLink[current];
	}
	return n;
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
bool Bag::isEmpty() const {
	//TODO - Implementation
	return (first == -1);
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
Bag::~Bag() {
    //no need to deallocate e and nextLink arrys here
}