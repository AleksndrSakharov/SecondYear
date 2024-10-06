#pragma once
#include <cstdlib>
#include <stdexcept>
#include <algorithm> 
// #include <immintrin.h>

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

public:
    ArrayHandler() : _size(1000002), _count(0) {
        _array = new T[_size];
    }

    ArrayHandler(size_t size) : _size(size), _count(0) {
        _array = new T[_size];
    }

    void AppendElem(const T &elem) {
        UpdateMinMax(elem);
        if (_count == _size) {
            Resize(_size * 2);
        }
        _array[_count++] = elem;
    }

    // bool IsContains(const T &elem) const {
    //     for (size_t i = 0; i < _count; ++i) {
    //         if (_array[i] == elem) return true;
    //     }
    //     return false;
    // }

    

    // bool IsContains(const T* __restrict array, size_t count, const T elem) {
    //     const T* end = array + count;
    //     const __m256i search_value = _mm256_set1_epi32(elem);  // Устанавливаем элемент для поиска

    //     while (array + 8 <= end) {  // Каждая операция AVX работает с 8 32-битными элементами
    //         __m256i data = _mm256_loadu_si256((__m256i*)array);
    //         __m256i cmp = _mm256_cmpeq_epi32(data, search_value);
    //         if (_mm256_movemask_epi8(cmp) != 0) {  // Проверяем, есть ли совпадения
    //             return true;
    //         }
    //         array += 8;
    //     }

    //     // Оставшиеся элементы
    //     while (array < end) {
    //         if (*array == elem) return true;
    //         ++array;
    //     }

    //     return false;
    // }


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
