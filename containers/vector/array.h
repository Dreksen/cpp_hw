#include <iostream>
#include <fstream>

class Array {
private:
    std::ostream& Ostream_;
    size_t capacity, size;
    int *data = nullptr;
    void Copy(const Array &other){
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        if(capacity == 0){
            capacity = 2;
            return ;
        }
        else{
            data = new int[capacity];
            for(size_t i = 0; i < size; ++i){
                data[i] = other.data[i];
            }
        }
    }

public:

    size_t Size() const { return size; }
    size_t Capacity() const { return capacity; }

    Array(std::ostream& ostream) : Ostream_(ostream), capacity(2), size(0) {
        Ostream_ << "Constructed. " << *this << '\n';
    }
    Array(const Array& array) : Ostream_(array.Ostream_), capacity(array.capacity), size(array.size){
        Copy(array);
        Ostream_ << "Constructed from another Array. " << *this << '\n';
    }
    Array(size_t size, std::ostream& ostream = std::cout, int defaultValue = 0) : Ostream_(ostream), capacity(2 * size), size(size){
        delete[] data;
//        Reserve(capacity);
        data = new int[capacity];
        for(size_t i = 0; i < this->size; i++) {
            data[i] = defaultValue;
        }
        Ostream_ << "Constructed with default. " << *this << '\n';
    }
    ~Array() {
        Ostream_ << "Destructed " << this->size << '\n';
        delete[] data;
    }


    void Reserve(size_t newCapacity) {
        if (capacity > 0){
            if(capacity <= newCapacity) {
                capacity = newCapacity;
                if (capacity == 0){
                    capacity = 2;
                }
                int *data2 = new int[capacity];
                for(size_t i = 0; i < size; i++) {
                    if (data == nullptr)
                        break;
                    data2[i] = data[i];
                }
                delete [] data;
                data = data2;
//        data = new int[capacity];
//        for(size_t i = 0; i < size; i++) {
//          this->data[i] = data2[i];
//        }
//        delete [] data2;
            }
        }
        else{
            delete[] data;
            data = new int[newCapacity];
        }
    }
    void Resize(size_t newSize) {
        Reserve(newSize);
        size = newSize;
//        int *data2 = new int[capacity];
//        for(size_t i = 0; i < size; i++) {
//            data2[i] = data[i];
//        }
//        delete [] data;
//        data = data2;
    }
    void PushBack(int value = 0) {
        if (size == capacity || data == nullptr) {
            capacity *= 2;
            if (capacity == 0){
                capacity += 2;
            }
            Reserve(capacity);
        }
        data[size] = value;
        size++;
    }
    void PopBack() {
        size--;
    }

    const int& operator[](const size_t i) const {
        return data[i];
    }
    int& operator[](const size_t i) {
        return data[i];
    }
    explicit operator bool() const { return size > 0; }

    bool operator<(const Array& it) const {
        for (size_t i = 0; i < std::min(size, it.size); i++) {
            if (data[i] > it.data[i]) {
                return false;
            }
            else if(data[i] < it.data[i]){
                return true;
            }
        }
        return size < it.size;
    }
    bool operator>(const Array& it) const { return !(*this < it) && !(*this == it); }
    bool operator!=(const Array& it) const { return !(*this == it); }
    bool operator==(const Array& it) const {
        for(size_t i = 0; i < std::min(size, it.size); ++i){
            if(data[i] != it.data[i]){
                return false;
            }
        }
        if(size != it.size){
            return false;
        }
        return true;
    }
    bool operator<=(const Array& it) const { return (*this < it) || (*this == it); }
    bool operator>=(const Array& it) const { return (*this > it) || (*this == it); }

    Array& operator<<(const int value) {    PushBack(value); return *this; }
    Array& operator<<(const Array& it) {
        for(size_t i = 0; i < it.size; i++) {
            this->PushBack(it[i]);
        }
        return *(this);
    }
    friend std::ostream& operator<<(std::ostream& ostream, const Array& array) {

        ostream << "Result Array's capacity is " << array.capacity << " and size is " << array.size;
        if (array.size != 0) {
            ostream << ", elements are: ";

            for(size_t i = 0; i < array.size - 1; i++) {
                ostream << array.data[i] << ", ";
//                f<< array.data[i] << ", ";
            }
            ostream << array.data[array.size - 1];
//            f << array.data[array.size - 1] << std::endl;
        }
        return ostream;
    }
};

