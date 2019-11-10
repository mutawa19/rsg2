#include "RandomSentenceGenerator.h"

// the one constructor for RSG will call the Grammar constructor passing
// into it the received filename
RandomSentenceGenerator::RandomSentenceGenerator(string filename) : grammar(filename) {}


RandomSentenceGenerator::~RandomSentenceGenerator() {
  
}
// defining the only method RSG can perform, getSentance, which
// will call the recursive function (resolve) defined in Grammar.cpp
string RandomSentenceGenerator::randomSentence(string& text) {
    // text will be "<start>" as an entry to the recursive function
    return grammar.resolve(text);
}

void RandomSentenceGenerator::printGrammar() {
  cout << grammar;
}
