#pragma once
#include <vector>

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
	vector <Parameter*> domain;
	Predicate* last;
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
		vector <Parameter*> newDomain;
		domain = newDomain;
		last = new Predicate("NULL");
	}

	void AddScheme(string id) {
		schemes.push_back(Predicate(id));
		last = &scheme;
	}

	void AddFact(string id) {
		facts.push_back(Predicate(id));
		last = &fact
	}

	void AddQuery(string id) {
		queries.push_back(Predicate(id));
		last = &query;
	}

	void AddRule(Rule* rule) {
		rules.push_back(rule);
	}

	void AddID(Token* data) {
		int i = 0;
		if (rules.size() < 1) {
			i = schemes.size() - 1;
			schemes[i]->AddContents(data);
		}
		else {
			i = rules.size() - 1;
			rules[i]->AddID(data);
		}
	}

	void AddString(Token* data) {
		int i = 0;
		i = facts.size() - 1;
		facts[i]->AddContents(data);
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
			Predicate add = new Predicate(data->inputString);
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
		out = "Schemes(" + schemes.size() +"):";
		for (unsigned int i = 0; i < to_string(schemes.size()); i++) {
			out = out + "\n" + "  " + schemes[i]->ToString();
		}
		out = out + "\n" + "Facts(" +  facts.size() +"):";
		for (unsigned int i = 0; i < to_string(facts.size()); i++)
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
		for (unsigned int i = 0; i < domain.size(); i++) {
			out = out + "\n" + domain[i]->ToString();
		}
		return out;
	}

};

