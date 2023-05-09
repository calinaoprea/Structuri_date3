#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->current = this->bag.first;
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
void BagIterator::first() {
    this->current = this->bag.first;
}

//best case: O(1)
//worst case: O(n)
//overall case: O(n)
void BagIterator::next() {
    if (!valid()){
        throw exception();
    } else {
        this->current = this->bag.nextLink[this->current];
    }
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
bool BagIterator::valid() const {
    return (this->current!=-1);
}

//best case: O(1)
//worst case: O(1)
//overall case: O(1)
TElem BagIterator::getCurrent() const
{
    if (!valid()){
        throw exception();
    } else {
        return this->bag.e[this->current];
    }
}
