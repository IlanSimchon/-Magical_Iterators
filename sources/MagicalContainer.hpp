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

            AscendingIterator(AscendingIterator &other) = default;
            AscendingIterator(AscendingIterator&& other) noexcept = default;

            ~AscendingIterator() = default;

            AscendingIterator begin();

            AscendingIterator end();

            AscendingIterator&  operator=(AscendingIterator const &other);
            AscendingIterator& operator=(AscendingIterator&& other) noexcept;


            bool operator==(AscendingIterator other) const;

            bool operator!=(AscendingIterator other) const;

            bool operator<(AscendingIterator other) const;

            bool operator>(AscendingIterator other) const;

            AscendingIterator& operator++();

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

            SideCrossIterator(SideCrossIterator& other) = default;
            SideCrossIterator(SideCrossIterator&& other) noexcept = default;

            ~SideCrossIterator() = default;

            SideCrossIterator begin();

            SideCrossIterator end();

            SideCrossIterator& operator=(SideCrossIterator const &other);
            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;


            bool operator==(SideCrossIterator other) const;

            bool operator!=(SideCrossIterator other) const;

            bool operator<(SideCrossIterator other) const;

            bool operator>(SideCrossIterator other) const;

            SideCrossIterator& operator++();

            int operator*();

        };
            class PrimeIterator{
            private:
                MagicalContainer &cont;
                int index;
            public:
                PrimeIterator(MagicalContainer &cont);

                PrimeIterator(MagicalContainer &cont, int index);

                PrimeIterator(PrimeIterator& other) = default;
                PrimeIterator(PrimeIterator&& other) noexcept = default;


                ~PrimeIterator() = default;

                PrimeIterator begin();

                PrimeIterator end();

                PrimeIterator& operator=(PrimeIterator const &other);
                PrimeIterator& operator=(PrimeIterator&& other) noexcept;


                bool operator==(PrimeIterator other) const;

                bool operator!=(PrimeIterator other) const;

                bool operator<(PrimeIterator other) const;

                bool operator>(PrimeIterator other) const;

                PrimeIterator& operator++();

                int operator*();

    };
            bool contains(int value);
    };

    bool isPrime(int value);
}
#endif //CPP_EX5_MAGICALCONTAINER_HPP

