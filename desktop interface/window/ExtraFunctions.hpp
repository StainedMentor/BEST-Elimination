#ifndef ExtraFunctions_hpp
#define ExtraFunctions_hpp

#include <stdio.h>
#include <string>
#include <vector>


std::string removePolishSymbol(std::string);
std::string removeConfusingSymbols(std::string);
std::vector<std::string> generateStrings(std::string);
std::string applyStars(std::string, int&, int&);
#endif 
