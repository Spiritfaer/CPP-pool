#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm(const std::string &name);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;

private:
	RobotomyRequestForm &operator=(RobotomyRequestForm const &);
};


#endif
