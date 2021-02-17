#pragma once
#include <string>
#include <vector>
#include <cctype>
#include "Token.h"
#include "Automaton.h"
#include "MatcherAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "IDAutomaton.h"
#include "UndefinedAutomaton.h"
#include "EndFileAutomaton.h"
using namespace std;

class Lexer
{
private:
	vector<Token*> tokens;
	vector<Automaton*> automata;

public:
	Lexer()
	{
		vector<Token*> token;
		tokens = token;
		vector<Automaton*> automatons;
		automata = automatons;
		automata.push_back(new MatcherAutomaton(COMMA));
		automata.push_back(new MatcherAutomaton(PERIOD));
		automata.push_back(new MatcherAutomaton(Q_MARK));
		automata.push_back(new MatcherAutomaton(LEFT_PAREN));
		automata.push_back(new MatcherAutomaton(RIGHT_PAREN));
		automata.push_back(new MatcherAutomaton(ADD));
		automata.push_back(new MatcherAutomaton(MULTIPLY));
		automata.push_back(new MatcherAutomaton(COLON));
		automata.push_back(new MatcherAutomaton(COLON_DASH));
		automata.push_back(new MatcherAutomaton(SCHEMES));
		automata.push_back(new MatcherAutomaton(FACTS));
		automata.push_back(new MatcherAutomaton(RULES));
		automata.push_back(new MatcherAutomaton(QUERIES));
		automata.push_back(new StringAutomaton(STRING));
		automata.push_back(new CommentAutomaton(COMMENT));
		automata.push_back(new IDAutomaton(ID));
		automata.push_back(new UndefinedAutomaton(UNDEFINED));
	}

	vector <Token*> Run(string input)
	{
		int maxRead;
		int check;
		int lineNumber = 1;
		Automaton* maxAutomaton = automata[0];
		Automaton* endfile = new EndFileAutomaton(ENDFILE);
		Token* newToken;
		while (input.empty() != true && input.length() > 1)
		{
			maxRead = 0;
			while (isspace(input[0]))
			{
				if (input[0] == '\n')
				{
					lineNumber++;
				}
				input = input.substr(1, input.length());
			}
			for (unsigned int i = 0; i < automata.size(); i++)
			{	
				check = automata[i]->Start(input, lineNumber);
				if (check > maxRead)
				{
					maxRead = check;
					maxAutomaton = automata[i];
				}
			}
			newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
			tokens.push_back(newToken);
			lineNumber = lineNumber + maxAutomaton->NewLinesRead();
			input.erase(0, maxRead);
			while (isspace(input[0]))
			{
				if (input[0] == '\n')
				{
					lineNumber++;
				}
				input = input.substr(1, input.length());
			}
		}
		tokens.push_back(endfile->CreateToken("", lineNumber));
		return tokens;
	}
};

