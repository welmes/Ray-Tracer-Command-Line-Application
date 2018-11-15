#include "TokenReader.h"
#include "RayTracer.h"
using namespace std;

TokenReader tr;
RayTracer rt;
string inp_f_name = "";
string out_f_name = "";
string dep_f_name = "";
bool verbose = false;

bool parseArguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	if (!parseArguments(argc, argv)) return 1;
	if (inp_f_name == "") return 0;
	if (!tr.openFile(inp_f_name)) return 1;
	if (!tr.parseFile()) return 1;
	if (verbose) cout << endl << "Scene parsed: no errors" << endl << endl;
	rt.initializeRays();
	rt.traceRays();
	return 0;
}

bool parseArguments(int argc, char *argv[])
{
	cout << "Parsing arguments:" << endl
		 << "argc = " << argc << endl;
	for (int i = 1; i < argc; i++)
	{
		cout << "argv[" << i << "] = " << argv[i] << endl;
		if (string(argv[i]) == "-h")
		{
			// Print help menu
			cout << "Help menu" << endl;
		}
		else if (string(argv[i]) == "-v")
		{
			// Enable verbose mode
			verbose = true;
			tr.setVerbose(verbose);
			cout << "Verbose mode enabled" << endl;
		}
		else if (string(argv[i]) == "-i" && argc > i + 1)
		{
			// Set input file
			inp_f_name = argv[i + 1];
			cout << "inp_f_name = " << inp_f_name << endl;
			i++;
		}
		else if (string(argv[i]) == "-o" && argc > i + 1)
		{
			// Set output file
			out_f_name = argv[i + 1];
			cout << "out_f_name = " << out_f_name << endl;
			i++;
		}
		else if (string(argv[i]) == "-d" && argc > i + 1)
		{
			// Set output depth file
			dep_f_name = argv[i + 1];
			cout << "dep_f_name = " << dep_f_name << endl;
			i++;
		}
		else
		{
			// Invalid command
			cout << "Invalid command" << endl;
			return false;
		}
	}
	cout << endl;
	return true;
}