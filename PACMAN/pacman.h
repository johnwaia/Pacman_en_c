#include "Labyrinthe.h"
#ifndef PACMAN_H
#define PACMAN_H

typedef struct {
  int x;                // Position X
  int y;                // Position Y
  int pacGommesMangees; // Nombre de pac-gommes mangées
  int enVie;            // Etat de Pac-Man (0 = mort, 1 = en vie)
} Pacman;

// Fonction pour initialiser la position de Pac-Man
void initPacman(Pacman *pacman, int x, int y, Labyrinthe *lab);

// Fonctions pour déplacer Pac-Man
void movePacmanTop(Pacman *pacman, Labyrinthe *lab);
void movePacmanBottom(Pacman *pacman, Labyrinthe *lab);
void movePacmanLeft(Pacman *pacman, Labyrinthe *lab);
void movePacmanRight(Pacman *pacman, Labyrinthe *lab);

#endif // PACMAN_H
