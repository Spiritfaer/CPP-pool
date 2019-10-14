#include <fstream>
#include <sstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("TestBlank", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : Form(name, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->isSign())
		throw Form::NoSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException();
	newFile(executor);
}

void ShrubberyCreationForm::newFile(Bureaucrat const &executor) const {
	static size_t index = 0;
	std::ofstream file;
	std::stringstream fileName;

	fileName << executor.getName() << "_shrubbery";
	file.open(fileName.str(), std::ios_base::app);
	if (file.is_open())
	{
		file.close();
		fileName << "(" << index++ << ")";
		file.open(fileName.str(), std::ios_base::trunc);
	}
	file << initTree() << std::endl;
	file.close();
}
std::string ShrubberyCreationForm::initTree(void) const {
	std::string ref =
			"                     / / /\n"
			"                   /        /  /     //    /\n"
			"                /                 /         /  /\n"
			"                                /\n"
			"                               /                //\n"
			"               /          /            /              /\n"
			"               /            '/,        /               /\n"
			"               /              'b      *\n"
			"                /              '$    //                //\n"
			"               /    /           $:   /:               /\n"
			"             //      /  //      */  @):        /   / /\n"
			"                          /     :@,@):   ,/**:'   /\n"
			"              /      /,         :@@*: //**'      /   /\n"
			"                       '/o/    /:(@'/@*\"'  /\n"
			"               /  /       'bq,//:,@@*'   ,*      /  /\n"
			"                          ,p$q8,:@)'  /p*'      /\n"
			"                   /     '  / '@@Pp@@*'    /  /\n"
			"                    /  / //    Y7'.'     /  /\n"
			"                              :@):.\n"
			"                             .:@:'.\n"
			"                           .::(@:.      ";
	return ref;
}
