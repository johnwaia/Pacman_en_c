#include "Labyrinthe.h"
#ifndef FANTOME_H
#define FANTOME_H

typedef struct {
  int x;          // Position X
  int y;          // Position Y
  char **memoire; // Mémoire des déplacements
  int memoireDur; // Durée de la mémoire
} Fantome;

// Fonction pour initialiser la position d'un fantôme au hasard
void initFantomeRand(Fantome *fantome, Labyrinthe *lab);

// Fonction pour déplacer un fantôme au hasard
void moveFantomeRand(Fantome *fantome, Labyrinthe *lab);

// Fonction pour déplacer un fantôme en utilisant la mémoire
void moveFantomeMem(Fantome *fantome, Labyrinthe *lab);

// Fonction pour rafraîchir la mémoire d'un fantôme
void refreshFantomeMem(Fantome *fantome, int tour);

#endif // FANTOME_H
