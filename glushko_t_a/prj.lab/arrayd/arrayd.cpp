#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>



ArrayD::ArrayD() {
	memory = nullptr;
	size = 0;

}

ArrayD::~ArrayD() {
	delete[] memory;
	return;
}

ArrayD::ArrayD(const std::ptrdiff_t length) : size(length), memory(new double[length]) {}

ArrayD::ArrayD(const ArrayD& arr) : size(arr.size), memory(new double[arr.size]) {
    for (std::ptrdiff_t i = 0; i < size; ++i) {
        memory[i] = arr.memory[i];
    }
}

ArrayD::ArrayD(const std::ptrdiff_t size_c, double num) : size(size_c), memory(new double[size_c]) {
    for (std::ptrdiff_t i = 0; i < size_c; ++i) {
        memory[i] = num;
    }
}

ArrayD::~ArrayD() {
    delete[] memory;
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size;
}

double& ArrayD::operator[](const std::ptrdiff_t i) {
    return memory[i];
}

const double& ArrayD::operator[](const std::ptrdiff_t i) const {
    return memory[i];
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    double* new_memory = new double[new_size];
    std::ptrdiff_t min_size = new_size < size ? new_size : size;
    for (std::ptrdiff_t i = 0; i < min_size; ++i) {
        new_memory[i] = memory[i];
    }
    delete[] memory;
    memory = new_memory;
    size = new_size;
}

void ArrayD::insert(const std::ptrdiff_t index, const double num) {
    if (index < 0 || index > size) {
        return;
    }
    resize(size + 1);
    for (std::ptrdiff_t i = size - 1; i > index; --i) {
        memory[i] = memory[i - 1];
    }
    memory[index] = num;
}

void ArrayD::remove(const std::ptrdiff_t index) {
    if (index < 0 || index >= size) {
        return;
    }
    for (std::ptrdiff_t i = index; i < size - 1; ++i) {
        memory[i] = memory[i + 1];
    }
    resize(size - 1);
}

std::ostream& ArrayD::writeTo(std::ostream& ostrm) const {
    for (std::ptrdiff_t i = 0; i < size; ++i) {
        ostrm << memory[i];
        if (i != size - 1) {
            ostrm << comm << ' ';
        }
    }
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) {
    return rhs.writeTo(ostrm);
}

bool operator==(const ArrayD& lhs, const ArrayD& rhs) {
}
