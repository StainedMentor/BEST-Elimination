
#include <iostream>
#include "FiterWordMapper.hpp"
#include "ExtraFunctions.hpp"
using namespace std;

const string address = "/Users/oli/Desktop/dev/profanityMapper/profanityMapper/db.txt";

const string testStr = "dłuchuj";

int main(int argc, const char * argv[]) {
    
    FilterManager mapper = FilterManager();
    
    if (mapper.loadTxt(address)){
        
        cout << "File loaded successfully" << endl;
//        mapper.displayData();
        cout << mapper.checkString(testStr) << endl;
        
        string input;
        while (input != "exit"){
            cout << "write text: ";
            getline(cin, input);
            input = removeConfusingSymbols(input);
            cout << mapper.checkString(input) << endl;
        }
        
    }
    else {
        cout << "Failed to load file" << endl;
        return 1;
    }
    
    return 0;
}


