#include <complex>
//collection of functions/constants relevant to fractal computation
#define max_radius 2
size_t iterations = 20;

inline bool radius_test(const std::complex<long double> &c, const std::complex<long double> &other) { //test if one complex number is within a *max_radius* distance of another
    return (c.real() - other.real())*(c.real() - other.real()) + (c.imag() - other.imag())*(c.imag() - other.imag()) > max_radius*max_radius;
}

//fractal tests
bool mandelbrot_test(const std::complex<long double> &c) {
    std::complex<long double> result;
    for (size_t i = 0; i < iterations; i++) {
        result = (result * result) + c;
        if ((result.real() - c.real())*(result.real() - c.real()) + (result.imag() - c.imag())*(result.imag() - c.imag()) > max_radius*max_radius) return false;
    }
    return true;
}
