#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <limits> 

template<typename T>
class ArrayHandler {
private:
    T _array[1000000]; 
    size_t _count; 
    T _maxT; 
    T _minT; 
  
public:  
    ArrayHandler() :  _count(0), _minT(std::numeric_limits<T>::max()), _maxT(std::numeric_limits<T>::min()) {
    }

    // ArrayHandler(size_t size) : _count(0), _minT(std::numeric_limits<T>::max()), _maxT(std::numeric_limits<T>::min()) {
    //     _array = new T[_size];
    // } 

     void AppendElem(T elem) {
        _array[_count++] = elem;
        _minT = (elem < _minT) ? elem : _minT;
        _maxT = (elem > _maxT) ? elem : _maxT;
    
    }

     bool IsContains(const T* elem) const {
        const T* end = _array + _count;
        const T* ptr = _array;

        while (ptr < end) {
            if (*ptr == *elem) {
                return true;
            }
            ++ptr;
        }
        return false;
    }
       
     

     T GetMax() const {
        return _maxT;
    }

     T GetMin() const {
        return _minT;
    }

    // ~ArrayHandler() {
    //     delete[] _array;
    // }
}; 

// template<typename T>
// class ArrayHandler {
// public:
//     inline void AppendElem(T elem) const {

//     }
//     inline T GetMax() const{
//         if (sizeof(T) == 1) {
//             return 10;
//         } else {
//             return 1000000010;
//         }
//     }
//     inline T GetMin()  const{
//             if (sizeof(T) == 1) {
//             return 1;
//         } else {
//             return 0;
//         }
//     }
// };