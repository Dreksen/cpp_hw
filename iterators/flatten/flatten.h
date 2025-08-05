#pragma once

#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>
#include <iostream>

template<class T>
class FlattenedVector {
private:
    std::vector<int> sizes;
    std::vector<std::vector<T>> *begin_;

public:
    template<bool IsConst>
    class iter {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = typename std::conditional<IsConst, const T *, T *>::type;
        using reference = typename std::conditional<IsConst, const T &, T &>::type;
        using vector_type = typename std::conditional<IsConst, const std::vector<std::vector<T>>, std::vector<std::vector<T>>>::type;

        iter(vector_type *begin_, const std::vector<int> *sizes, size_t pos = 0)
                : begin_(begin_), sizes(sizes), pos(pos) {
        }

        reference operator*() const {
            const int j = std::upper_bound(sizes->begin(), sizes->end(), pos) - sizes->begin();
            return (*begin_)[j-1][pos - (*sizes)[j - 1]];
        }

        iter &operator++() {
            ++pos;
            return *this;
        }

        iter operator++(int) {
            iter tmp = *this;
            ++(*this);
            return tmp;
        }

        iter &operator--() {
            --pos;
            return *this;
        }

        iter operator--(int) {
            iter tmp = *this;
            --(*this);
            return tmp;
        }

        iter operator+(difference_type n) const {
            iter tmp = *this;
            return tmp += n;
        }

        iter &operator+=(const difference_type n) {
            pos += n;
            return *this;
        }

        iter &operator-=(difference_type n) {
            return *this += -n;
        }

        iter operator-(difference_type n) const {
            iter tmp = *this;
            return tmp -= n;
        }

        difference_type operator-(const iter &other) const {
            return pos - other.pos;
        }

        reference operator[](difference_type n) const {
            return *(*this + n);
        }

        bool operator==(const iter &other) const { return pos == other.pos; }

        bool operator!=(const iter &other) const { return !(*this == other); }

        bool operator<(const iter &other) const { return pos < other.pos; }

        bool operator>(const iter &other) const { return other < *this; }

        bool operator<=(const iter &other) const { return !(other < *this); }

        bool operator>=(const iter &other) const { return !(*this < other); }

        friend iter operator+(const int n, iter a) {
            return a + n;
        }

    private:
        vector_type *begin_;
        const std::vector<int> *sizes;
        size_t pos;
    };

    using Iterator = iter<false>;
    using ConstIterator = iter<true>;

    explicit FlattenedVector(std::vector<std::vector<T>> &fv) : begin_(&fv) {
        sizes.push_back(0);
        for (const auto &vec: fv) {
            sizes.push_back(sizes[sizes.size() - 1] + vec.size());
        }
    }

    ConstIterator begin() const { return ConstIterator(begin_, &sizes); }
    ConstIterator end() const { return ConstIterator(begin_, &sizes, sizes.back()); }

    Iterator begin() { return Iterator(begin_, &sizes); }

    Iterator end() { return Iterator(begin_, &sizes, sizes.back()); }


};