#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>

#include <fstream>
#include <vector>
#include "Definition.h"
#include "util.h"



using namespace std;


class Grammar {
private:
    // declare a private list of Production objects
    vector<Definition> definitions;

public:
    Grammar();
    // the only constructor, expecting a file name to read
    Grammar(string);
    // destructor for freeing up memory allocated for the list
    ~Grammar();

    // the recursive function that will build the sentence
    string resolve(string text);
    
    friend ostream& operator<<(ostream& stream, Grammar& grm);
};

ostream& operator<<(ostream& stream, Grammar& grm);


#endif //GRAMMAR_H
