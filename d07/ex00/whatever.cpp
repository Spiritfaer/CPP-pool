#include <iostream>

template <typename T>
T	max(T const &x, T const &y) {
	return (x > y ? x : y);
}

template <typename T>
T	min(T const &x, T const &y) {
	return (x < y ? x : y);
}

template <typename T>
void swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 42;
	int b = 21;

	float f1 = 42.042f;
	float f2 = 21.021f;

	std::cout << "\nTesting template with int\n" << std::endl;
	std::cout << "int a = " << a << std::endl;
	std::cout << "int b = " << b << std::endl;
	std::cout << "max = " << max<int>(a, b) << std::endl;
	std::cout << "min = " << min<int>(a, b) << std::endl;
	std::cout << "\nNow swap a and b" << std::endl;
	swap<int>(a, b);
	std::cout << "int a = " << a << std::endl;
	std::cout << "int b = " << b << std::endl;
	std::cout << "\nTesting template with float\n" << std::endl;
	std::cout << "float f1 = " << f1 << std::endl;
	std::cout << "float f2 = " << f2 << std::endl;
	std::cout << "max = " << max<float>(f1, f2) << std::endl;
	std::cout << "min = " << min<float>(f1, f2) << std::endl;
	std::cout << "\nNow swap f1 and f2" << std::endl;
	swap<float>(f1, f2);
	std::cout << "float f1 = " << f1 << std::endl;
	std::cout << "float f2 = " << f2 << std::endl;
	return 0;
}
