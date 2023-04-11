#pragma once
#include <iostream>
#include <string>
#ifndef ARRAYT_ARRAYT_HPP_20230215
#define ARRAYT_ARRAYT_HPP_20230215

template<typename T>
class ArrayT {
public:
	ArrayT();
	ArrayT( const ptrdiff_t length);
	ArrayT(const ArrayT&);
	ArrayT& operator=(const ArrayT&);
	~ArrayT();

	

	std::ptrdiff_t ssize() noexcept;

	T& operator[](const ptrdiff_t i);
	const T& operator[](const ptrdiff_t i)const; // i - index

	
	void resize( const ptrdiff_t new_size);
	void insert(const ptrdiff_t i, const double num);
	void remove(const ptrdiff_t i);

	

	std::ostream writeTo(std::ostream& ostrm)const;
	//std::istream readFrom(std::istream& istrm);

private:
	std:: ptrdiff_t size;
    T* memory;


};





#endif
