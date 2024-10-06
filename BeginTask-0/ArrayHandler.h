#pragma once
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

template<typename T>
class ArrayHandler {
private:
    T *_array;
    size_t _size;
    size_t _count;
    T _maxT;
    T _minT;
    bool _isSorted;

    void Resize(size_t new_size) {
        T *new_array = new T[new_size];
        std::move(_array, _array + _count, new_array);
        delete[] _array;
        _array = new_array;
        _size = new_size;
    }

    void UpdateMinMax(const T &elem) {
        if (_count == 0) {
            _maxT = elem;
            _minT = elem;
        } else {
            if (elem > _maxT) _maxT = elem;
            if (elem < _minT) _minT = elem;
        }
    }

    void SortArrayIfNeeded() {
        if (!_isSorted) {
            std::sort(_array, _array + _count);
            _isSorted = true;
        }
    }

public:
    ArrayHandler() : _size(1000000), _count(0), _isSorted(false) {
        _array = new T[_size];
    }

    ArrayHandler(size_t size) : _size(size), _count(0), _isSorted(false) {
        _array = new T[_size];
    }

    void AppendElem(const T &elem) {
        UpdateMinMax(elem);
        if (_count == _size) {
            Resize(_size * 2);
        }
        _array[_count++] = elem;
        _isSorted = false;
    }

    bool IsContains(const T &elem) {
        SortArrayIfNeeded();
        return std::binary_search(_array, _array + _count, elem);
    }

    T GetMax() const {
        if (_count == 0) throw std::runtime_error("Array is empty");
        return _maxT;
    }

    T GetMin() const {
        if (_count == 0) throw std::runtime_error("Array is empty");
        return _minT;
    }

    ~ArrayHandler() {
        delete[] _array;
    }
};
