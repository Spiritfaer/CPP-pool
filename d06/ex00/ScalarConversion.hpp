#ifndef SCALAR_CONVERSION_HPP
#define SCALAR_CONVERSION_HPP


#include <string>

class ScalarConversion {
public:
    ScalarConversion();
	ScalarConversion(std::string const &ref);
    ~ScalarConversion();

    operator char();
    operator int();
    operator float();
    operator double();

    void infoChar();
    void infoInteger();
    void infoFloat();
    void infoDouble();


    bool isChar();
    bool isInt();
    bool isFloat();
    bool isDouble();
    bool isFuck();

    void initChar();
    void initInteger();
    void initFloat();
    void initDouble();
	class NoConversionExceptions : public std::exception
	{
	public:
		NoConversionExceptions();
		NoConversionExceptions(NoConversionExceptions const &);
		~NoConversionExceptions() _NOEXCEPT;
		const char *what() const _NOEXCEPT;
	private:
		NoConversionExceptions &operator=(NoConversionExceptions const &);
	};

	class NoDisplayableExceptions : public std::exception
	{
	public:
		NoDisplayableExceptions();
		NoDisplayableExceptions(NoDisplayableExceptions const &);
		~NoDisplayableExceptions() _NOEXCEPT;
		const char *what() const _NOEXCEPT;
	private:
		NoDisplayableExceptions &operator=(NoDisplayableExceptions const &);
	};

    std::string     _ref;
    char 			_ch;
    int 			_i;
    float			_fl;
    double			_db;
    bool			_err;
private:
    ScalarConversion(ScalarConversion const &);
    ScalarConversion& operator=(ScalarConversion const &);

};


#endif
