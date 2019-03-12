#include "my_array.h"
#include <stdexcept>

// When our object is created it acquires a resource (in
// this case memory) to put itself in a valid usable state.
// It's valid usable state is an array of 'size' integers.
MyArray::MyArray(size_t sz) : size(sz), array(new int[size]) {}
	
// When our object is destroyed it must also release the
// resource (in this case memory) that it acquired.
MyArray::~MyArray() {
	delete[] array;
}
	
// Copy constructor must correctly copy an existing array's
// contents into this new one
MyArray::MyArray(const MyArray &a) : size(a.size), array(new int[size])
{
	for (size_t i = 0; i < size; ++i) {
		array[i] = a.array[i];
	}
}

// Copy-assignment operator must release our previous memory
// and get a copy of rhs's memory. We must also prevent
// self-assignment since this would result in us deleting
// and then trying to copy our own memory!
MyArray& MyArray::operator=(const MyArray &rhs) {
	// Check if we're actually the right hand side too
	if (this == &rhs) {
		return *this;
	}
	// Release our old memory
	delete[] array;
	// Allocate room to hold the copy of the right hand
	// side's array
	size = rhs.size;
	array = new int[size];
	// Copy over the right hand side's data
	for (size_t i = 0; i < size; ++i) {
		array[i] = rhs.array[i];
	}
	return *this;
}
	
int& MyArray::operator[](size_t i) {
	if (i >= size) {
		throw std::range_error("Index out of bounds");
	}
	return array[i];
}
	
// We must also provide a const accessor so we can index
// into a const MyArray
const int& MyArray::operator[](size_t i) const {
	if (i >= size) {
		throw std::range_error("Index out of bounds");
	}
	return array[i];
}

size_t MyArray::get_size() const {
		return size;
}

