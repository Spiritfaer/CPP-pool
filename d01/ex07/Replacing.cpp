#include <iostream>
#include "Replacing.hpp"

Replacing::Replacing(std::string const &filename) : filename_(filename) {}

void	Replacing::setFileName(std::string const &filename) {
	filename_ = filename;
}

bool
Replacing::readFile() {
	char	buff;
	read_.open(filename_, std::ios::in);
	if (!read_) {
		std::cout << FILE_NOT_FOUND << std::endl;
		return read_;
	}
	while (read_.get(buff))
		body_ += buff;
	read_.close();
	return true;
}

bool
Replacing::writeFile() {
	write_.open(filename_);
	if (!write_) {
		std::cout << FILE_NOT_FOUND << std::endl;
		return write_;
	}

	write_ << body_;
	write_.close();
	return true;
}

bool
Replacing::replaceFile(std::string const &in, std::string const &out) {
	size_t  start_pos = body_.find(in);
	if (start_pos == std::string::npos)
		return false;
	body_.replace(start_pos, in.length(), out);
	return true;
}

Replacing::~Replacing() {
	if (read_.is_open()) read_.close();
	if (write_.is_open()) write_.close();
}

void Replacing::replace(std::string const &in, std::string const &out) {
	if (!readFile())
		return;
	while (replaceFile(in, out));
	if (!writeFile())
		return;
}
