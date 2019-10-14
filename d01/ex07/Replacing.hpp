#ifndef REPLACING_H
#define REPLACING_H

#define FILE_NOT_FOUND "SORRY BUT THE FILE WHICH YOU SPECIFIED \
DOES NOT EXIST OR BE IN ANOTHER PLACE"

#include <string>
#include <fstream>

class Replacing {
public:
	Replacing(std::string const &filename);
	void	setFileName(std::string const &filename);

	std::string &makeBody();
	void	replace(std::string const &in, std::string const &out);

	~Replacing();

private:
	std::string		filename_;
	std::ifstream	read_;
	std::ofstream	write_;
	std::string		body_;

	bool	readFile();
	bool	writeFile();
	bool	replaceFile(std::string const &in, std::string const &out);
};


#endif
