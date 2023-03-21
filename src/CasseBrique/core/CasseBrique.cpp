#include"CasseBrique.h"
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

const int DIMW = 500;

    void CasseBrique::init(){
    nbBalles = 1;
    nbBriquesUtil = 25;
    score = 0;
    nbVies = 3;

    // Initialisation de la planche
    p.positionXmin = Complex(100,100);
    p.positionXmax = Complex(200,200);

    // Initialisation de(s) balles
    for (int i=0; i<nbBalles;i++){
        (b[i]).position = Complex(50,50);
        (b[i]).vitesse = Complex(rand()%5 - 4, rand()%5 - 4);
    }

    // Initialisation de la grille
    int l, h, nbl, nbh;
    nbl = sqrt(nbBriquesUtil);
    nbh = nbl;
    l = (2 * DIMW/3) / nbl;
    h = (DIMW/2) / nbh;
    for (int i=0; i<sqrt(nbBriquesUtil); i++){
        for (int j=0; j<sqrt(nbBriquesUtil); j++){
            (grille[i][j]).etat = true;
            (grille[i][j].positionXmin) = Complex(j*l, (DIMW/2) + i*h);
            (grille[i][j].positionXmax) = Complex((j+1)*l, (DIMW/2) + (i+1)*h);
            (grille[i][j].vitesse.x) = 0.3;
        }
    }
}

void CasseBrique::update(){

    // Balle(s)
    for (int i=0; i<nbBalles; i++){

        // Balle respawn
        if (b[i].position.y <= 0){
            b[i].position = Complex(DIMW/2, DIMW/3);
            b[i].vitesse = Complex(rand()%5-4, rand()%5-4);
        }

        // Mouvement Balle(s)
        b[i].position = b[i].position + b[i].vitesse;

        // Collision fenetre-Balle(s)
        // Gauche
        if (b[i].position.x < 0) b[i].vitesse.x = -b[i].vitesse.x;
        // Droite
        if (b[i].position.x > DIMW) b[i].vitesse.x = -b[i].vitesse.x;
        // Haut
        if (b[i].position.y >= DIMW) b[i].vitesse.y = -b[i].vitesse.y;
        // Bas
        if (b[i].position.y < 0){
            b[i].vitesse.y = -b[i].vitesse.y;
            nbVies--;
            b[i].position = Complex(DIMW/2, DIMW/3);
            b[i].vitesse = Complex(rand()%5-4, rand()%5-4); 
        }

        // Collision Planche-Balle(s)
        if ((b[i].position.x + b->r < p.positionXmax.x) &&
            (b[i].position.x - b->r > p.positionXmin.x) &&
            (b[i].position.y > p.positionXmin.y) &&
            (b[i].position.y < p.positionXmax.y)) {
                if (b[i].vitesse.x > 0 && b[i].vitesse.y < 0) b[i].vitesse.y *= -1;
                else if (b[i].vitesse.x < 0 && b[i].vitesse.y < 0) b[i].vitesse.y *= -1;
            }
        
        // Collision Grille-Balle(s)
        for (int j=0; j<sqrt(nbBriquesUtil); j++){
            for (int k=0; k<sqrt(nbBriquesUtil); k++){
                if((b[i].position.x > grille[j][k].positionXmin.x) &&
                   (b[i].position.x < grille[j][k].positionXmax.x) &&
                   (b[i].position.y > grille[j][k].positionXmin.y) &&
                   (b[i].position.y < grille[j][k].positionXmax.y)){
                    if (grille[j][k].etat == true) grille[j][k].etat = false;
                   }

            }
        }
    }

    // Grille
    // Mouvement
    for (int i=0; i<sqrt(nbBriquesUtil); i++){
        for (int j=0; j<sqrt(nbBriquesUtil); j++){
            if (grille[i][j].etat == true){
                if (grille[i][j].positionXmin.x < 0 || grille[i][j].positionXmax.x > DIMW){
                    for (int k=0; k<sqrt(nbBriquesUtil); k++){
                        for (int l=0; l<sqrt(nbBriquesUtil); l++){
                            grille[k][l].vitesse.x *= -1;
                            grille[k][l].positionXmin.x += grille[k][l].vitesse.x;
                            grille[k][l].positionXmax.x += grille[k][l].vitesse.x;
                        }
                    }
                }
                grille[i][j].positionXmin.x += grille[i][j].vitesse.x;
                grille[i][j].positionXmax.x += grille[i][j].vitesse.x;
            }
        }
    }
}