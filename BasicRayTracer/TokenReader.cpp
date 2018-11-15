#include "TokenReader.h"
#include "Point3.h"
#include "Camera.h"
#include "Light.h"
#include "ViewPlane.h"
#include "Background.h"
#include "PhongMaterial.h"
#include "Sphere.h"

void TokenReader::printError(string err, string exp)
{
	cout << "\nError: Bad " << err;
	if (0 < exp.length())
		cout << ", saw " << exp;
	cout << endl;
}

bool TokenReader::openFile(string f_name)
{
	if (verbose) cout << "Opening file: f_name = " << f_name << endl;
	f_stream.open(f_name.c_str());
	if (!f_stream)
	{
		// Error opening file
		printError("file open", f_name);
		more = false;
		return false;
	}
	more = true;
	if (verbose) cout << "File opened: more = " << more << endl;
	return true;
}

bool TokenReader::parseFile()
{
	if (more && f_stream)
	{
		if (verbose) cout << "Parsing file..." << endl;
		reset();
		if (!parseCamera() ||
			!parseViewPlane() ||
			!parseBackground() ||
			!parseMaterials() ||
			!parseGroup())
		{
			// Error while parsing file
			f_stream.close();
			printError("file parsing");
			return false;
		}
		f_stream.close();
		if (verbose) cout << "\nFile parsed: closing file" << endl;
		return true;
	}
	else if (more)
		// Can't parse file
		printError("file parsing");
	return false;
}

bool TokenReader::parseNextToken(string exp)
{
	string token = next_token;
	if (token == "")
		f_stream >> token;
	else
		next_token = "";
	//if (verbose) cout << "Parsing token: \"" << token << "\" against: \"" << exp << "\"" << endl;
	if (token != exp)
		printError(exp, token);
	return (token == exp);
}

string TokenReader::peekNextToken()
{
	string token;
	f_stream >> token;
	next_token = token;
	//if (verbose) cout << "Peeked at " << token << endl;
	return token;
}

Point3 TokenReader::parseVec3f()
{
	Point3 p;
	f_stream >> p.x >> p.y >> p.z;
	return p;
}

bool TokenReader::parseCamera()
{
	if (verbose) cout << "\nParsing camera..." << endl;
	Camera c;
	Light *l = new Light();
	l->type = LIGHT_PHONG_POINT;
	l->diffuse.x = 1.0;
	l->diffuse.y = 1.0;
	l->diffuse.z = 1.0;
	if (!parseNextToken("OrthographicCamera")) return false;
	c.type = CAMERA_ORTHOGRAPHIC;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("center")) return false;
	c.center = parseVec3f();
	l->position = c.center;
	if (!parseNextToken("direction")) return false;
	c.direction = parseVec3f();
	if (!parseNextToken("up")) return false;
	c.up = parseVec3f();
	if (!parseNextToken("}")) return false;
	if (verbose) c.Show();
	if (verbose) l->Show();
	scene.camera = c;
	scene.lights.push_back(l);
	return true;
}

bool TokenReader::parseViewPlane()
{
	if (verbose) cout << "\nParsing viewplane..." << endl;
	ViewPlane vp;
	if (!parseNextToken("ViewPlane")) return false;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("width")) return false;
	f_stream >> vp.width;
	if (!parseNextToken("height")) return false;
	f_stream >> vp.height;
	if (!parseNextToken("pixelsize")) return false;
	f_stream >> vp.pixelSize;
	if (!parseNextToken("}")) return false;
	if (verbose) vp.Show();
	scene.view_plane = vp;
	return true;
}

bool TokenReader::parseBackground()
{
	if (verbose) cout << "\nParsing background..." << endl;
	Background bg;
	if (!parseNextToken("Background")) return false;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("color")) return false;
	Point3 p = parseVec3f();
	bg.color.x = p.x;
	bg.color.y = p.y;
	bg.color.z = p.z;
	if (!parseNextToken("}")) return false;
	if (verbose) bg.Show();
	scene.background = bg;
	return true;
}

bool TokenReader::parseMaterials()
{
	if (verbose) cout << "\nParsing materials..." << endl;
	int num_materials = 0;
	if (!parseNextToken("Materials")) return false;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("numMaterials")) return false;
	f_stream >> num_materials;
	if (verbose) cout << "num_materials = " << num_materials << endl;
	for (int id = 0; id < num_materials; id++)
		if (!parsePhongMaterial(id)) return false;
	if (!parseNextToken("}")) return false;
	return true;
}

bool TokenReader::parsePhongMaterial(int id)
{
	PhongMaterial *pm = new PhongMaterial();
	pm->id = id;
	pm->type = MATERIAL_PHONG;
	if (!parseNextToken("PhongMaterial")) return false;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("diffuseColor")) return false;
	Point3 p = parseVec3f();
	pm->diffuse.x = p.x;
	pm->diffuse.y = p.y;
	pm->diffuse.z = p.z;
	if (!parseNextToken("}")) return false;
	if (verbose) pm->Show();
	scene.materials.push_back(pm);
	return true;
}

bool TokenReader::parseGroup()
{
	if (verbose) cout << "\nParsing group..." << endl;
	int num_objects = 0;
	if (!parseNextToken("Group")) return false;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("numObjects")) return false;
	f_stream >> num_objects;
	if (verbose) cout << "numObjects = " << num_objects << endl;
	bool more_objects = true;
	int material_index;
	do
	{
		string token = peekNextToken();
		if (token == "MaterialIndex")
		{
			material_index = parseObjectMaterialIndex();
			if (material_index == -1) return false;
		}
		else if (token == "Sphere")
		{
			if (!parseSphere(material_index)) return false;
		}
		else if (token == "}")
		{
			more_objects = false;
		}
		else
		{
			printError("MaterialIndex, Sphere, or }", token);
			return false;
		}
	} while (more_objects);
	return true;
}

int TokenReader::parseObjectMaterialIndex()
{
	if (!parseNextToken("MaterialIndex")) return false;
	int i = -1;
	f_stream >> i;
	if (verbose) cout << "\nMaterialIndex = " << i << endl;
	return i;
}

bool TokenReader::parseSphere(int mi)
{
	if (verbose) cout << "Parsing sphere..." << endl;
	Sphere *s = new Sphere();
	s->material_index = mi;
	if (!parseNextToken("Sphere")) return false;
	if (!parseNextToken("{")) return false;
	if (!parseNextToken("center")) return false;
	s->center = parseVec3f();
	if (!parseNextToken("radius")) return false;
	f_stream >> s->radius;
	if (!parseNextToken("}")) return false;
	if (verbose) s->Show();
	scene.objects.push_back(s);
	return true;
}