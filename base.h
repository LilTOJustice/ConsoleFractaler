#include <complex>
//collection of functions/constants relevant to fractal computation
#define max_radius 2
size_t iterations = 50;

inline bool radius_test(const std::complex<long double> &c, const std::complex<long double> &other) { //test if one complex number is within a *max_radius* distance of another
    return (c.real() - other.real())*(c.real() - other.real()) + (c.imag() - other.imag())*(c.imag() - other.imag()) < max_radius*max_radius;
}
inline bool fractal(const std::complex<long double> &c, std::complex<long double> (*frac)(const std::complex<long double>&,const std::complex<long double>&)) {
    std::complex<long double> result(0,0);
    for (size_t i = 0; i < iterations; i++) {
        result = frac(result, c);
        if (result.real() >= 2 || result.imag() >= 2) return false;
    }
    return true;
}

//fractal formulas
inline std::complex<long double> mandelbrot(const std::complex<long double> &result, const std::complex<long double> &c) {return result*result + c;}
inline std::complex<long double> burning_ship(const std::complex<long double> &result, const std::complex<long double> &c) {return {result.real()*result.real() - result.imag()*result.imag() - c.real(),2*fabs(result.real()*result.imag()) - c.imag()};}
inline std::complex<long double> mandelbrot3(const std::complex<long double> &result, const std::complex<long double> &c) {return result*result*result + c;}
