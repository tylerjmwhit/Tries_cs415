//
// Created by Tyler on 4/7/2022.
//

#ifndef CS415PROJECT3_READER_HPP
#define CS415PROJECT3_READER_HPP

#include <string>
#include <fstream>
#include <iostream>

class Reader {
public:
	Reader(const std::string& filename);
	std::string gettext();
private:
	std::fstream _inStream;
	std::string _nameofInputFile;
};


#endif //CS415PROJECT3_READER_HPP
