#include <iostream>

template<typename T>
class Array {
private:
    size_t capacity, size;
    std::ostream& Ostream_ = std::cout;

public:
    T *data = nullptr;
    size_t Size() const { return size; }
    size_t Capacity() const { return capacity; }

    Array(std::ostream& ostream) {
        size = 0;
        capacity = 2;
        data = new T[capacity];
        Ostream_ << "Constructed. " << *this << '\n';
    }

    Array(const Array<T>& array) {
        size = array.size;
        capacity = array.capacity;
        data = new T[capacity];

        for(size_t i = 0; i < size; i++) {
            data[i] = array[i];
        }
        Ostream_ << "Constructed from another Array. " << *this << '\n';
    }

    Array(size_t size, std::ostream& ostream = std::cout, T defaultValue = T()) {
        this->size = int(size);
        capacity = this->size * 2;
        data = new T[capacity];

        for(size_t i = 0; i < this->size; i++) {
            data[i] = defaultValue;
        }
        Ostream_ << "Constructed with default. " << *this << '\n';
    }

    ~Array() {
        delete[] data;
        data = nullptr;
        Ostream_ << "Destructed " << this->size << '\n';
    }

    void Reserve(size_t newCapacity) {
        if(capacity <= newCapacity) {
            capacity = newCapacity;
            T *data2 = new T[capacity];
            for(size_t i = 0; i < size; i++) {
                data2[i] = this->data[i];
            }
            if (data != nullptr) {
                delete [] data;
            }
            data = data2;
        }
    }

    void Resize(size_t newSize) {
        if (newSize > size) {
            size = newSize;
            //capacity = newSize;
            Reserve(newSize);
        } else {
            size = newSize;
        }
    }

    void PushBack(T value = 0) {
        if (size == capacity) {
            capacity *= 2;
            Reserve(capacity);
        }
        data[size] = value;
        size++;
    }

    void PopBack() {
      size--;
    }

    const T& operator [](const size_t i) const { return data[i]; }

    T& operator [](const size_t i) { return data[i];}

    explicit operator bool() const { return size > 0; }

    bool operator <(const Array<T>& it) const {
        for (size_t i = 0; i < std::min(size, it.size); i++) {
            if (data[i] > it.data[i]) {
                return false;
            }
             if(data[i] < it.data[i]){
                return true;
            }
        }
        return size < it.size;
    }

    bool operator >(const Array<T>& it) const {
        return !(*this < it) && !(*this == it);
    }

    bool operator !=(const Array<T>& it) const { return !(*this == it);
    }

    bool operator ==(const Array<T>& it) const {
        if(size != it.size){
            return false;
        }
        for(size_t i = 0; i < size; i++){
            if(data[i] != it.data[i]){
                return false;
            }
        }
        return true;
    }

    bool operator <=(const Array<T>& it) const {
        return (*this < it) || (*this == it);
    }

    bool operator >=(const Array<T>& it) const {
        return (*this > it) || (*this == it);
    }

    Array<T>& operator <<(const T& value) {
        PushBack(value); return *this;
    }

    Array<T>& operator <<(const Array<T>& it) {
        for(size_t i = 0; i < it.size; i++) {
            this->PushBack(it[i]);
        }
        return *(this);
    }
    void Clear() {
        size = 0;
        capacity = 2;
        delete [] data;
        data = new T[capacity];
    }
    bool Insert(size_t pos, const T& value) {
      if (pos > size) {
        return false;
      }
      Resize(size + 1);
      for (size_t i = pos + 1; i < size; i++) {
        data[i] = data[i - 1];
      }
      data[pos] = value;
      return true;
    }

    bool Erase(size_t pos) {
        if (size == 0 || pos >= size) {
          return false;
        }
        for (size_t i = pos; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        Resize(size - 1);
        return true;
    }
    template<typename TO>
    friend std::ostream& operator <<(std::ostream& ostream, const Array<TO>& array);
};

template<typename T>
std::ostream& operator <<(std::ostream& ostream, const Array<T>& array) {
    ostream << "Result Array's capacity is " << array.capacity << " and size is " << array.size;
    if (array.size != 0) {
        ostream << ", elements are: ";

        for(size_t i = 0; i < array.size - 1; i++) {
            ostream << array.data[i] << ", ";
        }
        ostream << array.data[array.Size() - 1];
    }
    return ostream;
}

