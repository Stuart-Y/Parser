#pragma once
#include "Automaton.h"

class IDAutomaton :
    public Automaton
{
private:
public:
    IDAutomaton(TokenType type)
    {
        this->type = type;
    }

    int Start(string input, int lineNumber)
    {
        maxReadCount = 0;
       if (isalpha(input[0]) != 0)
        {
           for (unsigned int i = 0; isalnum(input[i]) != 0; i++)
           {
               maxReadCount++;
           }
           return maxReadCount;
        }
        return 0;
    }
};

