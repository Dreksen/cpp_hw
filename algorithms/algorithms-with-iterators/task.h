#include <cstdlib>
#include <iterator>
#include <cstdint>

/*
 * Нужно написать функцию, которая принимает на вход диапазон, применяет к каждому элементу данную операцию и затем складывает результат применения операции в новый диапазон
 * Входной диапазон задан итераторами [firstIn; lastIn)
 * Выходной диапазон начинается с firstOut и имеет такую же длину как входной диапазон
 * Операция является функцией с одним аргументом (унарная функция), возвращающая результат такого типа, который можно положить в OutputIt
 */

template<class InputIt, class OutputIt, class UnaryOperation>
void Transform(InputIt firstIn, InputIt lastIn, OutputIt firstOut, UnaryOperation op) {
//    for (auto& itIn = firstIn, itOut = firstOut; itIn != lastIn; itIn++, itOut++) {
//        *itOut = op(*itIn);
//    }
    for (; firstIn != lastIn; firstIn++, firstOut++) {
        *firstOut = op(*firstIn);
    }
}

/*
 * Нужно написать функцию, которая принимает на вход диапазон и переставляет элементы в нем таким образом, чтобы элементы,
 * которые удовлетворяют условию p, находились ближе к началу диапазона, чем остальные элементы.
 * Входной диапазон задан итераторами [first; last)
 * p является функцией с одним аргументом (унарная функция), возвращающая результат типа bool
 */

template<class BidirIt, class UnaryPredicate>
void Partition(BidirIt first, BidirIt last, UnaryPredicate p) {
    auto& fls = first, tre = first;
    while (fls != last) {
        while(fls != last && p(*fls)) {
            fls++;
        }
        if (fls == last)
            break;

        tre = fls;
        while (tre != last && !p(*tre)) {
            tre++;
        }
        if (tre == last)
            break;
        auto tmp = *tre;
        *tre = *fls;
        *fls = tmp;
    }
}

/*
 * Нужно написать функцию, которая принимает на вход два отстотированных диапазона и объединяет их в новый отсортированный диапазон, содержащий все элементы обоих входных диапазонов.
 */
template<class InputIt1, class InputIt2, class OutputIt>
void Merge(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt firstOut) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *firstOut = *first1;
            first1++;
        } else {
            *firstOut = *first2;
            first2++;
        }
        firstOut++;
    }
    while (first1 != last1) {
        *firstOut = *first1;
        firstOut++;
        first1++;
    }
    while (first2 != last2) {
        *firstOut = *first2;
        firstOut++;
        first2++;
    }
}


/*
 * Напишите класс "диапазон чисел Фибоначчи"
 * Экземпляр класса представляет из себя диапазон от первого до N-го числа Фибоначчи (1, 2, 3, 5, 8, 13 и т.д.)
 * С помощью функций begin и end можно получить итераторы и пробежать по диапазону или передать их в STL-алгоритмы
 */
class FibonacciRange {
private:
    size_t sz;
public:

    class Iterator {
        friend class FibonacciRange;
    private:
        uint64_t it, prev, n;
    public:
        using value_type = uint64_t;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::input_iterator_tag;

        Iterator(): it(1), prev(1), n(1) {};

        value_type operator *() const {
            // разыменование итератора -- доступ к значению
            return it;
        }

        Iterator& operator ++() {
            // prefix increment
            value_type next = it + prev;
            prev = it;
            it = next;
            ++n;
            return *this;
        }

        Iterator operator ++(int) {
            // postfix increment
            Iterator old;
            value_type next = it + prev;
            prev = it;
            it = next;
            ++n;
            return old;
        }

        bool operator ==(const Iterator& rhs) const {
            return it == rhs.it; // and n == rhs.n;
        }

        bool operator <(const Iterator& rhs) const {
            return n < rhs.n;
        }
    };

    FibonacciRange(size_t amount) : sz(amount){}

    Iterator begin() const {
        Iterator bg;
        return bg;
    }

    Iterator end() const {
        Iterator end;
        for (int i = 0; i < (int)sz; i++) {
            end++;
        }
        return end;
    }

    size_t size() const {
        return sz;
    }
};
