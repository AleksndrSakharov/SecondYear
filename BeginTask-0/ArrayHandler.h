#pragma once
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

template<typename T>
class ArrayHandler {
private:
    T *_array;
    size_t _size;
    size_t _count;
    T _maxT;
    T _minT;

    void Resize(size_t new_size) {
        T *new_array = new T[new_size];
        std::move(_array, _array + _count, new_array);
        delete[] _array;
        _array = new_array;
        _size = new_size;
    };

public:
    ArrayHandler() : _size(10), _count(0) {
        _array = new T[_size];
    };

    ArrayHandler(size_t size) : _size(size), _count(0) {
        _array = new T[_size];
    };

    void AppendElem(const T &elem) {
        if (_count == 0){
            _maxT = elem;
            _minT = elem;
        }else{
            if (_maxT < elem) _maxT = elem;
            if (_minT > elem) _minT = elem;
        }
        if (_count == _size) {
            Resize(_size * 128);
        }
        _array[_count++] = elem;
    };

    bool IsContains(const size_t &elem) const {
        return std::find(_array, _array + _count, elem) != (_array + _count);
    };

    T GetMax() const {
        if (_count == 0) throw std::runtime_error("Array is empty");
        return _maxT;
    };

    T GetMin() const {
        if (_count == 0) throw std::runtime_error("Array is empty");
        return _minT;
    };

    ~ArrayHandler() {
        delete[] _array;
    };
};