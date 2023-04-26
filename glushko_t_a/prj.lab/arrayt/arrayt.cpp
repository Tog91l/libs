#include <arrayt/arrayt.hpp>

template<typename T>
ArrayT<T>::ArrayT() {
	memory = nullptr;
	size = 0;
	
}

template<typename T>
ArrayT<T>::~ArrayT() {
	delete[] memory;
	return;
}
template<typename T>
void ArrayT<T>::resize(ptrdiff_t new_size) {
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

	/*void ArrayD::insert(const std::ptrdiff_t i, const double num)
	{
		if (i<0 || i >size()) {
			throw std::invalid_argument("you don't need to use it");
		}
		resize(size() + 1);
		for (int l = i + 1; i < size(); l++) {
			memory[l] = memory[l - 1];
		}
		memory[i] = num;
	}*/
     
template<typename T>
	void ArrayT<T>::remove(const std::ptrdiff_t i) {
		
		return;
	}
