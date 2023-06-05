#include "MagicalContainer.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace ariel;
using namespace std;
MagicalContainer::MagicalContainer() {};

void MagicalContainer::addElement(int element) {
        if(! this->contains(element)){
        this->myContainer.push_back(element);
        sort(this->myContainer.begin(), this->myContainer.end(), [](int a, int b) -> int { return a < b; });
        this->primes.clear();
        for (int i = 0; i < this->size() ; ++i) {
            if (isPrime(this->myContainer.at((vector<int>::size_type)i)))
                this->primes.push_back(&this->myContainer.at((vector<int>::size_type)i));
        }
    }
}

void MagicalContainer::removeElement(int value) {
    if(!this->contains(value))
        throw runtime_error("");
    for (vector<int>::size_type i = 0; i < this->myContainer.size(); ++i) {
        if (this->myContainer.at(i) == value)
            this->myContainer.erase(this->myContainer.begin() + (int) i);
    }
}

int MagicalContainer::size() {
    return this->myContainer.size();
}

void MagicalContainer::print() {
    for (int val : this->myContainer) {
        cout << val << " ";
    }
    cout << endl;
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont) :cont(cont) , index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(ariel::MagicalContainer &cont , int index) :cont(cont) , index(index) {}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(this->cont);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return AscendingIterator(this->cont , this->cont.size());
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator const &other) {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    this->index = other.index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(MagicalContainer::AscendingIterator other) const{
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index == other.index;
}

int MagicalContainer::AscendingIterator::operator*() {
    if(*this == this->end()){
        throw runtime_error("");
    }
    return this->cont.myContainer[(vector<int>::size_type)index];
}

bool MagicalContainer::AscendingIterator::operator!=(ariel::MagicalContainer::AscendingIterator other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(MagicalContainer::AscendingIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(MagicalContainer::AscendingIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index < other.index;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(*this == this->end())
        throw runtime_error("");
    this->index++;
    return *this;
}


// SideCrossIterator


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : cont(cont) , index(0) , s_index(0) , e_index(cont.size()-1) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont, int index) : cont(cont) , index(index) ,s_index(0) , e_index(cont.size()-1){}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(this->cont);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return SideCrossIterator(this->cont , cont.size());
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator const &other) {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    this->index = other.index;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(MagicalContainer::SideCrossIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(MagicalContainer::SideCrossIterator other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(MagicalContainer::SideCrossIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index < other.index;}

bool MagicalContainer::SideCrossIterator::operator>(MagicalContainer::SideCrossIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index > other.index;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(*this == this->end())
        throw runtime_error("");
    if (s_index == e_index)
        index = this->cont.size();
    else if (this->index < this->cont.size()/2) {
        index = e_index;
        e_index--;
    } else {
        s_index++;
        index = s_index;
    }
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() {
    if(*this == this->end()){
        throw runtime_error("here");
    }
    return this->cont.myContainer[(vector<int>::size_type)index];
}


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont) : cont(cont) , index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont, int index) : cont(cont) , index(index) {}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(this->cont);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator(this->cont , this->cont.primes.size());
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator const &other) {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    this->index = other.index;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(MagicalContainer::PrimeIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index == other.index;
}
bool MagicalContainer::PrimeIterator::operator!=(MagicalContainer::PrimeIterator other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(MagicalContainer::PrimeIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index < other.index;
}

bool MagicalContainer::PrimeIterator::operator>(MagicalContainer::PrimeIterator other) const {
    if(&this->cont != &other.cont)
        throw runtime_error("");
    return this->index > other.index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(*this == this->end())
        throw runtime_error("");
    this->index++;
    return  *this;
}

int MagicalContainer::PrimeIterator::operator*() {
    if(*this == this->end()){
        throw runtime_error("");
    }
    return *(this->cont.primes[(vector<int>::size_type)index]);
}

bool MagicalContainer::contains(int value) {
    for (int i = 0; i < this->size(); ++i) {
        if(this->myContainer.at((vector<int>::size_type)i) == value)
            return true;
    }
    return false;
}

bool ariel::isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
