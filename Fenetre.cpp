#include "Fenetre.hpp"

Fenetre * Fenetre::actual = nullptr;

void Fenetre::InitGL() {
    // Active les tests de profondeur
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

Fenetre& Fenetre::Actual() {
    return *Fenetre::actual;
}


Fenetre::Fenetre(const char * name, int width, int height, int argc, char * argv[]) :
    tpNum(1), exoNum(1)
{
    Fenetre::actual = this;

    // Initialise GLUT
    glutInit(&argc, argv);

    /**
     * Configure quelques options de GLUT :
     * - GLUT_DOUBLE active le « double buffering » (dessiner dans un tampon en arrière-plan pendant qu'un autre tampon est affiché)
     * - GLUT_RGBA définit le format des pixels du tampon de couleurs où sont appliqués les rendus (par exemple : l'écran)
    */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Initialise la taille de la fenêtre
    glutInitWindowSize(width, height);

    this->win_width = width;
    this->win_height = height;

    // Initialise la position de la fenêtre
    glutInitWindowPosition(100, 100);

    // Crée une fenêtre avec le nom entré en paramètres
    this->id = glutCreateWindow(name);

    // Assigne le callback de rendu
    glutDisplayFunc(Fenetre::OnDisplay);
    // Assigne le callback de redimensionnement de la fenêtre
    glutReshapeFunc(Fenetre::OnReshape);
    // Assigne le callback de la gestion des évènements clavier
    glutKeyboardFunc(Fenetre::OnKeyboardEvent);
    // Assigne le callback de la gestion des évènements souris
    glutMouseFunc(Fenetre::OnMouseEvent);
    // Assigne le callback de la gestion des évènements de mouvement de souris (avec bouton pressé)
    glutMotionFunc(Fenetre::OnMotionPressedEvent);
    // Assigne le callback de la gestion des évènements de mouvement de souris (sans bouton pressé)
    glutPassiveMotionFunc(Fenetre::OnMotionUnpressedEvent);

    // Définit la couleur qui sera utilisée lors du vidage du tampon d'image
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // On initialise certaines choses
    Fenetre::InitGL();

    this->ortho = true;

    this->exo = new TP1Exo();

    // On crée un menu de sélection des TPS

    int menu2 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 21);
    glutAddMenuEntry(" Exercice 2 ", 22);
    glutAddMenuEntry(" Exercice 3 ", 23);

    int menu3 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 31);
    glutAddMenuEntry(" Exercice 2 ", 32);
    glutAddMenuEntry(" Exercice 3 ", 33);

    int menu4 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 41);
    glutAddMenuEntry(" Exercice 2 ", 42);
    glutAddMenuEntry(" Exercice 3 ", 43);

    int menu5 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 51);
    glutAddMenuEntry(" Exercice 2 ", 52);
    glutAddMenuEntry(" Exercice 3 ", 53);

    int menu6 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 2 ", 62);
    glutAddMenuEntry(" Exercice 3 ", 63);

    int menu7 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 71);

    int menu8 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 81);

    int menu9 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 91);
    glutAddMenuEntry(" Exercice 2 ", 92);
    glutAddMenuEntry(" Exercice 3 ", 93);
    glutAddMenuEntry(" Exercice 4 ", 94);

    int menu10 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 1 ", 101);
    glutAddMenuEntry(" Exercice 2 ", 102);

    int menu11 = glutCreateMenu(Fenetre::SelectExo);
    glutAddMenuEntry(" Exercice 2 ", 112);

    this->menu_main = glutCreateMenu(Fenetre::SelectExo);

    glutAddMenuEntry(" TP 1 ", 11);
    glutAddSubMenu(" TP 2 ", menu2);
    glutAddSubMenu(" TP 3 ", menu3);
    glutAddSubMenu(" TP 4 ", menu4);
    glutAddSubMenu(" TP 5 ", menu5);
    glutAddSubMenu(" TP 6 ", menu6);
    glutAddSubMenu(" TP 7 ", menu7);
    glutAddSubMenu(" TP 8 ", menu8);
    glutAddSubMenu(" TP 9 ", menu9);
    glutAddSubMenu(" TP 10 ", menu10);
    glutAddSubMenu(" TP 11 ", menu11);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

Fenetre::~Fenetre() {
    glutDestroyMenu(this->menu_main);
    glutDestroyWindow(this->id);
}

int Fenetre::GetWidth() const {
    return this->win_width;
}

int Fenetre::GetHeight() const {
    return this->win_height;
}

void Fenetre::Execute() {
    // Lance la boucle interne de GLUT
    glutMainLoop();
}

void Fenetre::initOrtho() {
    this->ortho = true;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    // On initialise la caméra en orthographique
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    // Spécifie quelle matrice est la matrice actuelle : Modèle de vue
    glMatrixMode(GL_MODELVIEW);
}

void Fenetre::initPerspective() {
    this->ortho = false;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    // On initialise la caméra en perspective
    Camera::Perspective(Camera::FOVY, (double)win_width / (double)win_height, Camera::ZNEAR, Camera::ZFAR);

    // Spécifie quelle matrice est la matrice actuelle : Modèle de vue
    glMatrixMode(GL_MODELVIEW);
}

void Fenetre::OnDisplay() {
    // Vide le tampon d'image
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // On initialise la couleur
    glColor3f(1.0, 1.0, 1.0);

    // On initialize la taille d'un point
    glPointSize(5);

    glMatrixMode(GL_PROJECTION);

    //On charge la matrice d'identité
    glLoadIdentity();

    if (Fenetre::actual->ortho) {
        // On initialise la caméra en orthographique
        glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    }
    else {
        // On initialise la caméra en perspective
        Camera::Perspective();
    }

    Lumiere::Mode3D();
    Fenetre::actual->exo->OnDraw3D();

    glMatrixMode (GL_PROJECTION);

    glLoadIdentity ();

    gluOrtho2D (0, (double)Fenetre::actual->win_width, 0, (double)Fenetre::actual->win_height);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    Lumiere::Mode2D();
    Fenetre::actual->exo->OnDraw2D();

    // Trace la scène : Avec un seul buffer
    //glFlush();
    // Echange les buffers de rendu
    glutSwapBuffers();

    glutPostRedisplay();
}

void Fenetre::OnReshape(int width, int height) {
    // Assigne le viewport (espace de visibilité)
    glViewport(0, 0, width, height);

    // Spécifie quelle matrice est la matrice actuelle : Projection
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (Fenetre::actual->ortho) {
        // On initialise la caméra en orthographique
        glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    }
    else {
        // On initialise la caméra en perspective
        Camera::Perspective(Camera::GetFOVY(), (double)width / (double)height, Camera::GetZNear(), Camera::GetZFar());
    }

    // Spécifie quelle matrice est la matrice actuelle : Modèle de vue
    glMatrixMode(GL_MODELVIEW);
}

void Fenetre::OnKeyboardEvent(unsigned char key, int x, int y) {
    Fenetre::actual->exo->OnKeyboardEvent(key, x, y);
}

void Fenetre::OnMouseEvent(int button, int state, int x, int y) {
    Fenetre::actual->exo->OnMouseEvent(button, state, x, y);
}

void Fenetre::OnMotionPressedEvent(int x, int y) {
    Fenetre::actual->exo->OnMotionPressedEvent(x, y);
}

void Fenetre::OnMotionUnpressedEvent(int x, int y) {
    Fenetre::actual->exo->OnMotionUnpressedEvent(x, y);
}

void Fenetre::SelectExo(int index) {
    Fenetre::DestroyExo();

    Fenetre::actual->tpNum = index / 10;
    Fenetre::actual->exoNum = index % 10;

    switch (index) {
        case 11:
            Fenetre::actual->exo = new TP1Exo();
            break;
        case 21:
            Fenetre::actual->exo = new TP2Exo1();
            break;
        case 22:
            Fenetre::actual->exo = new TP2Exo2();
            break;
        case 23:
            Fenetre::actual->exo = new TP2Exo3();
            break;
        case 31:
            Fenetre::actual->exo = new TP3Exo1();
            break;
        case 32:
            Fenetre::actual->exo = new TP3Exo2();
            break;
        case 33:
            Fenetre::actual->exo = new TP3Exo3();
            break;
        case 41:
            Fenetre::actual->exo = new TP4Exo1();
            break;
        case 42:
            Fenetre::actual->exo = new TP4Exo2();
            break;
        case 43:
            Fenetre::actual->exo = new TP4Exo3();
            break;
        case 51:
            Fenetre::actual->exo = new TP5Exo1();
            break;
        case 52:
            Fenetre::actual->exo = new TP5Exo2();
            break;
        case 53:
            Fenetre::actual->exo = new TP5Exo3();
            break;
        case 62:
            Fenetre::actual->exo = new TP6Exo2();
            break;
        case 63:
            Fenetre::actual->exo = new TP6Exo3();
            break;
        case 71:
            Fenetre::actual->exo = new TP7Exo1();
            break;
        case 81:
            Fenetre::actual->exo = new TP8Exo1();
            break;
        case 91:
            Fenetre::actual->exo = new TP9Exo1();
            break;
        case 92:
            Fenetre::actual->exo = new TP9Exo2();
            break;
        case 93:
            Fenetre::actual->exo = new TP9Exo3();
            break;
        case 94:
            Fenetre::actual->exo = new TP9Exo4();
            break;
        case 101:
            Fenetre::actual->exo = new TP10Exo1();
            break;
        case 102:
            Fenetre::actual->exo = new TP10Exo2();
            break;
        case 112:
            Fenetre::actual->exo = new TP11Exo2();
            break;

        default:
            Fenetre::actual->exo = new TP1Exo();
            Fenetre::actual->tpNum = 1;
            Fenetre::actual->exoNum = 1;
    }

    std::stringstream win_name;
    win_name << "OpenGL - TP " << Fenetre::actual->tpNum << " - Exercice " << Fenetre::actual->exoNum;
    glutSetWindowTitle(win_name.str().c_str());
}

void Fenetre::DestroyExo() {
    switch (Fenetre::actual->tpNum) {
        case 1:
            delete ((TP1Exo *)Fenetre::actual->exo);
            break;
        case 2:
            switch (Fenetre::actual->exoNum) {
                case 1:
                    delete ((TP2Exo1 *)Fenetre::actual->exo);
                    break;
                case 2:
                    delete ((TP2Exo2 *)Fenetre::actual->exo);
                    break;
                case 3:
                    delete ((TP2Exo3 *)Fenetre::actual->exo);
                    break;
            }
            break;
        case 3:
            switch (Fenetre::actual->exoNum) {
                case 1:
                    delete ((TP3Exo1 *)Fenetre::actual->exo);
                    break;
                case 2:
                    delete ((TP3Exo2 *)Fenetre::actual->exo);
                    break;
                case 3:
                    delete ((TP3Exo3 *)Fenetre::actual->exo);
                    break;
            }
            break;
        case 4:
            switch (Fenetre::actual->exoNum) {
                case 1:
                    delete ((TP4Exo1 *)Fenetre::actual->exo);
                    break;
                case 2:
                    delete ((TP4Exo2 *)Fenetre::actual->exo);
                    break;
                case 3:
                    delete ((TP4Exo3 *)Fenetre::actual->exo);
                    break;
            }
            break;
        case 5:
            switch (Fenetre::actual->exoNum) {
                case 1:
                    delete ((TP5Exo1 *)Fenetre::actual->exo);
                    break;
                case 2:
                    delete ((TP5Exo2 *)Fenetre::actual->exo);
                    break;
                case 3:
                    delete ((TP5Exo3 *)Fenetre::actual->exo);
                    break;
            }
            break;
        case 6:
            switch (Fenetre::actual->exoNum) {
                case 2:
                    delete ((TP6Exo2 *)Fenetre::actual->exo);
                    break;
                case 3:
                    delete ((TP6Exo3 *)Fenetre::actual->exo);
                    break;
            }
            break;
        case 7:
            switch (Fenetre::actual->exoNum) {
                case 1:
                    delete ((TP7Exo1 *)Fenetre::actual->exo);
                    break;
            }
            break;

        default:
            delete Fenetre::actual->exo;
    }
}
