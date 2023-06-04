#ifndef CPP_EX5_MAGICALCONTAINER_HPP
#define CPP_EX5_MAGICALCONTAINER_HPP

#include <vector>
#include <set>

using  namespace std;
namespace  ariel {
    class MagicalContainer {
    private:
        vector<int> myContainer;
        vector<int *> primes;
    public:
        MagicalContainer();

        void addElement(int element);

        void removeElement(int value);

        int size();

        void print();

        class AscendingIterator {
        private:
            MagicalContainer &cont;
            int index;
        public:
            AscendingIterator(MagicalContainer &cont);

            AscendingIterator(MagicalContainer &cont, int index);

            AscendingIterator begin();

            AscendingIterator end();

            bool operator==(AscendingIterator other) const;

            bool operator!=(AscendingIterator other) const;

            bool operator<(AscendingIterator other) const;

            bool operator>(AscendingIterator other) const;

            AscendingIterator operator++();

            int operator*();


        };

        class SideCrossIterator {
        private:
            MagicalContainer &cont;
            int index;
            int s_index;
            int e_index;
        public:
            SideCrossIterator(MagicalContainer &cont);

            SideCrossIterator(MagicalContainer &cont, int index);

            SideCrossIterator begin();

            SideCrossIterator end();

            bool operator==(SideCrossIterator other) const;

            bool operator!=(SideCrossIterator other) const;

            bool operator<(SideCrossIterator other) const;

            bool operator>(SideCrossIterator other) const;

            SideCrossIterator operator++();

            int operator*();

        };
            class PrimeIterator{
            private:
                MagicalContainer &cont;
                int index;
            public:
                PrimeIterator(MagicalContainer &cont);

                PrimeIterator(MagicalContainer &cont, int index);

                PrimeIterator begin();

                PrimeIterator end();

                bool operator==(PrimeIterator other) const;

                bool operator!=(PrimeIterator other) const;

                bool operator<(PrimeIterator other) const;

                bool operator>(PrimeIterator other) const;

                PrimeIterator operator++();

                int operator*();

    };
            bool contains(int value);
    };

    bool isPrime(int value);
}
#endif //CPP_EX5_MAGICALCONTAINER_HPP

