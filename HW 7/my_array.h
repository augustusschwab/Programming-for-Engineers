#pragma once
// MyArray is a basic fixed size dynamically allocated array
// of integers.
class MyArray {
	// Size of the array we've allocated
	size_t size;
	// Pointer to the array of ints being stored
	int *array;
public:
	MyArray(size_t sz);
	~MyArray();
	MyArray(const MyArray &a);
	MyArray& operator=(const MyArray &rhs);
	int& operator[](size_t i);
	const int& operator[](size_t i) const;
	size_t get_size() const;
};
