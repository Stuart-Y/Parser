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
		out = DatalogProgram();
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
		catch(Token* error){
			throw error;
		}
		return out;
	}

	int ParseExpression(int startIndex) {
		if (program[startIndex]->getType() == LEFT_PAREN) {
			startIndex = ParseLeft(startIndex);
			startIndex = ParseParameter(startIndex);
			startIndex = ParseOperator(startIndex);
			startIndex = ParseParameter(startIndex);
			startIndex = ParseRight(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseOperator(int startIndex) {
		if (program[startIndex]->getType() == ADD) {
			startIndex = ParseAdd(startIndex);
		}
		else if (program[startIndex]->getType() == MULTIPLY) {
			startIndex = ParseMultiply(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseQueryList(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseQuery(startIndex);
			startIndex = ParseQueryList(startIndex);
		}
		else if(program[startIndex]->getType() == ENDFILE){
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseQuery(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParsePredicate(startIndex);
			startIndex = ParseQuestion(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseRuleList(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseRule(startIndex);
			startIndex = ParseRuleList(startIndex);
		}
		else if (program[startIndex]->getType() == QUERIES) {
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseRule(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseHeadPredicate(startIndex);
			startIndex = ParseColonDash(startIndex);
			startIndex = ParsePredicate(startIndex);
			startIndex = ParsePredicateList(startIndex);
			startIndex = ParsePeriod(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseHeadPredicate(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseID(startIndex);
			startIndex = ParseLeft(startIndex);
			startIndex = ParseID(startIndex);
			startIndex = ParseIDList(startIndex);
			startIndex = ParseRight(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParsePredicate(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseID(startIndex);
			startIndex = ParseLeft(startIndex);
			startIndex = ParseParameter(startIndex);
			startIndex = ParseParameterList(startIndex);
			startIndex = ParseRight(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParsePredicateList(int startIndex) {
		if (program[startIndex]->getType() == COMMA) {
			startIndex = ParseComma(startIndex);
			startIndex = ParsePredicate(startIndex);
			startIndex = ParsePredicateList(startIndex);
		}
		else if (program[startIndex]->getType() == PERIOD) {
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseParameter(int startIndex) {
		if (program[startIndex]->getType() == STRING) {
			startIndex = ParseString(startIndex);
		}
		else if (program[startIndex]->getType() == ID) {
			startIndex = ParseID(startIndex);
		}
		else if (program[startIndex]->getType() == LEFT_PAREN) {
			startIndex = ParseExpression(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseParameterList(int startIndex) {
		if (program[startIndex]->getType() == COMMA) {
			startIndex = ParseComma(startIndex);
			startIndex = ParseParameter(startIndex);
			startIndex = ParseParameterList(startIndex);
		}
		else if (program[startIndex]->getType() == RIGHT_PAREN) {
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseFactList(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseFact(startIndex);
			startIndex = ParseFactList(startIndex);
		}
		else if (program[startIndex]->getType() == PERIOD) {
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseFact(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseID(startIndex);
			startIndex = ParseLeft(startIndex);
			startIndex = ParseString(startIndex);
			startIndex = ParseStringList(startIndex);
			startIndex = ParseRight(startIndex);
			startIndex = ParsePeriod(startIndex);
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseStringList(int startIndex) {
		if (program[startIndex]->getType() == COMMA)
		{
			startIndex = ParseComma(startIndex);
			startIndex = ParseString(startIndex);
			startIndex = ParseStringList(startIndex);
		}
		else if (program[startIndex]->getType() == RIGHT_PAREN) {
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseScheme(int startIndex) {
		startIndex = ParseID(startIndex);
		startIndex = ParseLeft(startIndex);
		startIndex = ParseID(startIndex);
		startIndex = ParseIDList(startIndex);
		startIndex = ParseRight(startIndex);
		return startIndex;
	}

	int ParseschemeList(int startIndex) {
		if (program[startIndex]->getType() == ID) {
			startIndex = ParseScheme(startIndex);
			startIndex = ParseschemeList(startIndex);
		}
		else if (program[startIndex]->getType() == RIGHT_PAREN) {
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
	}

	int ParseIDList(int startIndex) {
		if (program[startIndex]->getType() == COMMA) {
			startIndex = ParseComma(startIndex);
			startIndex = ParseID(startIndex);
			startIndex = ParseIDList(startIndex);
		}
		else if (program[startIndex]->getType() == RIGHT_PAREN) {
			return startIndex;
		}
		else {
			throw program[startIndex];
		}
		return startIndex;
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

