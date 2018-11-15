#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Scene.h"
using namespace std;

class TokenReader
{
public:
	int more;
	Scene scene;

	TokenReader() { reset(); verbose = false; }
	void reset() { next_token = ""; }
	void setVerbose(bool v) { verbose = v; }
	bool openFile(string fname);
	bool parseFile();

private:
	ifstream f_stream;
	string next_token;
	bool verbose;
	
	void printError(string err, string exp = "");
	bool parseNextToken(string exp);
	string peekNextToken();
	Point3 parseVec3f();
	bool parseCamera();
	bool parseViewPlane();
	bool parseBackground();
	bool parseMaterials();
	bool parsePhongMaterial(int id);
	bool parseGroup();
	int parseObjectMaterialIndex();
	bool parseSphere(int mi);
};