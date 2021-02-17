#pragma once
#include "Automaton.h"
class StringAutomaton :
    public Automaton
{
private:
    string element;

public:
    StringAutomaton(TokenType type)
    {
        this->type = type;
    }

    int Start(string input, int lineNumber)
    {
        if (input[0] == '\'')
        {
            bool cycle = true;
            maxReadCount = 1;
            maxLines = 0;
            element = "'";
            for (unsigned int i = 1; cycle && i < input.length(); i++)
            {
                element = element + input[i];
                if (input.length() - i <= 1)
                {
                    type = UNDEFINED;
                    maxLines++;
                    return element.length();
                }
                if (input[i] == '\n')
                {
                    maxLines++;
                }
                if (input[i] == '\'')
                {
                    cycle = false;
                    if (input[i + 1] == '\'')
                    {
                        cycle = true;
                        i++;
                        element = element + input[i];
                    }
                }
            }
            return element.length();
        }
        return 0;
    }
};

