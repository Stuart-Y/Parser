#pragma once
#include "Automaton.h"
class UndefinedAutomaton :
    public Automaton
{
public:
    UndefinedAutomaton(TokenType type) {
        this->type = type;
    }

    int Start(string input, int lineNumber) {
        return 1;
    }
};

