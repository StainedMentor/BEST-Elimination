#ifndef FiterWordMapper_h
#define FiterWordMapper_h

#include <stdio.h>
#include <map>
#include <string>
namespace TREE {
    class TreeNode {
        char character;
        int depth;
        bool last = false;
        std::map<char, TreeNode> map;
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

    class FilterManager {

        TreeNode tree;

    public:

        std::string checkString(std::string);
        void displayData();
        bool loadTxt(std::string);
        void addWord(std::string);
        FilterManager();
    };
}
#endif /* FiterWordMapper_hpp */
