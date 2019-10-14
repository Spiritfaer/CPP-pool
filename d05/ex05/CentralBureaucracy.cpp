#include <iostream>
#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "Intern.hpp"


CentralBureaucracy::CentralBureaucracy() {
	_currentBureaucrat = 0;
	_offices = new OfficeBlock[OFFICES];
	Intern *idiot = new Intern();
	for (int i = 0; i < OFFICES; ++i) {
		_offices[i].setIntern(*idiot);
	}
}

CentralBureaucracy::~CentralBureaucracy() {
	for (int i = 0; i < OFFICES; ++i)
		fireOneOfficeBureaucrat(i);
	for (int i = 0; i < _currentBureaucrat; ++i)
		delete _humanResourcesDepartment[i];
	_currentBureaucrat = 0;
	delete _offices[0].getIntern();
	delete [] _offices;
}

bool CentralBureaucracy::hireNewBureaucrat(Bureaucrat *human) {
	if (_currentBureaucrat >= OFFICES)
		return false;
	_humanResourcesDepartment[_currentBureaucrat++] = human;
	return true;
}

void CentralBureaucracy::feed() {
	int cur = _currentBureaucrat - 1;
	for (int i = 0; i < _currentBureaucrat && cur + 1;) {

		if (!_offices[i].getSigner()) {
			_offices[i].setSigner(*_humanResourcesDepartment[cur]);
			_humanResourcesDepartment[cur--] = nullptr;
		} else if (!_offices[i].getExecutor()) {
			_offices[i].setExecutor(*_humanResourcesDepartment[cur]);
			_humanResourcesDepartment[cur--] = nullptr;
		}

		if (_offices[i].getSigner() && _offices[i].getExecutor())
			++i;
	}
	_currentBureaucrat = cur + 1;
}

bool CentralBureaucracy::fireOneOfficeBureaucrat(int i) {
	if (i < 0 || i >= OFFICES)
		return false;
	delete _offices[i].getSigner();
	delete _offices[i].getExecutor();
	return true;
}

void CentralBureaucracy::queueUp(std::string const &target) {
	if (target.empty()) {
		std::cout << "Please write something in target, give as the chance" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_QUEUE; ++i) {
		_target[i] = target;
	}
}

void CentralBureaucracy::doBureaucracy() {
	static size_t cof = 1;
	std::string forms[] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request",
		"mutant pig termination"
	};

	for (int i = 0; i < MAX_QUEUE;) {
		for (int j = 0; j < OFFICES && i < MAX_QUEUE; ++j) {
			try
			{
				_offices[j].doBureaucracy(forms[(std::rand() * ++cof) % 3], _target[i]);
				++i;
			}
			catch (OfficeBlock::InternIsAbsentException &ex) {
				std::cout << ex.what() << std::endl;
			}
			catch (OfficeBlock::SignerIsAbsentException &ex) {
				std::cout << ex.what() << std::endl;
			}
			catch (OfficeBlock::ExecutorIsAbsentException &ex) {
				std::cout << ex.what() << std::endl;
			}
			catch (OfficeBlock::UnknownBlankException &ex) {
				std::cout << ex.what() << std::endl;
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}
