#pragma once
#include <vector>
#include <set>

#include"Token.h"
#include"DatalogProgram.h"

using namespace std;
class Parser
{
private:
	vector<Token*> program;
public:
	Parser(vector<Token*> program) {
		this->program = program;
	}

	DatalogProgram Run()
	{
		ParseSchemes();
		ParseColon();
		ParseScheme();
		ParseschemeList();
		ParseFacts();
		ParseColon();
		ParseFactList();
		ParseRules();
		ParseColon();
		ParseRuleList();
		ParseQueries();
		ParseColon();
		ParseQuery();
		ParseQueryList();
		ParseEndfile();
	}

	void ParseQueryList() {

	}

	void ParseQuery() {

	}

	void ParseRuleList() {

	}

	void ParseFactList() {

	}

	void ParseScheme() {

	}

	void ParseschemeList() {

	}

	void ParseComma() {

	}

	void ParsePeriod() {

	}

	void ParseQuestion() {

	}

	void ParseLeft() {

	}

	void ParseRight() {

	}

	void ParseColon() {

	}

	void ParseColonDash() {

	}

	void ParseMultiply() {

	}

	void ParseAdd() {

	}

	void ParseSchemes() {

	}

	void ParseFacts() {

	}

	void ParseRules() {

	}

	void ParseQueries() {

	}

	void ParseID() {

	}

	void ParseString() {

	}

	void ParseComment() {

	}

	void ParseEndfile() {

	}
};

