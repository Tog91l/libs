#include <matrixs/matrixs.hpp>

MatrixS::MatrixS() {
	rows = 0;
	cols = 0;
	data = nullptr;
}


MatrixS::MatrixS(const SizeType& s) {
	if (rows < 0 || cols < 0) {
		throw std::invalid_argument("Size can't be negative");
	}
}

MatrixS::MatrixS(std::ptrdiff_t rows, std::ptrdiff_t cols) {

}


MatrixS::MatrixS(std::ptrdiff_t rows, std::ptrdiff_t cols, int num) {

}

const int& MatrixS::at(const std::ptrdiff_t r, const std::ptrdiff_t c)const {
	return data[r, c];
}

int& MatrixS::at(const std::ptrdiff_t r, const std::ptrdiff_t c) {
	return data[r, c];
}

const int& MatrixS::at(const MatrixS::SizeType s)const {
	return data[0];
}

int& MatrixS::at(const MatrixS::SizeType s) {
	return data[0];
}

MatrixS::~MatrixS() {
	delete[] data;
}


std::ptrdiff_t MatrixS::NRows()const noexcept {
	return rows;
}

std::ptrdiff_t MatrixS::NCols()const noexcept {
	return cols;
}

void  MatrixS::resize(const std::ptrdiff_t row, const std::ptrdiff_t coln) {
	if (row <= 0 || coln <= 0) {
		throw std::invalid_argument("Sizes must be positive");
	}
	int* data_temp;
	data_temp = new int[row, coln];
	for (int i = 0; i < row; i++) {
		for (int c = 0; c < coln; c++) {

		}
	}
	delete[] data_temp;
}

void MatrixS::resize(const SizeType& s) {
	//if (new_size <= 0) {
	//	throw std::invalid_argument("Sizes must be positive");
	//}

}

MatrixS::SizeType MatrixS::ssize()const noexcept {
	return SizeType(rows, cols);
}
