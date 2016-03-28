#include "tinyxml.h"
#include <iostream>
#include <string>

using namespace std;

enum SuccessEnum {FAILURE,SUCCESS};

SuccessEnum loadXML()
{
	TiXmlDocument doc;
	if (!doc.LoadFile("config.xml"))
	{
		cerr << doc.ErrorDesc();
		return FAILURE;
	}
	for (TiXmlElement* root = doc.FirstChildElement(); root != NULL; root = doc.NextSiblingElement())
	{
		if (root != NULL)
		{
			string root_name = root->Value();
			if (root_name == "conf_db")
			{
				TiXmlElement* elem = root->FirstChildElement("user");
				string user= elem->GetText();
				cout << user << endl;
			}
		}
	}
	doc.Clear();
	return SUCCESS;
}

int main()
{
	if (loadXML() == FAILURE)
		return 1;
	return 0;
}