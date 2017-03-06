#include "Fenetre.hpp"

Fenetre * Fenetre::actual = nullptr;

void Fenetre::InitGL() {
    // Active les tests de profondeur
    glEnable(GL_DEPTH_TEST);
}

Fenetre& Fenetre::Actual() {
    return *Fenetre::actual;
}


Fenetre::Fenetre(const char * name, int width, int height, int argc, char * argv[]) {
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

    this->menu_main = glutCreateMenu(Fenetre::SelectExo);

    glutAddMenuEntry(" TP 1 ", 11);
    glutAddSubMenu(" TP 2 ", menu2);
    glutAddSubMenu(" TP 3 ", menu3);
    glutAddSubMenu(" TP 4 ", menu4);
    glutAddSubMenu(" TP 5 ", menu5);
    glutAddSubMenu(" TP 6 ", menu6);

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
    delete Fenetre::actual->exo;

    switch (index) {
        case 11:
            Fenetre::actual->exo = new TP1Exo();
            glutSetWindowTitle("OpenGL - TP 1");
            break;
        case 21:
            Fenetre::actual->exo = new TP2Exo1();
            glutSetWindowTitle("OpenGL - TP 2 - Exercice 1");
            break;
        case 22:
            Fenetre::actual->exo = new TP2Exo2();
            glutSetWindowTitle("OpenGL - TP 2 - Exercice 2");
            break;
        case 23:
            Fenetre::actual->exo = new TP2Exo3();
            glutSetWindowTitle("OpenGL - TP 2 - Exercice 3");
            break;
        case 31:
            Fenetre::actual->exo = new TP3Exo1();
            glutSetWindowTitle("OpenGL - TP 3 - Exercice 1");
            break;
        case 32:
            Fenetre::actual->exo = new TP3Exo2();
            glutSetWindowTitle("OpenGL - TP 3 - Exercice 2");
            break;
        case 33:
            Fenetre::actual->exo = new TP3Exo3();
            glutSetWindowTitle("OpenGL - TP 3 - Exercice 3");
            break;
        case 41:
            Fenetre::actual->exo = new TP4Exo1();
            glutSetWindowTitle("OpenGL - TP 4 - Exercice 1");
            break;
        case 42:
            Fenetre::actual->exo = new TP4Exo2();
            glutSetWindowTitle("OpenGL - TP 4 - Exercice 2");
            break;
        case 43:
            Fenetre::actual->exo = new TP4Exo3();
            glutSetWindowTitle("OpenGL - TP 4 - Exercice 3");
            break;
        case 51:
            Fenetre::actual->exo = new TP5Exo1();
            glutSetWindowTitle("OpenGL - TP 5 - Exercice 1");
            break;
        case 52:
            Fenetre::actual->exo = new TP5Exo2();
            glutSetWindowTitle("OpenGL - TP 5 - Exercice 2");
            break;
        case 53:
            Fenetre::actual->exo = new TP5Exo3();
            glutSetWindowTitle("OpenGL - TP 5 - Exercice 3");
            break;
        case 62:
            Fenetre::actual->exo = new TP6Exo2();
            glutSetWindowTitle("OpenGL - TP 6 - Exercice 2");
            break;
        case 63:
            Fenetre::actual->exo = new TP6Exo3();
            glutSetWindowTitle("OpenGL - TP 6 - Exercice 3");
            break;

        default:
            Fenetre::actual->exo = new TP1Exo();
            glutSetWindowTitle("OpenGL - TP 1");
    }
}
