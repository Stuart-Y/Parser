#pragma once
#include <string>
#include <iostream>

using namespace std;

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, 
	COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, 
	QUERIES, ID, STRING, COMMENT, UNDEFINED, ENDFILE};

class Token
{
private:
	string input;
	int lineNumber;
	TokenType type;
	string tokenTypeToString(TokenType token)
	{
		switch (token) 
		{
			case COMMA: return "COMMA"; break;
			case PERIOD: return "PERIOD"; break;
			case Q_MARK: return "Q_MARK"; break;
			case LEFT_PAREN: return "LEFT_PAREN"; break;
			case RIGHT_PAREN: return "RIGHT_PAREN"; break;
			case COLON: return "COLON"; break;
			case COLON_DASH: return "COLON_DASH"; break;
			case MULTIPLY: return "MULTIPLY"; break;
			case ADD: return "ADD"; break;
			case SCHEMES: return "SCHEMES"; break;
			case FACTS: return "FACTS"; break;
			case RULES: return "RULES"; break;
			case QUERIES: return "QUERIES"; break;
			case ID: return "ID"; break;
			case STRING: return "STRING"; break;
			case COMMENT: return "COMMENT"; break;
			case UNDEFINED: return "UNDEFINED"; break;
			case ENDFILE: return "EOF"; break;
		}
		cout << "TokenType Error: Type not found";
		return "";
	}
public:
	Token(TokenType type, string input, int lineNumber) {
		this->type = type;
		this->input = input;
		this->lineNumber = lineNumber;
	}

	string toString()
	{
		string out;
		out = "(" + tokenTypeToString(type) + "," + '"' + input + '"'+  "," + to_string(lineNumber) + ")" + '\n';
		return out;
	}
};

