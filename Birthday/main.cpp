#include"Functions.h"
#include"Initialise.h"

int main() {
	cout << "Version 0.04" << endl;
	Initialise a;
	Functions function;
	function.ShowMainMenu();
	function.SelectMode();
	function.SaveInfo();
	return 0;
}