#include"Functions.h"
#include"Initialise.h"

int main() {
	cout << "Version 0.03(注意,这是一个未经严格测试的版本)" << endl;
	Initialise a;
	Functions function;
	function.ShowMainMenu();
	function.SelectMode();
	function.SaveInfo();
}