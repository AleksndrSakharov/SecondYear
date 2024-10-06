#pragma once
#include <cstdlib>
#include <limits>

template<typename T>
class ArrayHandler {
private:
    T *_array;
    size_t _size;
    size_t _count;
    T _maxT;
    T _minT;

    // void Resize(size_t new_size) {
    //     T *new_array = new T[new_size];
    //     std::move(_array, _array + _count, new_array);
    //     delete[] _array;
    //     _array = new_array;
    //     _size = new_size;
    // }


public:
    ArrayHandler() : _size(1000002), _count(0), _minT(std::numeric_limits<T>::max()), _maxT(std::numeric_limits<T>::min()) {
        _array = new T[_size];
    }

    ArrayHandler(size_t size) : _size(size), _count(0), _minT(std::numeric_limits<T>::max()), _maxT(std::numeric_limits<T>::min()) {
        _array = new T[_size];
    }

    void AppendElem(const T &elem) {
        _minT = (elem < _minT) ? elem : _minT;
        _maxT = (elem > _maxT) ? elem : _maxT;
        // if (_count == _size) {
        //     Resize(_size * 2);
        // }
        _array[_count++] = elem;
    }

    // bool IsContains(const T &elem) const {
    //     for (size_t i = 0; i < _count; ++i) {
    //         if (_array[i] == elem) return true;
    //     }
    //     return false;
    // }

    

    T GetMax() const {
        return _maxT;
    }

    T GetMin() const {
        return _minT;
    }

    ~ArrayHandler() {
        delete[] _array;
    }
};
