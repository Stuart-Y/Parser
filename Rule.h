#pragma once
#include <vector>
#include "Parameter.h"
#include "Predicate.h"
class Rule
{
private:
	string id;
	vector <Token*> idList;
	vector <Predicate*> predicateList;
public:
	Rule(string id) {
		this->id = id;
		vector <Token*> newIDList;
		vector <Predicate*> newPredicateList;
		idList = newIDList;
		predicateList = newPredicateList;
	}

	void AddID(Token* add) {
		idList.push_back(add);
	}

	void AddPredicate(string id) {
		Predicate create = Predicate(id);
		Predicate* add -> create;
		predicateList.push_back(add);
	}

	void  AddContent(Token* add)
	{
		int i = 0;
		i = predicateList.size() - 1;
		predicateList[i]->AddContents(add);
	}

	string ToString(){
		string out;
	out = id + "(";
	for (unsigned int i = 0; i < idList.size(); i++) {
		out = out + idList[i]->inputString();
		if (i + 1 != idList.size()) {
			out = out + ",";
		}
	}
	out = out + ") :- ";
	for (unsigned int i = 0; i < predicateList.size(); i++)
	{
		out = out + predicateList[i]->ToString();
		if (i + 1 != predicateList.size())
		{
			out = out + ",";
		}
		else {
			out = out + ".";
		}
	}
	return out;
	}
};

