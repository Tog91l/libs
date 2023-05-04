#include <arrayd/arrayd.hpp>

ArrayD::ArrayD(){
	memory = nullptr;
	size = 0;
	
}

ArrayD::~ArrayD(){
	delete[] memory;
	return;
}

ArrayD::ArrayD(const std::ptrdiff_t size_c) {

}

ArrayD::ArrayD(const std::ptrdiff_t size_c, const double num) {

}

std::ptrdiff_t ArrayD::ssize()const noexcept {
	return size;
}

double& ArrayD::operator[](const std::ptrdiff_t i) {
	return memory[i];
}


const double& ArrayD::operator[](const std::ptrdiff_t i)const {
	return memory[i];
}

void ArrayD::resize(ptrdiff_t new_size) {
	if (new_size < 0) {
		throw std::invalid_argument("ArrayD can't be less than zero");
	}
	if (new_size > 0) {

		double* memory_temp;
		memory_temp = new double[new_size];
		for (int i = 0; i < size; i++) {
			memory_temp[i] = memory[i];
		}
		for (int i = size; i < new_size; i++) {
			memory_temp[i] = 0;
		}
		delete[] memory;
		memory = new double[size];
		for (int i = 0; i < size; i++) {
			memory[i] = memory_temp[i];
		}
		delete[] memory_temp;
	}
}

void ArrayD::insert(const std::ptrdiff_t n, const double num) {

}


void ArrayD::remove(const std::ptrdiff_t n) {

}


std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) {
	return ostrm;
}
