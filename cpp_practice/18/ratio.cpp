#include <iostream>

template <int X, int Y>
struct GCD
{
	static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0>
{
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio
{
	private:
		const static int _gcd = GCD<N, D>::value;

	public:
		typedef Ratio<N / _gcd, D / _gcd> type;
		static const int num = N / _gcd;
		static const int den = D / _gcd;
};

template <typename R1, typename R2>
struct _Ratio_add
{
	typedef Ratio<R1::num * R2::den + R1::den * R2::num, R1::den * R2::den> type;
};

template <typename R1, typename R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <typename R1, typename R2>
struct _Ratio_sub
{
	typedef Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den> type;
};

template <typename R1, typename R2>
struct Ratio_sub : _Ratio_sub<R1, R2>::type {};

template <typename R1, typename R2>
struct _Ratio_mul
{
	typedef Ratio<R1::num * R2::num, R1::den * R2::den> type;
};

template <typename R1, typename R2>
struct Ratio_mul : _Ratio_mul<R1, R2>::type {};

template <typename R1, typename R2>
struct _Ratio_div
{
	typedef Ratio<R1::num * R2::den, R1::den * R2::num> type;
};

template <typename R1, typename R2>
struct Ratio_div : _Ratio_div<R1, R2>::type {};

int main()
{
	typedef Ratio<2, 3> rat;
  	typedef Ratio<3, 2> rat2;

 	using r3 = Ratio_add<rat, rat2>;
 	std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

	using r4 = Ratio_mul<rat, rat2>;
	std::cout << "2/3 * 3/2 = " << r4::num << " / " << r4::den << std::endl;

 	using r5 = Ratio_sub<rat, rat2>;
 	std::cout << "2/3 - 3/2 = " << r5::num << " / " << r5::den << std::endl;

	using r6 = Ratio_div<rat, rat2>;
 	std::cout << "2/3 / 3/2 = " << r6::num << " / " << r6::den << std::endl;
	return 0;
}
