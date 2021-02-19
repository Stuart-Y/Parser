#pragma once
#include <vector>
#include "Parameter.h"
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
		Predicate add = new Predicate(id)
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
	for (int i = 0; i < idList.size(); i++) {
		out = out + idlist[i]->inputString();
		if (i + 1 != idList.size()) {
			out = out + ",";
		}
	}
	out = out + ") :- ";
	for (int i = 0; i < predicateList.size(); i++)
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

