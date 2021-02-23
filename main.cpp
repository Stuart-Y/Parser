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
    DatalogProgram* out;

    input.open(fileName);

    if (input.fail())
    {
        cerr << "File Read Error" << endl;
    }
    else
    {
        while (input.peek() != EOF)
        {
            file = file += input.get();
        }
    }
    input.close();

    lexInput = program.Run(file);
    cout << lexInput.size() <<"\n";

    for (unsigned int i = 0; i < lexInput.size(); i++)
    {
        if (lexInput.at(i)->getType() == COMMENT)
        {
            lexInput.erase(lexInput.begin() + i);
            i--;
        }
    }

    cout << lexInput.size() << "\n";

    Parser read = Parser(lexInput);
    try {
        out = read.Run();
    }
    catch (Token* reject) {
        return 1;
    }

    cout << "Success!" << "/n" << out;

    return 0;
}