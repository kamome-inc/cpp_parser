#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "single_include/nlohmann/json.hpp"
#include <fstream>
#include <string>

struct student {
	std::string name;
	std::string group;
	std::string avg;
	std::string debt;
};

std::string getDebt(const nlohmann::json& );
std::string beautify(std::string );
int Parse(char* );