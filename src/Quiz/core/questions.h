#ifndef _QUESTIONS_H
#define _QUESTIONS_H

#include <string>

using namespace std;

/// @brief classe questions

class Questions
{
private:
    /// @brief question du quiz
    string question;
    
    /// @brief tableau de choix d'une question
    string choix[4];

    /// @brief difficulte de la question
    string difficultee;

    /// @brief tableau du type de la question (drapeux de pays/ capitales de pays/ culture generale/ films ou series)
    string type[4];

public:

    /// @brief constructeur
    Questions();

};

#endif