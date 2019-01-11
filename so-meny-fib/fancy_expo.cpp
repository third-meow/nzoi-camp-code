#include<bits/stdc++.h>
using namespace std;

const uint64_t modulo_val = 1000000;

struct Matrix {
	uint64_t a, b, c, d;

	static Matrix one() {
		return { 1, 0, 0, 1 };
	}

	Matrix operator*(Matrix other) const {
		return {
			(a * other.a + b * other.c) % modulo_val,
			(a * other.b + b * other.d) % modulo_val,
			(c * other.a + d * other.c) % modulo_val,
			(c * other.b + d * other.d) % modulo_val
		};
	}

	Matrix operator*=(Matrix other) {
		*this = *this * other;
		return *this;
	}

	Matrix pow(uint64_t n) {
		if (n == 0) return Matrix::one();
		if (n == 1) return *this;

		Matrix r = pow(n / 2);
		r *= r;
		if (n % 2 == 1) r *= *this;
		return r;
	}

	pair<uint64_t, uint64_t> apply(pair<uint64_t, uint64_t> v) {
		return make_pair(
			(a * v.first + b * v.second) % modulo_val,
			(c * v.first + d * v.second) % modulo_val
		);
	}
};

uint64_t fib_fast(uint64_t n) {
	Matrix m = { 0, 1, 1, 1 };
	return m.pow(n).apply({ 0, 1 }).first;
}

int main() {
	uint64_t n;
	cin >> n;
	//uint64_t r = fib_slow(n);
	uint64_t r = fib_fast(n);
	cout << r << endl;
}
