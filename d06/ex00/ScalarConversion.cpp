#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include "ScalarConversion.hpp"

/*******************************************************/
/***         Constructor and Destructor              ***/
/*******************************************************/

ScalarConversion::ScalarConversion() : _ref(""), _ch(0) {}
ScalarConversion::ScalarConversion(std::string const &ref) : _ref(ref), _ch(0){
	if(isDouble()) {
		initDouble();
	} else if (isFloat()) {
		initFloat();
	} else if (isInt()) {
		initInteger();
	} else if (isChar()) {
		initChar();
	} else
		_err = true;
}
ScalarConversion::~ScalarConversion() {}

/*******************************************************/
/***               override operator                 ***/
/*******************************************************/

ScalarConversion::operator char() {
	if (!isChar() || isFuck())
		throw ScalarConversion::NoConversionExceptions();
	if (!isprint(_ref[0]))
		throw ScalarConversion::NoDisplayableExceptions();
	return _ref[0];
}

ScalarConversion::operator int() {
	if (!isInt() || isFuck())
		throw ScalarConversion::NoConversionExceptions();
	return std::atoi(_ref.c_str());
}

ScalarConversion::operator float() {
	if (!isFloat())
		throw ScalarConversion::NoConversionExceptions();
	return std::atof(_ref.c_str());
}

ScalarConversion::operator double() {
	if (!isDouble())
		throw ScalarConversion::NoConversionExceptions();
	errno = 0;
	const char *str = _ref.c_str();
	char *end;
	double dd = std::strtod(str, &end);
	return dd;
}

/*******************************************************/
/***                   infoFoo()                     ***/
/*******************************************************/

void ScalarConversion::infoChar() {
	std::cout << "char: ";
	try {
		if (isFuck() || _i > 127 || _i < 0 || _err)
			throw ScalarConversion::NoConversionExceptions();
		if (isprint(_ch))
			std::cout << "\'" << _ch << "\'" << std::endl;
		else
			throw ScalarConversion::NoDisplayableExceptions();
	} catch(std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}

void ScalarConversion::infoInteger() {
	std::cout << "int: ";
	try {
		if (_err || _fl > INT_MAX || _fl < INT_MIN || isFuck())
			throw ScalarConversion::NoConversionExceptions();
		std::cout << _i << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}

void ScalarConversion::infoFloat() {
	std::cout << std::fixed;
	std::cout.precision(1);

	std::cout << "float: ";
	try {
		if (_err)
			throw ScalarConversion::NoConversionExceptions();
		std::cout << _fl << "f" << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}

void ScalarConversion::infoDouble() {
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "double: ";
	try {
		if (_err)
			throw ScalarConversion::NoConversionExceptions();
		std::cout << _db << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}

/*******************************************************/
/***                   IS_FOO()                      ***/
/*******************************************************/

bool ScalarConversion::isChar() {
	return _ref.length() == 1 && !isdigit(_ref.c_str()[0]);
}

bool ScalarConversion::isInt() {
	errno = 0;
	const char *str = _ref.c_str();
	char *end;
	long l;
	l = std::strtol(str, &end, 10);
	if (errno || l > INT_MAX || l < INT_MIN || *str == '\0' || *end != '\0')
		return false;
	return true;
}

bool ScalarConversion::isFloat() {
	errno = 0;

	float _f = std::atof(_ref.c_str());
	if (errno || *_ref.c_str() == '\0' || _ref.c_str()[_ref.length() - 1] != 'f')
		return false;
	return true;
}


bool ScalarConversion::isDouble() {
	errno = 0;
	const char *str = _ref.c_str();
	char *end;
	double dd = std::strtod(str, &end);
	if (errno || *str == '\0' || *end != '\0' || end == str)
		return false;
	for (int i = 0; i < _ref.length(); ++i) {
		if (str[i] == '.')
			return true;
	}
	if (isFuck())
		return true;
	return false;
}

bool ScalarConversion::isFuck() {
	return _ref == "NaN" || _ref == "nan" || _ref == "-inf" || _ref == "inf" || _ref == "nanf" || _ref == "NaNf";
}

/*******************************************************/
/***                     INIT                        ***/
/*******************************************************/

void ScalarConversion::initDouble() {
	_db = static_cast<double>(*this);
	_fl = static_cast<float>(_db);
	_ch = static_cast<char>(_db);
	_i = static_cast<int>(_db);
}

void ScalarConversion::initChar() {
	_ch = static_cast<char>(*this);
	_i = static_cast<int>(_ch);
	_fl = static_cast<float>(_ch);
	_db = static_cast<double>(_ch);
}

void ScalarConversion::initFloat() {
	_fl = static_cast<float>(*this);
	_db = static_cast<double>(_fl);
	_i = static_cast<int>(_fl);
	_ch = static_cast<char>(_fl);
}

void ScalarConversion::initInteger() {
	_i = static_cast<int>(*this);
	_ch = static_cast<char>(_i);
	_fl = static_cast<float>(_i);
	_db = static_cast<double>(_i);
}
/*******************************************************/
/***                  Exceptions                     ***/
/*******************************************************/

ScalarConversion::NoConversionExceptions::NoConversionExceptions() :exception() {}
ScalarConversion::NoConversionExceptions::NoConversionExceptions(NoConversionExceptions const &) :exception() {}
ScalarConversion::NoConversionExceptions::~NoConversionExceptions() _NOEXCEPT {}
const char* ScalarConversion::NoConversionExceptions::what() const _NOEXCEPT {
	return "impossible";
}

ScalarConversion::NoDisplayableExceptions::NoDisplayableExceptions() :exception() {}
ScalarConversion::NoDisplayableExceptions::NoDisplayableExceptions(NoDisplayableExceptions const &) :exception() {}
ScalarConversion::NoDisplayableExceptions::~NoDisplayableExceptions() _NOEXCEPT {}
const char* ScalarConversion::NoDisplayableExceptions::what() const _NOEXCEPT {
	return "Non displayable";
}
