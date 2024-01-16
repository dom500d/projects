# Projects
This is a collection of small projects that I've worked on.

## C++ Projects
Here's all the projects in C++

### Range-Constrained Integer
This is a templated class that takes a size on initialization. I store the actual value for the range-constrained integer in a std::bitset so I can use the least amount of memory possible for the range wanted. Since it's a templated class, I need to determine the size of the bitset at compile time, I can't do so dynamically. To solve this, I found a macro which computes log2. Using this, I'm able to determine the number of bits needed to store the max range value.
