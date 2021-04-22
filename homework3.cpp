#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
template <typename UnOp>
auto n_compos(UnOp f, size_t n) {
    return [f, n](auto fun) {
        auto p = fun;
        for (int j = 0; j< n; j++)
            p = f(p);
        return p;
    };
}
int main() {
	auto half4 = n_compos([](double x) {return 0.5 * x; }, 4);
	cout << half4(8.0) << std::endl;
	double (*f)(double) = sqrt;
	auto sqrt2 = n_compos(f, 2);
	cout << sqrt2(0.0625) << endl;

}