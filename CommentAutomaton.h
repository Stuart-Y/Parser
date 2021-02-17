#pragma once
#include "Automaton.h"
class CommentAutomaton :
    public Automaton
{
public:
    CommentAutomaton(TokenType type)
    {
        this->type = type;
    }

    int Start(string input, int lineNumber)
    {
        maxReadCount = 0;
        if (type != COMMENT)
        {
            cout << "ERROR: Comment Automaton Improperly Requested";
            return 0;
        }
        else if (input[0] == '#')
        {
            if (input[1] == '|')
            {
                maxReadCount++;
                maxReadCount++;
                bool cycle = true;
                for (unsigned int i = 2; i < input.length() && cycle; i++)
                {
                    maxReadCount++;
                    if (input[i] == '\n')
                    {
                        maxLines++;
                    }
                    if (input[i] == '|')
                    {
                        if (input[i + 1] == '#')
                        {
                            cycle = false;
                            maxReadCount++;
                        }
                    }
                }
                return maxReadCount;
            }
            else {
                for (unsigned int j = 0; input[j] != '\n' && j < input.length(); j++)
                {
                    maxReadCount++;
                }
                return maxReadCount;
            }
        }
        return 0;
    }
};

