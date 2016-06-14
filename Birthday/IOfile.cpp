#include"IOfile.h"

IOfile::IOfile(int a) {
	get_iofile_name();
	open_iofile();
}

IOfile::IOfile(string ifn, string ofn):ifname(ifn),ofname(ofn) {
	ifs.open(ifname);
	if (!ifs) {
		cerr << "Error 2: Input file open error: " << ifname << endl;
		getchar();
		exit(2);
	}
	ofs.open(ofname);
	if (!ofs) {
		cerr << "Error 3: Output file open error: " << ofname << endl;
		getchar();
		exit(3);
	}
}

void IOfile::get_iofile_name() {
	cout << "Enter the input file's name." << endl;
	cin >> ifname;
	cout << "Enter the output file's name." << endl;
	cin >> ofname;
}
void IOfile::open_iofile() {
	ifs.open(ifname);
	if (!ifs) {
		cerr << "Error 2: Input file open error: " << ifname << endl;
		exit(2);
	}
	ofs.open(ofname);
	if (!ofs) {
		cerr << "Error 3: Output file open error: " << ofname << endl;
		exit(3);
	}
}