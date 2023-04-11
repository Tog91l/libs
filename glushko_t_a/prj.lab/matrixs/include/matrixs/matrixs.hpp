#pragma once
#include <iostream>
#include <string>
#ifndef MATRIXS_MATRIXS_HPP_20230215
#define MATRIXS_MATRIXS_HPP_20230215

class MatrixS {

public:
	using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

public:
	explicit MatrixS(const SizeType& size = { 0,0 });
	MatrixS(const std::ptrdiff_t rows, const std::ptrdiff_t colns);
	~MatrixS();

	MatrixS(const MatrixS& other);
	MatrixS& operator=(const MatrixS& other);

	void resize(const SizeType& new_size);
	void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);

private:
	ptrdiff_t _rows;
	ptrdiff_t _colns;
	int* data;
};

#endif
