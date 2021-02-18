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
	DatalogProgram out;
public:
	Parser(vector<Token*> program) {
		this->program = program;
	}

	DatalogProgram Run()
	{
		try {
			int i = 0;
			i = ParseSchemes(i);
			i = ParseColon(i);
			i = ParseScheme(i);
			i = ParseschemeList(i);
			i = ParseFacts(i);
			i = ParseColon(i);
			i = ParseFactList(i);
			i = ParseRules(i);
			i = ParseColon(i);
			i = ParseRuleList(i);
			i = ParseQueries(i);
			i = ParseColon(i);
			i = ParseQuery(i);
			i = ParseQueryList(i);
			i = ParseEndfile(i);
		}
		return out;
	}

	int ParseQueryList(int startIndex) {
		return 0;
	}

	int ParseQuery(int startIndex) {
		return 0;
	}

	int ParseRuleList(int startIndex) {
		return 0;
	}

	int ParseFactList(int startIndex) {
		return 0;
	}

	int ParseScheme(int startIndex) {
		return 0;
	}

	int ParseschemeList(int startIndex) {
		return 0;
	}

	int ParseComma(int startIndex) {
		if (program[startIndex]->getType() == COMMA) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParsePeriod(int startIndex) {
		if (program[startIndex]->getType() == PERIOD) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseQuestion(int startIndex) {
		if (program[startIndex]->getType() == Q_MARK) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseLeft(int startIndex) {
		if (program[startIndex]->getType() == LEFT_PAREN) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseRight(int startIndex) {
		if (program[startIndex]->getType() == RIGHT_PAREN) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseColon(int startIndex) {
		if (program[startIndex]->getType() == COLON) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseColonDash(int startIndex) {
		if (program[startIndex]->getType() == COLON_DASH) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseMultiply(int startIndex) {
		if (program[startIndex]->getType() == MULTIPLY) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseAdd(int startIndex) {
		if (program[startIndex]->getType() == ADD) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseSchemes(int startIndex) {
		if (program[startIndex]->getType() == SCHEMES) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseFacts(int startIndex) {
		if (program[startIndex]->getType() == FACTS) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseRules(int startIndex) {
		if (program[startIndex]->getType() == RULES) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseQueries(int startIndex) {
		if (program[startIndex]->getType() == QUERIES) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseID(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseString(int startIndex) {
		if (program[startIndex]->getType() == STRING){
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseEndfile(int startIndex) {
		if (program[startIndex]->getType() == ENDFILE) {
			startIndex++;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}
};

