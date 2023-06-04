#include "sources/MagicalContainer.hpp"
#include "doctest.h"
#include <stdexcept>
#include <iostream>

using namespace ariel;
using namespace std;




TEST_CASE("Magical Container function"){
    MagicalContainer myContainer;
    CHECK_EQ(myContainer.size() , 0);

    for (int i = 1; i < 5; ++i) {
        CHECK_NOTHROW(myContainer.addElement(i));
        CHECK_EQ(myContainer.size() , i);
    }

    int size = myContainer.size();
    myContainer.addElement(3);
    CHECK_EQ(myContainer.size() , size);

    for (int i = 4; i > 0 ; --i) {
        CHECK_EQ(myContainer.size() , i);
        CHECK_NOTHROW(myContainer.removeElement(i));
    }
}

TEST_CASE("basic Test Iterator"){
    MagicalContainer myContainer;
    MagicalContainer::AscendingIterator empty(myContainer);
    CHECK_EQ(empty.begin() , empty.end());

    CHECK_THROWS_AS(*empty , runtime_error);
    for (int i = 0; i < 10; ++i) {
        CHECK_NOTHROW(myContainer.addElement(i));
    }
    MagicalContainer::AscendingIterator Iter(myContainer);
    int count = 0;
    for (auto i = Iter.begin() ; i != Iter.end() ; ++i) {
        count++;
    }
    CHECK_EQ(count , myContainer.size());

    CHECK((Iter.begin() < Iter.end()));
    CHECK((Iter.end() > Iter.begin()));

}

TEST_CASE("Adding elements apter create iterator"){
    MagicalContainer myContainer;
    myContainer.addElement(3);
    MagicalContainer::AscendingIterator iter(myContainer);
    auto  it = iter.begin();
    CHECK_EQ(*it , 3);
    myContainer.addElement(7);
    ++it;
    CHECK_EQ(*it , 7);
    myContainer.addElement(5);
    ++it;
    CHECK_EQ(*it , 7); // still 7 because the sort

}

TEST_CASE("Ascending Iterator Test"){
    MagicalContainer myContainer;
    myContainer.addElement(3);
    myContainer.addElement(7);
    myContainer.addElement(2);
    myContainer.addElement(8);
    myContainer.addElement(1);

    MagicalContainer::AscendingIterator ascIter(myContainer);
    int sum = *ascIter.begin();
    CHECK_EQ(sum , 1);
    sum += *++ascIter;
    CHECK_EQ(sum , 3);
    sum += *++ascIter;
    CHECK_EQ(sum , 6);
    sum += *++ascIter;
    CHECK_EQ(sum , 13);
    sum += *++ascIter;
    CHECK_EQ(sum , 21);

}


TEST_CASE("SideCross Iterator Test"){
    MagicalContainer myContainer;
    myContainer.addElement(3);
    myContainer.addElement(7);
    myContainer.addElement(2);
    myContainer.addElement(8);
    myContainer.addElement(1);

    MagicalContainer::SideCrossIterator ascIter(myContainer);
    int sum = *ascIter.begin();
    CHECK_EQ(sum , 1);
    sum += *++ascIter;
    CHECK_EQ(sum , 9);
    sum += *++ascIter;
    CHECK_EQ(sum , 11);
    sum += *++ascIter;
    CHECK_EQ(sum , 18);
    sum += *++ascIter;
    CHECK_EQ(sum , 21);

}

TEST_CASE("Prime Iterator Test"){
    MagicalContainer myContainer;
    myContainer.addElement(3);
    myContainer.addElement(7);
    myContainer.addElement(2);
    myContainer.addElement(8);
    myContainer.addElement(1);

    MagicalContainer::PrimeIterator primeIter(myContainer);
    int sum = *primeIter.begin();
    CHECK_EQ(sum , 2);
    sum += *++primeIter;
    CHECK_EQ(sum , 5);
    sum += *++primeIter;
    CHECK_EQ(sum , 12);
}

TEST_CASE("bad arguments") {
    MagicalContainer myContainer1;
    MagicalContainer myContainer2;

    MagicalContainer::AscendingIterator ascIter1(myContainer1);
    MagicalContainer::AscendingIterator ascIter2(myContainer2);

    bool flag;

    CHECK_THROWS_AS(flag = (ascIter1 == ascIter2), runtime_error);
    CHECK_THROWS_AS(flag = (ascIter1 != ascIter2), runtime_error);
    CHECK_THROWS_AS(flag = (ascIter1 < ascIter2), runtime_error);
    CHECK_THROWS_AS(flag = (ascIter1 > ascIter2), runtime_error);


    MagicalContainer::SideCrossIterator crossIter1(myContainer1);
    MagicalContainer::SideCrossIterator crossIter2(myContainer2);

    CHECK_THROWS_AS(flag = (crossIter1 == crossIter2), runtime_error);
    CHECK_THROWS_AS(flag = (crossIter1 != crossIter2), runtime_error);
    CHECK_THROWS_AS(flag = (crossIter1 < crossIter2 ), runtime_error);
    CHECK_THROWS_AS(flag = (crossIter1 > crossIter2 ), runtime_error);

    MagicalContainer::PrimeIterator primeIter1(myContainer1);
    MagicalContainer::PrimeIterator primeIter2(myContainer2);

    CHECK_THROWS_AS(flag = (primeIter1 == primeIter2), runtime_error);
    CHECK_THROWS_AS(flag = (primeIter1 != primeIter2), runtime_error);
    CHECK_THROWS_AS(flag = (primeIter1 < primeIter2) , runtime_error);
    CHECK_THROWS_AS(flag = (primeIter1 > primeIter2) , runtime_error);

}


