#pragma once
#include <vector>
#include "Parameter.h"
#include "Predicate.h"
class Rule
{
private:
	Predicate headPredicate;
	vector <Predicate*> predicateList;
public:
	Rule(string id) {
		headPredicate.AddName(id);
		vector <Predicate*> newPredicateList;
		predicateList = newPredicateList;
	}

	void AddHeadID(string id) {
		headPredicate.AddName(id);
	}

	void AddHeadContent(Token* add) {
		headPredicate.AddContents(add);
	}

	void AddPredicate(string id) {
		predicateList.push_back(new Predicate(id));
	}

	void AddID(string id) {
		predicateList[predicateList.size() - 1]->AddName();
	}

	void  AddContent(Token* add)
	{
		predicateList[predicateList.size() -1 ]->AddContents(add);
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

	int getHeadSize() {
		return headPredicate.size();
	}

	string getHeadName() {
		return headPredicate.getName();
	}

	int getListSize() {
		return predicateList.size();
	}

	int getPredicateSize(int i) {
		return predicateList[i]->size();
	}

	bool needName() {
		if (predicateList[predicateList.size() - 1]->getName() == "NULL")
		{
			return true;
		}
		return false;
	}
};

