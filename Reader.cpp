//
// Created by Tyler on 4/7/2022.
//

#include "Reader.hpp"

Reader::Reader(const std::string& filename) {
	_nameofInputFile = filename;
	_inStream.open(_nameofInputFile,std::ios::in);
	if (!_inStream.is_open()) {
		std::cout << "Unable to open " << filename << ". Terminating...";
		exit(1);
	}
}

std::string Reader::gettext() {
	char c;
	std::string tempword;
	while(_inStream.get(c) && !_inStream.eof()){
		if (!isalpha(c)){
			if(tempword.back() != ' ')
				tempword += ' ';
		}
		else {
			tempword += tolower(c);
		}
	}
	return tempword;
}
