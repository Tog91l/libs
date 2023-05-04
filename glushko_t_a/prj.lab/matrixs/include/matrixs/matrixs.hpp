#pragma once
#include <iostream>
#include <string>
#ifndef MATRIXS_MATRIXS_HPP_20230215
#define MATRIXS_MATRIXS_HPP_20230215

class MatrixS {

public:
	using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

public:
	MatrixS();
	explicit MatrixS(const SizeType& size);
	MatrixS( std::ptrdiff_t rows,  std::ptrdiff_t cols);
	MatrixS(std::ptrdiff_t rows, std::ptrdiff_t cols, int num);
	MatrixS(const MatrixS&);

	~MatrixS();

	

	const int& at(const std::ptrdiff_t, const std::ptrdiff_t) const;
	int& at(const std::ptrdiff_t, const std::ptrdiff_t);
	const int& at(const SizeType)const;
	int& at(const SizeType);

	
	std::ptrdiff_t NRows() const noexcept;
	std::ptrdiff_t NCols() const noexcept;

	MatrixS& operator=(const MatrixS&);



	void resize(const SizeType&);
	void resize(const std::ptrdiff_t, const std::ptrdiff_t);

	SizeType ssize()const noexcept;

private:
	ptrdiff_t rows;
	ptrdiff_t cols;
	int* data;
};

#endif
