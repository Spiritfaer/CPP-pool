#include <iostream>
#include "Array.hpp"

class Foo
{
public:
	Foo() : _size(0), _data(new int[_size]) {}
	Foo(Foo const &other) {
		if (this != &other)
			*this = other;
	}
	Foo &operator=(Foo const &other) {
		delete [] _data;
		_size = other._size;
		_data = new int[_size];
		for (int i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
		return *this;
	}
	~Foo() { delete [] _data; }
	int _size;
	int *_data;
};

template <typename T>
void printArray(T const &array, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int		intArray[]		= { 24, 66, 84, 11, 0, 13, 74, 64, 28, 43, 61 };
	float	floatArray[]	= { 3.1415f, 42.042f, 210.021f, 0.123456f, 777.111f, 1716.655f, 65.45f };

	unsigned int sizeIntArray	= sizeof(intArray)/sizeof(intArray[0]);
	unsigned int sizeFloatArray	= sizeof(floatArray)/sizeof(floatArray[0]);

	Array <float>arF(sizeFloatArray, floatArray);
	Array <int>arI(sizeIntArray, intArray);

	try {
		printArray(arF.getData(), arF.size());
		printArray(arI.getData(), arI.size());
		std::cout << arF[arF.size() + 1] << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	Array <int>testCopyConstruct(arI);
	Array <float>TestOperator;
	Array <Foo>TestClassFoo;
	Array <Foo>tt;
	tt = TestClassFoo;

	TestOperator = arF;
	printArray(TestOperator.getData(), TestOperator.size());

	return 0;
}
