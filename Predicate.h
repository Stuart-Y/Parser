#pragma once
#include <vector>
#include <string>

#include "Parameter.h"

using namespace std;
class Predicate
{
private:
	string id;
	vector <Parameter*> contents;
public:
	Predicate(string id){
		vector <Parameter*> newContents;
		contents = newContents;
	}

	void AddContents(Token* data) {
		Predicate create = Predicate(data);
		Parameter* add -> create;
		contents.push_back(add);
	}

	string ToString() {
		string out;
		out = id + "(";
		for (unsigned int i = 0; i < contents.size(); i++)
		{
			out = out + contents[i]->ToString();
			if (i + 1 != contents.size()) {
				out = out + ",";
			}
		}
		return out;
	}
};

