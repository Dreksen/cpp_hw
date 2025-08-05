//#inculde<bits/st>
#include <string>
using namespace std;
class CowString {
public:
    // constrcutors
    explicit CowString(string str) : sz(str.size()), capac(sz * 2), ref_count(1), data(&str[0]) {};
    CowString() : sz(0), capac(2), ref_count(1) {};
    // copy operator=
    CowString& operator=(CowString other) {
        if (ref_count == 1) {
            delete[] data;  //? []
        }
        data = other.data;
        sz = other.sz;
        capac = other.capac;
        ++(other.ref_count);
        return *this;
    }
    const char& At(size_t index) const {
        return data[index];
    }
    char& operator[](size_t index) {
        return data[index];
    }

    const char& Back() const {
        return data[sz - 1];
    }

    void PushBack(char c) {
        if (sz == capac) {
            Reserve(2 * capac);
        } 
        data[sz] = c;
        sz++;
        
    }
    
    size_t Size() const {
        return sz;
    }
    size_t Capacity() const {
        return capac;
    }

    void Reserve(size_t capacity) {
        char* newdata = new char[capacity];
        for (int i = 0; i < (int)sz; i++) {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        capac = capacity;
    }
    void Resize(size_t size) {
        if (sz < size) {
            Reserve(2 * size);
        }
        sz = size;

    }
private:
    size_t sz, capac;
    int ref_count;
    char* data;
};

//Clang-Tidy: Operator=() does not handle self-assignment properly 