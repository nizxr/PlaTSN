#ifndef _QUESTIONS_H
#define _QUESTIONS_H

#include <string>

using namespace std;

/*
enum TypeQuestion{
    DRAPEAUX = 1,
    CAPITALES= 2,
    CULTG = 3,
    FILMS_SERIES = 4
};
*/


/// @brief classe questions

class Questions
{
private:
    /// @brief question du quiz
    string question;
    
    /// @brief tableau de choix d'une question
    string choix1;
    string choix2;
    string choix3;
    string choix4;

    /// @brief difficulte de la question
    string difficultee;


    string type;

public:

    /// @brief reponse de la question
    string reponse;

    /// @brief constructeur
    Questions(string q, string c1, string c2, string c3, string c4, string d, string r, string tq) : 
                question(q), choix1(c1), choix2(c2), choix3(c3), choix4(c4), difficultee(d), reponse(r), type(tq){}; 
    
    Questions() : question(""), choix1(""), choix2(""), choix3(""), choix4(""), difficultee(""), reponse(""), type(""){}; 

    Questions& operator= (const Questions& qu){
        question = qu.question;
        choix1 = qu.choix1;
        choix2 = qu.choix2;
        choix3 = qu.choix3;
        choix4 = qu.choix4;
        difficultee = qu.difficultee;
        reponse = qu.reponse;
        type = qu.type;
    }


};

#endif