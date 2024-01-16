//
// Created by Dominic Orlando on 1/12/24.
//
#include <iostream>

/*
 * Macro gotten from https://stackoverflow.com/a/11376759. Needed a way to either at compile time
 * or before compile time determine the log2 of the max value so the bitset contains only the
 * number of bits that are strictly necessary.
 */
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))

template <size_t aMax=100>
class Integer {
protected:
    std::bitset<LOG2(aMax)> value;
public:
     Integer(const int aValue=0) {
        if(aValue > aMax) {
            throw std::out_of_range("Value is greater than the max value for this range-constrained integer!");
        } else if(aValue < 0) {
            throw std::out_of_range("Value is less than 0");
        } else {
            this->value = aValue;
        }
    }

    Integer& operator=(const Integer& aRef) {
        if(aRef.value > aMax || aRef.value < 0) {
            throw std::out_of_range("Value is out of range");
        } else {
            this->value = aRef.value;
        }
        return *this;
    }

    template<size_t copy_max>
    operator Integer<copy_max>() {
        if(copy_max < aMax) {
            if(this->value.to_ulong() > copy_max || this->value.to_ulong() < 0) {
                throw std::out_of_range("Typecast value out of range of thing");
            }
        }
        return this->value.to_ulong();
    };

    bool operator==(const Integer &aRef) {
        if(this->value == aRef.value) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Integer &rRef) {
        if(this->value.to_ulong() > rRef.value.to_ulong()) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const Integer &rRef) {
        if(this->value.to_ulong() < rRef.value.to_ulong()) {
            return true;
        } else {
            return false;
        }
    }

    int operator+(const Integer& rRef) {
        int result = this->value.to_ulong() + rRef.value.to_ulong();
        return result;
    }

    int operator-(const Integer &rRef) {
        return this->value.to_ulong() - rRef.value.to_ulong();
    }

    int operator*(const Integer &rRef) {
        return this->value.to_ulong() * rRef.value.to_ulong();
    }

    int operator/(const Integer &rRef) {
        return this->value.to_ulong() / rRef.value.to_ulong();
    }

    int operator%(const Integer &rRef) {
        return this->value.to_ulong() / rRef.value.to_ulong();
    }
};
