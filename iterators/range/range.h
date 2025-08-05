#pragma once
#include <iostream>

class Range {
private:
    long long begin_, end_, step_;
public:
    class RangeIterator {
    private:
        long long ptr_, step_;
    public:
        explicit RangeIterator(const long long ptr,const long long step, const long long end) : ptr_(ptr), step_(step){}
        long long operator*() const { return ptr_; }
        RangeIterator operator++(int) {
            const RangeIterator tmp = *this;
            ptr_+=step_;
            // std::cout << "++ " << ptr_ << ' ' << *tmp << std::endl;
            return tmp;
        }
        RangeIterator& operator++() {
            // std::cout << "Х++" << std::endl;
            ptr_+= step_;
            return *this;
        }
        RangeIterator operator--() {
            const RangeIterator tmp = *this;
            ptr_-=step_;
            return tmp;
        }
        RangeIterator& operator--(int) {
            --ptr_;
            return *this;
        }
        bool operator==(const RangeIterator& rhs) const { return ptr_ == rhs.ptr_;}
        bool operator!=(const RangeIterator& rhs) const { return !(ptr_ == rhs.ptr_);}
    };
    explicit Range(const long long n) : begin_(0), end_(n), step_(1) {}
    Range (const long long l, const long long r) : begin_(l), end_(r), step_(1) {}
    Range (const long long l, const long long r, const long long step) : begin_(l), end_(r == l ? r :
        l + step *((abs(r - l) - 1) / abs(step) + 1)),
    step_(step) {}
    // Range (const long long l, const long long r, const long long step) : begin_(l), end_(r),
    // step_(step) {}
    RangeIterator begin() const { return RangeIterator(begin_, step_, end_); }
    RangeIterator end() const {return RangeIterator(end_, step_, end_); }
    long long Size() const {return (end_ - begin_) / step_;}
};
