#include "Inputer.h"

	void Inputer::setValue() {
		getline(std::cin, m_value);
		fflush(stdin);

		onPropertyChanged(m_value);
	}


	int Inputer::getAction() {
		try {
			return std::stoi(m_value);
		}
		catch (std::invalid_argument e) {

			return 0;
		}
	}

	std::string Inputer::m_value = "";
