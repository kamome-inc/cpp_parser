#include "Header.h"

using namespace std;
int main(int n, char* arr[]) {
	if (n != 1) {
		Parse(arr[1]);
	}
	else {
		cout << "No arguments found!" << endl;
		throw new runtime_error("No arguments found!");
		return 1;
	}
}
