#include "Quiz.h"
#include <fstream>
#include <iostream>

using namespace std;

Quiz::Quiz(){

    int nb1 = rand()%155;
    int nb2 = rand()%155;
    int nb3 = rand()%155;


    string num1 = to_string(nb1);
    string num2 = to_string(nb2);
    string num3 = to_string(nb3);
    

    ifstream ip("quiz.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string question, choix_001, choix_002, choix_003, choix_004, reponse, type, difficulte, tab;

    while(ip.good()){

        getline(ip, question, ',');
        getline(ip, choix1, ',');
        getline(ip, choix2, ',');
        getline(ip, choix3, ',');
        getline(ip, choix4, ',');
        getline(ip, reponse, ',');
        getline(ip, type, ',');
        getline(ip, difficulte, ',');
        getline(ip, tab, '\n');


        if(tab == num1){
            questions[0] = Question(question, choix1, choix2, choix3, choix4, difficulte, reponse, type);
        }
        else if(tab == num2){
            questions[1] = Question(question, choix1, choix2, choix3, choix4, difficulte, reponse, type);
        }
        else if(tab == num3){
            questions[2] = Question(question, choix1, choix2, choix3, choix4, difficulte, reponse, type);
        }

    }


}

bool Quiz::a_gagne(string r1, string r2, string r3){
    int cmpt;
    cmpt =0;

    if(questions[0].reponse == r1){cmpt++}
    if(questions[1].reponse == r2){cmpt++}
    if(questions[2].reponse == r3){cmpt++}

    return(cmpt>1);
}