# Puissance X

[Notion](https://nospy.notion.site/)

## Objectif

Puissance 4 fonctionnel en CLI.

Fichier de configuration pour les paramètres du jeu :
- Taille de la grille
- Nombre de pions à aligner pour gagner
- Nombre de joueurs

## Bonus

- Choix du jeux classique (Puisance 4) ou personnalisé (Puissance X)
- `Animation` de la chute des pions
- Couleur des pions en fonction du joueur
- Sauvergarde des scores dans un fichier / leaderboard
- Menu Help

### Bonus à la con

- `IA` pour jouer contre l'ordinateur

## Principes techniques

Matrice pour la grille de jeu (à l'init que des 0) de base 6x7.

While loop pour le jeu.

Fonction pour vérifier si un joueur a gagné.

Fonction pour vérifier si la grille est pleine, donc match nul.

### Tour de jeu

- Demander au joueur de choisir une colonne
- Vérifier si la colonne est valide et si elle n'est pas pleine
- Placer le pion dans la colonne
- Update la grille
- Vérifier si le joueur a gagné (4 pions alignés), ligne, colonne, diagonale
- Passer au joueur suivant

## Structure

Joueur :
- Nom
- Couleur
- 