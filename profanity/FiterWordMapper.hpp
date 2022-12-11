#ifndef FiterWordMapper_hpp
#define FiterWordMapper_hpp

#include <stdio.h>
#include <map>
#include <string>
using namespace std;

class TreeNode{
    char character;
    int depth;
    bool last;
    map<char, TreeNode> map;
public:
    
    std::map<char, TreeNode>::iterator end();
    std::map<char, TreeNode>::iterator begin();
    std::map<char, TreeNode>::iterator find(char);

    void createBranch(char);
    void display();
    bool isLastChar();
    void setLast();

    TreeNode(char, int);
};

class FilterManager{
    TreeNode tree;

public:
    
    string checkString(string);
    void displayData();
    bool loadTxt(string);
    void addWord(string);
    FilterManager();
};

#endif /* FiterWordMapper_hpp */
