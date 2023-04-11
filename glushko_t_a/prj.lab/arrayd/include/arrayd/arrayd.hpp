#pragma once
#include <iostream>
#include <string>
#ifndef ARRAYD_ARRAYD_HPP_20230215
#define ARRAYD_ARRAYD_HPP_20230215

class ArrayD {
public:
	ArrayD();
	ArrayD( const ptrdiff_t length);
	ArrayD(const ArrayD&);
	ArrayD& operator=(const ArrayD&);
	~ArrayD();

	explicit ArrayD(const std::ptrdiff_t size = 0);

	std::ptrdiff_t ssize() noexcept;

	double& operator[](const ptrdiff_t i);
	const double& operator[](const ptrdiff_t i)const; // i - index

	
	void resize( const ptrdiff_t new_size);
	void insert(const ptrdiff_t i, const double num);
	void remove(const ptrdiff_t i);

	bool operator ==(const ArrayD& rhs);
	

	std::ostream writeTo(std::ostream& ostrm)const;
	std::istream readFrom(std::istream& istrm);

private:
	std:: ptrdiff_t size;
    double* memory;


};

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs);
std::iostream& operator>>(std::istream& istrm, const ArrayD& rhs);


bool operator==(const ArrayD& lhs, const ArrayD& rhs);

#endif
