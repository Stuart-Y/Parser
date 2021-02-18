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
			//throw exception
		}
		return startIndex
	}

	int ParsePeriod(int startIndex) {
		if (program[startIndex]->getType() == PERIOD) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseQuestion(int startIndex) {
		if (program[startIndex]->getType() == Q_MARK) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseLeft(int startIndex) {
		if (program[startIndex]->getType() == LEFT_PAREN) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseRight(int startIndex) {
		if (program[startIndex]->getType() == RIGHT_PAREN) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseColon(int startIndex) {
		if (program[startIndex]->getType() == COLON) {
			startIndex++;
		}
		else {
			//throw error
		}
		return startIndex;
	}

	int ParseColonDash(int startIndex) {
		if (program[startIndex]->getType() == COLON_DASH) {
			startIndex++;
		}
		else {
			//throw error
		}
		return startIndex;
	}

	int ParseMultiply(int startIndex) {
		if (program[startIndex]->getType() == MULTIPLY) {
			startIndex++;
		}
		else {
			//throw error
		}
		return startIndex;
	}

	int ParseAdd(int startIndex) {
		if (program[startIndex]->getType() == ADD) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseSchemes(int startIndex) {
		if (program[startIndex]->getType() == SCHEMES) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseFacts(int startIndex) {
		if (program[startIndex]->getType() == FACTS) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseRules(int startIndex) {
		if (program[startIndex]->getType() == RULES) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseQueries(int startIndex) {
		if (program[startIndex]->getType() == QUERIES) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseID(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseString(int startIndex) {
		if (program[startIndex]->getType() == STRING){
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}

	int ParseEndfile(int startIndex) {
		if (program[startIndex]->getType() == ENDFILE) {
			startIndex++;
		}
		else {
			//throw exception
		}
		return startIndex;
	}
};

