#ifndef IMGLOADER_HPP
#define IMGLOADER_HPP

/**
 * Charge une image
 * Paramètres:
 * - nom du fichier
 * - (out) largeur
 * - (out) hauteur
 * - (out) nombre de champs couleur
 * Retourne le contenu de l'image
 */
unsigned char * IMG_Load(const char *, int&, int&, int&);

#endif