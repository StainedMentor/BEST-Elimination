#include "ExtraFunctions.hpp"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

const string polishSymbols = "ąćęłóśńźż";
const string normalisedSymbols = "acelosnzz";

string removePolishSymbol(string s){
    for (long i = 0; i < s.length()-1; i++){
        size_t it = polishSymbols.find(s.substr(i,2));
                                       
        if (it == string::npos) ;
        else {
            s.replace(i, 2, 1, normalisedSymbols[it/2]);
        }

    }
    return s;
}

const string confusingSymbols = "1@!340$";
const string nonConfusingSymbols = "iaieaos";
const string removableSymbols = "_xq.,#%^&-()=+";

string removeConfusingSymbols(string s) {
    int n = s.length();

    // replace every confusing symbol in string
    for (long i = 0; i < s.length(); i++){
        size_t it = confusingSymbols.find(s.substr(i,1));
                                       
        if (it != string::npos){
            s.replace(i, 2, 1, nonConfusingSymbols[it]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        s[i] = tolower(s[i]);
    }
    // check for every duplicate v and remove extra symbols
    int i = 0;
    while (i != n) {
        int vFound = 0;
        
        while (s[i] == s[i+1]) {
            if (s[i+1] == 'v') {
                vFound++;
            }
            s.erase(i+1, 1);
            n--;
        }
        if (removableSymbols.find(s[i]) != string::npos) {
            s.erase(i, 1);
            n--;
            i--;
        }
        else if (vFound == 1) {
            s[i] = 'w';
//            i++;
        }
        else if (s[i] == 'v') {
            s[i] = 'u';
            i++;

        }
        else {
            i++;

        }
//        cout<<n;
    }
    return s;
}

// extends and applys stars to reach the next blank symbol
string applyStars(string input, int& i, int& j){
    
    for (int d = 1; d < 5 && i - 1 >= 0; d++){

        if (input[i-1] != ' '){
            i --;
            j ++;
        }
        else break;
    }
    for (int d = 1; d < 5 && i + j + 1 <= input.length(); d++){
        if (input[i+j] != ' '){
            j ++;
        }
        else if( i + j == input.length()) j++;
        else break;
    }
    
    input.replace(i, j, j, '*');
    i += j;
    return input;
}

