#ifndef CENTRAL_BUREAUCRACY_HPP
#define CENTRAL_BUREAUCRACY_HPP

#define OFFICES 20
#define MAX_QUEUE 21
#include "Bureaucrat.hpp"

class OfficeBlock;

class CentralBureaucracy {
public:
	OfficeBlock *_offices;
	Bureaucrat	*_humanResourcesDepartment[OFFICES];

	CentralBureaucracy();
	~CentralBureaucracy();

	void queueUp(std::string const &);
	void doBureaucracy();

	void feed();
	bool hireNewBureaucrat(Bureaucrat *human);

private:
	int			_currentBureaucrat;
	std::string	_target[MAX_QUEUE];

	CentralBureaucracy(CentralBureaucracy const &);
	CentralBureaucracy &operator=(CentralBureaucracy const &);

	bool fireOneOfficeBureaucrat(int i);
};

#endif
