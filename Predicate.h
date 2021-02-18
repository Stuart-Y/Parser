#pragma once
#include <vector>
#include <string>

#include "Parameter.h"
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

	void AddContents(Parameter* add) {
		contents.push_back(add);
	}
};

