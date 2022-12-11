# BEST-Elimination
## Problem description
A cursed word filtration system is a tool used to block or filter out certain words that are considered inappropriate or offensive. The given setnece is being checked, then all ofensive words are replaced by '*'.
The system can be used to protect users from seeing words that could be considered offensive or triggering.

## Solution
Raw text from input is being filtered in various ways, signs are replaced by suiting letters, duplicates are being cut into one letter, not existing signs as well as letters are being dumped from the text witch will be later on tested by the programme.
Changes were made as described below:
- Conversion of (1,3,4,0,v,@,!,$) into (i,e,a,o,u,a,i,s)
- Changing uppercase into lowercase
- Detecting 'vv' and converting it into 'w'
- Repeating letters cut into one for ex. ssłoowo into słowo
- Polish signs converted into its english counterpart

## Additional info
The project was realised using `c++` and ui was based on 'winforms'.
