This week's challenge is to create a range-limited template class called “Integer”.  It will behave like an int,  but be range-limited as specified in constructor.  Assume support for math operators, comparison, assignment.   How do you handle errors? How will you test and validate?   Attach your source file (integer.*) to the engineering notebook repository.

For this challenge, I handled errors resulting from value being outside the specified range for the Integer class by throwing an
out_of_range exception. This is the only way I could think of to stop the constructor from actually constructing
an object from the class when the value should be out of the range. I followed this pattern for all of the other operators that could
result in a value being out of the range of the Integer specified. One thing I think I could improve is instead of using an int to store the value,
using a bitarray or some other method of storing the value that I can dynamically determine. Pretty much so if I want to only have a max range of
255 I can only take up 8 bits instead of however many are allocated for an integer by the compiler. After implementing everything using an integer in the background to store
the value, I changed it to a bit array (std::bitset). Figured I might as well try it.

As for testing and validating, I will instantiate a few objects, each with a different range, and then try to instantiate objects
with values that are inside the specified range, and outside the range. I will then use my operators on the objects to see if I am catching
every use case that could result in an Integer object getting a value that is outside the specified range.