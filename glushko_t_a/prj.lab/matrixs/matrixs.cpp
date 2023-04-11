#include <matrixs/matrixs.hpp>

MatrixS::MatrixS(const SizeType& size) {
	if (_rows < 0 || _colns < 0) {
		throw std::invalid_argument("Size can't be negative");
	}
}

MatrixS::~MatrixS() {
	delete[] data;
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

void MatrixS::resize(const SizeType& new_size) {
	//if (new_size <= 0) {
	//	throw std::invalid_argument("Sizes must be positive");
	//}

}
