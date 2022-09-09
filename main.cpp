#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/a/9158263
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

/**

    @TODO : add auto completion
    @TODO : config file .sbshell
    @TODO : command history .sbshell_history

*/

int main()
{
    // alias map
    std::map<string, string> aliases = {};

    system("clear");

    // loop
    while(true)
    {
        // get command input
        string cmd;
        std::cout << "[" << RED << getenv("USER") << RESET << "]" << " ~ ";
        getline(cin, cmd);



        // first check if it's an alias
        if(aliases.count(cmd)>0){
            system(aliases.find(cmd)->second.c_str());
            continue;
        }

        // override alias command
        if(cmd == "alias")
        {
            string name;
            cout << "please enter the name of your alias" << endl << "> ";
            getline(cin, name);
            cout << endl;
            string com;
            cout << "please enter the command of your alias" << endl << "> ";
            getline(cin, com);

            aliases.insert( std::pair<string,string>(name, com));
        }

        // exit command is overriden
        if(cmd == "exit")
        {
            system("clear");
            return 0;
        }else
        {
            // command is not overriden by aliases or anything, execute it
            system(cmd.c_str());
        }
    }
    return 0;
}
