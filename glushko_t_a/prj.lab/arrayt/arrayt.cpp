#include <arrayt/arrayt.hpp>

template<typename T>
ArrayT<T>::ArrayT() {
	memory = nullptr;
	size = 0;
	
}

template<typename T>
ArrayT<T>::ArrayT(std::ptrdiff_t size_c) {

}


template<typename T>
ArrayT<T>::ArrayT(std::ptrdiff_t size_c, T num) {

}

template<typename T>
ArrayT<T>::~ArrayT() {
	delete[] memory;
	return;
}

template<typename T>
std::ptrdiff_t ArrayT<T>::ssize()const {
	return size;
}

template<typename T>
T& ArrayT<T>::operator[](std::ptrdiff_t i) {
	return memory[i];
}


template<typename T>
const T& ArrayT<T>::operator[](std::ptrdiff_t i)const {
	return memory[i];
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

template <typename T>
void ArrayT<T>::insert(std::ptrdiff_t n, T num) {

}

template <typename T>
void ArrayT<T>::remove(std::ptrdiff_t n) {

}


template <typename T>
std::ostream& operator<<(std::ostream& ostrm, const ArrayT<T>& rhs) {
	return rhs.writeTo(ostrm);
}
