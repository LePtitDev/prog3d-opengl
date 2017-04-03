#ifndef PROG3D_MAIN_HPP
#define PROG3D_MAIN_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <chrono>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI 3.14159265358979323846
#include <GL/glut.h>

class Point;
class Vecteur;
class Segment;
class Droite;
class Plan;
class Triangle;
class RRectangle;

class Curve;
class Surface;

class Mesh;
class DynamicMesh;

class Camera;

//GEOMETRY
#include "Geometry/Matrice.hpp"
#include "Geometry/Point.hpp"
#include "Geometry/Vecteur.hpp"
#include "Geometry/Segment.hpp"
#include "Geometry/Droite.hpp"
#include "Geometry/Plan.hpp"
#include "Geometry/Triangle.hpp"
#include "Geometry/Rectangle.hpp"
#include "Geometry/Box.hpp"

#include "Geometry/Curve.hpp"
#include "Geometry/Surface.hpp"

//FORMES
#include "Shapes/Cylinder.hpp"
#include "Shapes/Cone.hpp"
#include "Shapes/Ball.hpp"
#include "Shapes/Voxel.hpp"
#include "Shapes/Volume.hpp"
#include "Shapes/OctreePoint.hpp"
#include "Shapes/Grille.hpp"
#include "Shapes/Mesh.hpp"
#include "Shapes/DynamicMesh.hpp"

//FILES
#include "Files/OFF.hpp"

//SCENE
#include "Raycaster.hpp"
#include "Lumiere.hpp"
#include "Camera.hpp"

//TOOLS
#include "Tools/Timer.hpp"
#include "Tools/Color.hpp"

//UI
#include "UI/Widget.hpp"
#include "UI/Bouton.hpp"
#include "UI/Switch.hpp"
#include "UI/GraphFIFO.hpp"
#include "UI/FPS_Counter.hpp"
#include "UI/Tab.hpp"
#include "UI/Layout.hpp"

//EXERCICES
#include "Exercices/Exercice.hpp"

#include "Exercices/TP1.hpp"
#include "Exercices/TP2.hpp"
#include "Exercices/TP3.hpp"
#include "Exercices/TP4.hpp"
#include "Exercices/TP5.hpp"
#include "Exercices/TP6.hpp"
#include "Exercices/TP7.hpp"
#include "Exercices/TP8.hpp"
#include "Exercices/TP9.hpp"
#include "Exercices/TP10.hpp"

//ROOT
#include "Fenetre.hpp"

#endif //PROG3D_MAIN_HPP
