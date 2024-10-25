#include "Set.h"
//СКОПИРОВАЛ = ПID@Р
Set::operator BitField() {
    return BitField(this->_bitfield);
}

Set::Set(const BitField& tmp) : _maxPower(tmp.GetLength()), _bitfield(tmp) {}

Set::Set(const Set& tmp):_maxPower(tmp.GetMaxPow()), _bitfield(tmp._bitfield) {
}

Set::Set(const size_t maxPower) :_bitfield(maxPower) { _maxPower = maxPower; }

void Set::InsElem(uint64_t elem) {
    if (elem < _maxPower)
        _bitfield.SetBit(elem);
    else {
        throw "Elem out of range";
    }
}

vector<uint64_t> Set::GetPrimary() const{
    vector <uint64_t> res;
    unordered_set<int> used;
    size_t tmp = _maxPower;
    res.push_back(1);
    for (int i = 2; i < tmp + 1; i++){
    
        if (used.find(i) != used.end()) continue;
    
        else{
            res.push_back(i);
            for (int j = i + 1; j < tmp + 1; j++)
                if (j % i == 0) used.insert(j);
            
       }
    }
    return res;
}

void Set::DelElem(uint64_t elem) {
    _bitfield.ClrBit(elem);
}
//СКОПИРОВАЛ = ПID@Р
size_t Set::GetMaxPow() const {
    return _maxPower;
}

bool Set::IsMember(uint64_t elem) {
    if (elem < _maxPower && elem >= 0){
        if (_bitfield.GetBit(elem) == 1) return true;
        }
        return false;
}

bool Set::operator==(const Set& tmp) const{
    if (_bitfield == tmp._bitfield)
        return true;
    return false;
}

bool Set::operator!=(const Set& tmp) const{
    if (_bitfield == tmp._bitfield)
        return false;
    return true;
}

Set& Set::operator= (const Set& tmp) {
    _maxPower = tmp._maxPower;
    _bitfield = tmp._bitfield;
    return *this;
}
//СКОПИРОВАЛ = ПID@Р
Set Set::operator+(const Set& tmp) {
    Set result(max(tmp._maxPower, _maxPower));
    result._bitfield = _bitfield | tmp._bitfield;
    return result;
}


void Set::operator+(uint64_t elem) {
    InsElem(elem);
}

void Set::operator-(uint64_t elem) {
    DelElem(elem);
}

Set Set::operator*(const Set& tmp) {
    Set result(max(tmp._maxPower, _maxPower));
    result._bitfield = _bitfield & tmp._bitfield;
    return result;
}
//СКОПИРОВАЛ = ПID@Р
Set Set::operator~() {
    Set result(_maxPower);
    result._bitfield = ~_bitfield;
    return result;
}


ostream& operator<<(ostream& os, const Set& tmp) {
    os << tmp._bitfield;
    return os << endl;
};

istream& operator>>(istream& is, Set& tmp) {
    is >> tmp._maxPower;
    is >> tmp._bitfield;
    return is;
}

