#pragma once
#include <iostream>
#include <string>
#include <sstream>
#ifndef ARRAYD_ARRAYD_HPP_20230215
#define ARRAYD_ARRAYD_HPP_20230215

class ArrayD {
public:
	ArrayD();
	explicit ArrayD( const std:: ptrdiff_t length);
	ArrayD(const ArrayD&);
	ArrayD(const std::ptrdiff_t size_c, double num);
	~ArrayD();

	

	std::ptrdiff_t ssize() const noexcept;

	double& operator[](const std:: ptrdiff_t i);
	const double& operator[](const std::ptrdiff_t i)const; // i - index

	
	void resize( const std:: ptrdiff_t new_size);
	void insert(const std:: ptrdiff_t, const double num);
	void remove(const std:: ptrdiff_t);

	
	

	std::ostream writeTo(std::ostream& ostrm)const;
	

private:
	std:: ptrdiff_t size;
    double* memory;

	static const char comm = ',' ;

};

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs);



bool operator==(const ArrayD& lhs, const ArrayD& rhs);

#endif
