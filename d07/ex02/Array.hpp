#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T = int>
class Array
{
public:
	Array() : _size(0), _data(static_cast<T*>(operator new [] (_size * sizeof(T))) ) {};

	Array(unsigned int size) : _size(size) {
		initData();
	}

	Array(unsigned int size, T const *arr) : _size(size) {
		initData();
		dataCpyData(arr);
	}

	Array(Array const &other) : _size(other._size) {
		initData();
		dataCpyData(other._data);
	}

	~Array() {
		deleteData();
	};

	Array	&operator=(Array const &other) {
		deleteData();
		_size = other._size;
		initData();
		dataCpyData(other._data);
		return *this;
	}

	T	&operator[](unsigned int index) {
		if (index > _size)
			throw OutOfTheLimitsException();
		return _data[index];
	}

	T const	&operator[](unsigned int index) const {
		if (index >= _size)
			throw OutOfTheLimitsException();
		return _data[index];
	}

	unsigned int size() { return _size;	}
	T const	*getData() const { return _data; }
	T *getData() { return _data; }

	class OutOfTheLimitsException : public std::exception
	{
	public:
		OutOfTheLimitsException() : exception() {}
		OutOfTheLimitsException(OutOfTheLimitsException const &) : exception() {}
		~OutOfTheLimitsException() throw() {}
		const char *what() const throw() { return "This element is out of the limits"; }
	private:
		OutOfTheLimitsException &operator=(OutOfTheLimitsException const &);
	};

private:
	unsigned int	_size;
	T				*_data;

	void initData() {
		_data = static_cast<T*>(operator new [] (_size * sizeof(T)));
		for (unsigned int i = 0; i < _size; ++i) {
			new(_data + i) T();
		}
	}

	void deleteData() {
		for (unsigned int i = 0; i < _size; ++i) {
			(_data + i)->~T();
		}
		operator delete [] (_data);
	}

	void dataCpyData(T const *other) {
		for (unsigned int i = 0; i < _size; ++i) {
			_data[i] = other[i];
		}
	}
};

#endif
