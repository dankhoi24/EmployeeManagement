#include "Inputer.h"

	void Inputer::setValue() {
		getline(std::cin, m_value);
		fflush(stdin);
	}


	bool Inputer::checkValidValud() {
		return true;
	}

	int Inputer::getValue() {
		try {
			return std::stoi(m_value);
		}
		catch (std::invalid_argument e) {

		}
		return 0;
	}

	std::string Inputer::m_value = "";
