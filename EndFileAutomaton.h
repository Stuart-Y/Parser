#pragma once
#include "Automaton.h"
class EndFileAutomaton :
    public Automaton
{
public: 
    EndFileAutomaton(TokenType type)
    {
        this->type = type;
    }
    int Start(string input, int lineNumber)
    {
        return 0;
    }
};

