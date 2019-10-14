#include <iostream>

template <typename T>
void iter(T *array, unsigned int size, void(*foo)(T &arr))
{
	for (unsigned int i = 0; i < size; ++i) {
		(*foo)(array[i]);
	}
}

template <typename T>
void testPlus(T &in)
{
	in += 42;
}

template <typename T>
void testMult(T &in)
{
	in *= 2;
}

template <typename T>
void printArray(T *array, unsigned int size)
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

	std::cout << "*  In array integers and gloat  *" << std::endl;
	printArray<int>(intArray, sizeIntArray);
	printArray<float>(floatArray, sizeFloatArray);

	std::cout << "\n*  Integer (x += 42) Float (x *= 2)  *" << std::endl;

	iter<int>(intArray, sizeIntArray, &testPlus);
	iter<float>(floatArray, sizeFloatArray, &testMult);

	std::cout << "\n*  Test info  *" << std::endl;
	printArray<int>(intArray, sizeIntArray);
	printArray<float>(floatArray, sizeFloatArray);

	std::cout << "\n*  Integer (x *= 2) Float (x += 42)  *" << std::endl;
	iter<int>(intArray, sizeIntArray, &testMult);
	iter<float>(floatArray, sizeFloatArray, &testPlus);

	std::cout << "\n*  Test info  *" << std::endl;
	printArray<int>(intArray, sizeIntArray);
	printArray<float>(floatArray, sizeFloatArray);

	return 0;
}
