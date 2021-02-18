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

};

