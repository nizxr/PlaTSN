#ifdef _QUIZ_H
#define _QUIZ_H

#include <string>
#include "Question.h"

using namespace std;


/// @brief classe quiz

class Quiz
{
    private:
        Question questions[3];
   

    public:
        /// @brief constructeur 
        Quiz();
        
        bool a_gagne(string r1, string r2, string r3);       


};

#endif