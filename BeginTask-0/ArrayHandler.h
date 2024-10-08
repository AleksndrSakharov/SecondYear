#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <limits> 

template<typename T>
class ArrayHandler {
private:
    T *_array;
    size_t _size;
    size_t _count;
    T _maxT;
    T _minT;

public:
    ArrayHandler() : _size(1000000), _count(0), _minT(std::numeric_limits<T>::max()), _maxT(std::numeric_limits<T>::min()) {
        _array = new T[_size];
    }

    ArrayHandler(size_t size) : _size(size), _count(0), _minT(std::numeric_limits<T>::max()), _maxT(std::numeric_limits<T>::min()) {
        _array = new T[_size];
    } 

    void AppendElem(T elem) {
        _array[_count++] = elem;
        _minT = (elem < _minT) ? elem : _minT;
        _maxT = (elem > _maxT) ? elem : _maxT;
    
    }

    bool IsContains(const T &elem) const {
        for (size_t i = 0; i < _count; ++i) {
            if (_array[i] == elem) return true;
        }
        return false;
    }
      
    

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

