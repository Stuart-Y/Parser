#pragma once
#include<vector>
#include "Token.h"
class Parameter
{
private:
	Token* data;
public:
	Parameter(Token* data) {
		this->data = data;
	}

	string ToString() {
		return data->inputString();
	}
};

