#pragma once
#include <iostream>
#include <string>
#ifndef ARRAYT_ARRAYT_HPP_20230215
#define ARRAYT_ARRAYT_HPP_20230215

template<typename T>
class ArrayT {
public:
	ArrayT();
	explicit ArrayT( const std:: ptrdiff_t length);
	ArrayT(const ArrayT<T>&);
	ArrayT(std::ptrdiff_t size_c, T num);
	~ArrayT();

	

	std::ptrdiff_t ssize() const;

	T& operator[](std:: ptrdiff_t i);
	const T& operator[](std:: ptrdiff_t i)const; // i - index

	
	void resize( std:: ptrdiff_t new_size);
	void insert(std::ptrdiff_t, T num);
	void remove(std:: ptrdiff_t);

	

	std::ostream writeTo(std::ostream& ostrm)const;
	

private:
	std:: ptrdiff_t size;
    T* memory;

	static const char comm = ',';
};
#endif
