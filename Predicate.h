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
	Predicate(string id)
	{
		this->id = id;
		vector <Parameter*> newContents;
		contents = newContents;
	}

	void AddName(string id) {
		this->id = id;
	}

	void AddContents(Token* data) {
		contents.push_back(new Parameter(data));
	}

	int size() {
		return contents.size();
	}

	string getName() {
		return id;
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
		out = out + ")";
		return out;
	}
};

