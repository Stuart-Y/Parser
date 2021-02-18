#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"
#include "DatalogProgram.h"
#include "Lexer.h"
#include "Token.h"
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    string fileName = argv[1];
    ifstream input;
    string file;
    vector <Token*> lexInput;
    Lexer program = Lexer();

    input.open(fileName);

    if (input.fail())
    {
        cerr << "File Read Error" << endl;
    }
    else
    {
        for (int i = 0; input.peek() != EOF; i++)
        {
            file = file += input.get();
        }
    }
    input.close();

    lexInput = program.Run(file);

    for (int i = 0; i < lexInput.size(); i++)
    {
        if (lexInput.at(i)->getType() == COMMENT)
        {
            lexInput.erase(lexInput.begin() + i);
            i--;
        }
    }

    Parser read = Parser(lexInput);

    return 0;
}