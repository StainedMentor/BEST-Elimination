#include "FiterWordMapper.h"
#include "ExtraFunctions.hpp"
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <iomanip>

using namespace std;
using namespace TREE;
const int txt_seperator = ',';


// Tree structure and its utility functions
std::map<char, TreeNode>::iterator TreeNode::end(){
    return map.end();
}
std::map<char, TreeNode>::iterator TreeNode::begin(){
    return map.begin();
}
std::map<char, TreeNode>::iterator TreeNode::find(char character){
    return map.find(character);
}

// initializer
TreeNode::TreeNode(char character, int depth){
    this->depth = depth + 1;
    this->character = character;
}
// wether its the last char
bool TreeNode::isLastChar(){
    return last;
}
void TreeNode::setLast(){
    last = true;
}
// add letter to tree
void TreeNode::createBranch(char character){
    map.emplace(character, TreeNode(character, depth + 1));
}

// displays database in log
void TreeNode::display(){
    std::map<char, TreeNode>::iterator it;

    for (it = map.begin(); it != map.end(); it++)
    {
        cout << setw(depth) << " ";
        cout << it->first << endl;
        it->second.display();

    }
}

// adds word to internal db
void FilterManager::addWord(string s){
    TreeNode * node = &tree;

    for (long i = 0; i < s.length(); i++){
            map<char, TreeNode>::iterator it = (*node).find(s[i]);
            //cout << (*node).isLastChar();
            //cout << it->first;

            if (it != (*node).end()){
                node = &(it->second);
            }
            else {
                (*node).createBranch(s[i]);
                it = (*node).find(s[i]);
                node = &(it->second);
            }
    }
    //cout << endl;
    (*node).setLast();
}

// init
FilterManager::FilterManager():tree(' ', 0){}

// initialize database from txt file
bool FilterManager::loadTxt(string location){
    ifstream input(location, ifstream::in);
    string word;
    stringstream buffer;
    buffer << input.rdbuf();
    while (getline(buffer,word, ',')) {
        word = removePolishSymbol(word);
        //cout << word << endl;
        addWord(word);
    }
    //displayData();
    input.close();
    return 1;
}

// display database in log
void FilterManager::displayData(){
    tree.display();
}

// check string for profanities
string checkStandard(string s, TreeNode &tree, int i){
    TreeNode *node = &tree;
    map<char, TreeNode>::iterator it;

    it = (*node).find(s[i]);
    if (it != (*node).end() ){
        int left = s.length() - i + 1;
        int j;
        
        for (j = 1; j < left && j < 20; j++){

            node = &(it->second);
            it = (*node).find(s[i+j]);
            
            if ((*node).isLastChar()){
                s = applyStars(s, i, j);
                break;
            }

            if (it == (*node).end() ) {
                break;
            }

        }
    }

    return  s;
}
string checkWithExtraSymbol(string s, TreeNode &tree, int i){
    for (int pos = 1; pos < 14; pos++){

        TreeNode *node = &tree;
        map<char, TreeNode>::iterator it;

        it = (*node).find(s[i]);
        if (it != (*node).end() ){
            
            int left = s.length() - i + 1;
            int j;
            
            for (j = 1; j < left && j < 20; j++){
                if (j == pos) j++;
                
                node = &(it->second);
                it = (*node).find(s[i+j]);
                
                if ((*node).isLastChar()){
                    s = applyStars(s, i, j);
                    break;
                }
                
                if (it == (*node).end() ) {
                    break;
                }
                
            }
        }
    }

    return  s;
}
string checkForIL(string s, TreeNode &tree, int i){
    TreeNode *node = &tree;
    map<char, TreeNode>::iterator it;

    it = (*node).find(s[i]);
    if (it != (*node).end() ){
        int left = s.length() - i + 1;
        int j;
        
        for (j = 1; j < left && j < 20; j++){

            node = &(it->second);
            it = (*node).find(s[i+j]);
            
            if ((*node).isLastChar()){
                s = applyStars(s, i, j);
                break;
            }

            if (it == (*node).end() ) {
                break;
            }

        }
    }

    return  s;
}
string checkForSwapped(string s, TreeNode &tree, int i){
    for (int pos = 1; pos < 14; pos++){

        TreeNode *node = &tree;
        map<char, TreeNode>::iterator it;

        it = (*node).find(s[i]);
        if (it != (*node).end() ){
            
            int left = s.length() - i + 1;
            int j;
            
            for (j = 1; j < left && j < 20; j++){
                
                node = &(it->second);
                if (j == pos){
                    it = (*node).find(s[i+j+1]);
                }
                else if (j == pos+1){
                    it = (*node).find(s[i+j-1]);
                }
                else {
                    it = (*node).find(s[i+j]);

                }
                if ((*node).isLastChar()){
                    s = applyStars(s, i, j);
                    break;
                }
                
                if (it == (*node).end() ) {
                    break;
                }
                
            }
        }
    }

    return  s;
}


string FilterManager::checkString(string input){
    input = removePolishSymbol(input);
    for (int i = 0; i < input.length(); i++){
        input = checkStandard(input, tree, i);
        input = checkWithExtraSymbol(input, tree, i);
        input = checkForSwapped(input, tree, i);


    }
    cout << input;
    return input;
}

