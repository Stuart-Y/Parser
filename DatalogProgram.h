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
	}

	void AddScheme(Predicate* scheme) {
		schemes.push_back(scheme);
	}

	void AddFact(Predicate* fact) {
		facts.push_back(fact);
	}

	void AddQuery(Predicate* query) {
		queries.push_back(query);
	}

	void AddRule(Rule* rule) {
		rules.push_back(rule);
	}

	string ToString() {
		string out;
		out = "Schemes(" + schemes.size() +"):";
		for (unsigned int i = 0; i < schemes.size(); i++) {
			out = out + "\n" + "  " + schemes[i]->ToString();
		}
		out = out + "\n" + "Facts(" +  facts.size() +"):";
		for (unsigned int i = 0; i < facts.size(); i++)
		{
			out = out + "\n" + "  " + facts[i]->ToString() + ".";
		}
		out = out + "\n" + "Rules(" + rules.size() + "):";
		for (unsigned int i = 0; i < rules.size(); i++)
		{
			out = out + "\n" + "  " + rules[i]->ToString();
		}
		out = out + "\n" + "Queries(" + queries.size() + "):";
		for (unsigned int i = 0; i < queries.size(); i++)
		{
			out = out + "\n" + "  " + queries[i]->ToString() + "?"; 
		}
		out = out + "\n" + "Domain(" + domain.size() +"):";
		for (unsigned int i = 0; i < domain.size(); i++) {
			out = out + "\n" + domain[i]->ToString();
		}
		return out;
	}

};

