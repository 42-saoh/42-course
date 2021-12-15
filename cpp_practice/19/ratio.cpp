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

template <typename U, typename V, typename W>
struct Dim
{
	using M = U;
	using L = V;
	using T = W;
	using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_
{
	typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
			typename Ratio_add<typename U::L, typename V::L>::type,
			typename Ratio_add<typename U::T, typename V::T>::type> type;
};

template <typename U, typename V>
struct subtract_dim_
{
	typedef Dim<typename Ratio_sub<typename U::M, typename V::M>::type,
			typename Ratio_sub<typename U::L, typename V::L>::type,
			typename Ratio_sub<typename U::T, typename V::T>::type> type;
};

template <typename T, typename D>
struct quantity
{
	T q;
	using dim_type = D;
	
	quantity operator+(quantity<T, D> quant)
	{
		return quantity<T, D>(q + quant.q);
	}
	quantity operator-(quantity<T, D> quant)
	{
		return quantity<T, D>(q - quant.q);
	}
	template <typename D2>
	quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant)
	{
		return quantity<T, typename add_dim_<D, D2>::type>(q * quant.q);
	}
	template <typename D2>
	quantity<T, typename subtract_dim_<D, D2>::type> operator/(quantity<T, D2> quant)
	{
		return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
	}
	quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }
	quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }
	quantity(T q) : q(q) {}
};

template <typename T, typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q)
{
	out << q.q << "kg^" << D::M::num / D::M::den << " * m^" << D::L::num / D::L::den << " * s^" << D::T::num / D::T::den;
	return out;
}

int main()
{
	using one = Ratio<1, 1>;
	using zero = Ratio<0, 1>;

	quantity<double, Dim<one, zero, zero> > kg(2);
	quantity<double, Dim<zero, one, zero> > meter(3);
	quantity<double, Dim<zero, zero, one> > second(1);

	auto F = kg * meter / (second * second);
	std::cout << "2 kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는? " << F << std::endl;
	return (0);
}
