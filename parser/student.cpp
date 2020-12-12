#include "Header.h"

using namespace std;
using namespace nlohmann;

std::string getDebt(const nlohmann::json& j) {
	if (j.is_null())
		return "null";
	else if (j.is_string())
		return j.get<std::string>();
	else {
		std::vector<std::string> v = j.get<std::vector<std::string>>();
		return std::to_string(v.size()) + " items"; // количество элементов + слово айтемс

	}
}
std::string beautify(std::string s) {
	if (s.at(0) == '"') {
		s = s.erase(0, 1);
		s = s.erase(s.length() - 1, s.length());
	}
	return s;
}
int Parse(char* arr) {
	string path = arr;
	ifstream input(path);
	if (input) {
		nlohmann::json js;
		input >> js;

		vector<student> students;
		int length = js["_meta"]["count"];
		int checkLength = 0;
		for (json::iterator i = js["items"].begin(); i != js["items"].end(); i++) {
			checkLength++;
		}
		if (checkLength == 0 || !js["items"].is_array()) {
			cout << "Items is not array!";
			throw new runtime_error("Items is not array!");
			return 1;
		}
		if (length != checkLength) {
			cout << "Length != _meta.length";
			throw new runtime_error("Length != _meta.length");
			return 1;
		}

		cout << "|" << setw(18) << left << " name" << "|" << setw(8)
			<< " group" << "|" << setw(8) << " avg" << "|" << setw(18) << " dept" << "|" << endl;
		string stemp = "|------------------|--------|--------|------------------|";
		cout << stemp << endl;
		for (int i = 0; i < length; i++) {
			student stud;
			stud.name = beautify(to_string(js["items"][i]["name"]));
			stud.group = beautify(to_string(js["items"][i]["group"]));
			stud.avg = beautify(to_string(js["items"][i]["avg"]));
			stud.debt = beautify(getDebt(js["items"][i]["debt"]));

			cout << "|" << setw(18) << left << stud.name << "|" << setw(8)
				<< stud.group << "|" << setw(8) << stud.avg << "|" << setw(18) << stud.debt << "|" << endl;

			cout << stemp << endl;
		}
	}
	else {
		cout << "unable to open json: " + path << endl;
		throw new runtime_error("unable to open json: " + path);
		return 1;
	}

}