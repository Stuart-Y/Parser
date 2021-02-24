#pragma once
#include <vector>
#include <string>
#include <set>

#include "Token.h"
#include "Predicate.h"
#include "Rule.h"

class DatalogProgram
{
private:
	vector <Predicate*> schemes;
	vector <Predicate*> facts;
	vector <Predicate*> queries;
	vector <Rule*> rules;
	set <string> domain;

public:
	DatalogProgram(){
		vector <Predicate*> newSchemes;
		schemes = newSchemes;
		vector <Predicate*> newFacts;
		facts = newFacts;
		vector <Predicate*> newQueries;
		queries = newQueries;
		vector <Rule*> newRules;
		rules = newRules;
		set<string> newDomain;
		domain = newDomain;
	}

	void AddScheme(string id) {
		schemes.push_back(new Predicate(id));
	}

	void AddFact(string id) {
		facts.push_back(new Predicate(id));
	}

	void AddQuery(string id) {
		queries.push_back(new Predicate(id));
	}

	void AddRule(string id) {
		rules.push_back(new Rule(id));
	}

	void AddID(Token* data) {
		if (schemes[schemes.size() - 1]->getName() == "NULL" && queries.size() == 0)
		{
			schemes[schemes.size() - 1]->AddName(data->inputString());
		}
		else if (facts.size() < 1 && queries.size() == 0)
		{
			schemes[schemes.size() - 1]->AddContents(data);
		}
		else if (facts[facts.size() - 1]->getName() == "NULL" && queries.size() ==0)
		{
			facts[facts.size() - 1]->AddName(data->inputString());
		}
		else if (rules[rules.size() - 1]->getHeadName() == "NULL" && queries.size() == 0)
		{
			rules[rules.size() - 1]->AddHeadID(data->inputString());
		}
		else if (rules[rules.size() - 1]->getListSize() < 1 && queries.size() == 0)
		{
			rules[rules.size() - 1]->AddHeadContent(data);
		}
		else if (rules[rules.size() - 1]->needName() && queries.size() == 0)
		{
			rules[rules.size() - 1]->AddID(data->inputString());
		}
		else if (queries.size() == 0 )
		{
			rules[rules.size() - 1]->AddContent(data);
		}
		else if (queries[queries.size() - 1]->getName() == "NULL")
		{
			queries[queries.size() - 1]->AddName(data->inputString());
		}
		else if (queries.size() > 0) {
			queries[queries.size() - 1]->AddContents(data);
		}
		else {
			cout << "ERROR: Improper ID assignment" << "\n";
		}
	}

	void AddString(Token* data) {
		if (rules.size() < 1) 
		{
			bool addTo = true;
			facts[facts.size() - 1]->AddContents(data);
			set <string>::iterator at = domain.begin();
			string check;
			for (unsigned int i = 0; i < domain.size(); i++)
			{
				check = *at;
				if (check.compare(data->inputString()) == 0) {
					addTo = false;
				}
				at++;
			}
			if (addTo)
			{
				domain.insert(data->inputString());
			}
		}
		else if (queries.size() < 1)
		{
			rules[rules.size() - 1]->AddContent(data);
		}
		else {
			queries[queries.size() - 1]->AddContents(data);
		}
	}

	void AddPredicate(Token* data) {
		int i = 0;
		if (queries.size() < 1) {
			i = rules.size() - 1;
			rules[i]->AddPredicate(data->inputString());
		}
		else
		{
			i = queries.size() - 1;
			queries[i]->AddName(data->inputString());
		}
	}

	void AddParameter(Token* data) {
		int i = 0;
		if (queries.size() < 1) {
			i = rules.size() - 1;
			rules[i]->AddContent(data);
		}
		else {
			i = queries.size() - 1;
			queries[i]->AddContents(data);
		}
	}

	

	string ToString() {
		string out;
		out = "Schemes(" + to_string(schemes.size()) +"):";
		for (unsigned int i = 0; i < schemes.size(); i++) {
			out = out + "\n" + "  " + schemes[i]->ToString();
		}
		out = out + "\n" + "Facts(" + to_string(facts.size()) +"):";
		for (unsigned int i = 0; i < facts.size(); i++)
		{
			out = out + "\n" + "  " + facts[i]->ToString() + ".";
		}
		out = out + "\n" + "Rules(" + to_string(rules.size()) + "):";
		for (unsigned int i = 0; i < rules.size(); i++)
		{
			out = out + "\n" + "  " + rules[i]->ToString();
		}
		out = out + "\n" + "Queries(" + to_string(queries.size()) + "):";
		for (unsigned int i = 0; i < queries.size(); i++)
		{
			out = out + "\n" + "  " + queries[i]->ToString() + "?"; 
		}
		out = out + "\n" + "Domain(" + to_string(domain.size()) +"):";
		set <string>::iterator at = domain.begin();
		for (unsigned int i = 0; i < domain.size(); i++) {
			out = out + "\n" + *at;
			at++;
		}
		out = out + "\n";
		return out;
	}

};

