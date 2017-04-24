#include "House.hpp"

House::House(const Point& center, float width, float height, float depth, float tx_toit) :
    loaded(false)
{
    float dx = width / 2, dy = (height * (1 - tx_toit)) / 2, dz = depth / 2, y_mur = center.y - (height * tx_toit) / 2;
    //Murs
    this->P[0] = Point(center.x - dx, y_mur - dy, center.z - dz);
    this->P[1] = Point(center.x - dx, y_mur + dy, center.z - dz);
    this->P[2] = Point(center.x + dx, y_mur - dy, center.z - dz);
    this->P[3] = Point(center.x + dx, y_mur + dy, center.z - dz);
    this->P[4] = Point(center.x - dx, y_mur - dy, center.z + dz);
    this->P[5] = Point(center.x - dx, y_mur + dy, center.z + dz);
    this->P[6] = Point(center.x + dx, y_mur - dy, center.z + dz);
    this->P[7] = Point(center.x + dx, y_mur + dy, center.z + dz);
    //Toit
    this->P[8] = Point(center.x, center.y + height / 2, center.z - dz);
    this->P[9] = Point(center.x, center.y + height / 2, center.z + dz);
}

void House::LoadTextures() {
    int ch = 3;
    this->T[0].data = IMG_Load("Ressources/TP 11/mur.tga", this->T[0].width, this->T[0].height, ch);
    this->T[1].data = IMG_Load("Ressources/TP 11/toit.tga", this->T[1].width, this->T[1].height, ch);
    this->T[2].data = IMG_Load("Ressources/TP 11/facade.tga", this->T[2].width, this->T[2].height, ch);
}

void House::Draw() const {
    glBindTexture(GL_TEXTURE_2D, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, this->T[0].width, this->T[0].height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->T[0].data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    this->P[0].Apply();
    glTexCoord2f(0.0f, 1.0f);
    this->P[1].Apply();
    glTexCoord2f(1.0f, 1.0f);
    this->P[3].Apply();
    glTexCoord2f(1.0f, 0.0f);
    this->P[2].Apply();

    glTexCoord2f(0.0f, 0.0f);
    this->P[4].Apply();
    glTexCoord2f(0.0f, 1.0f);
    this->P[5].Apply();
    glTexCoord2f(1.0f, 1.0f);
    this->P[7].Apply();
    glTexCoord2f(1.0f, 0.0f);
    this->P[6].Apply();
    glEnd();

    glTexImage2D(GL_TEXTURE_2D, 0, 3, this->T[2].width, this->T[2].height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->T[2].data);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    this->P[0].Apply();
    glTexCoord2f(0.0f, 0.0f);
    this->P[1].Apply();
    glTexCoord2f(1.0f, 0.0f);
    this->P[5].Apply();
    glTexCoord2f(1.0f, 1.0f);
    this->P[4].Apply();

    glTexCoord2f(0.0f, 1.0f);
    this->P[2].Apply();
    glTexCoord2f(0.0f, 0.0f);
    this->P[3].Apply();
    glTexCoord2f(1.0f, 0.0f);
    this->P[7].Apply();
    glTexCoord2f(1.0f, 1.0f);
    this->P[6].Apply();
    glEnd();

    glTexImage2D(GL_TEXTURE_2D, 0, 3, this->T[1].width, this->T[1].height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->T[1].data);
    glBegin(GL_QUADS);
    glTexCoord2f(5.0f, 0.0f);
    this->P[1].Apply();
    glTexCoord2f(0.0f, 0.0f);
    this->P[5].Apply();
    glTexCoord2f(0.0f, 3.0f);
    this->P[9].Apply();
    glTexCoord2f(5.0f, 3.0f);
    this->P[8].Apply();

    glTexCoord2f(5.0f, 0.0f);
    this->P[3].Apply();
    glTexCoord2f(0.0f, 0.0f);
    this->P[7].Apply();
    glTexCoord2f(0.0f, 3.0f);
    this->P[9].Apply();
    glTexCoord2f(5.0f, 3.0f);
    this->P[8].Apply();
    glEnd();

    glTexImage2D(GL_TEXTURE_2D, 0, 3, this->T[0].width, this->T[0].height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->T[0].data);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    this->P[1].Apply();
    glTexCoord2f(1.0f, 0.0f);
    this->P[3].Apply();
    glTexCoord2f(0.5f, (this->P[8].y - this->P[1].y) / (this->P[1].y - this->P[0].y));
    this->P[8].Apply();

    glTexCoord2f(0.0f, 0.0f);
    this->P[5].Apply();
    glTexCoord2f(1.0f, 0.0f);
    this->P[7].Apply();
    glTexCoord2f(0.5f, (this->P[8].y - this->P[1].y) / (this->P[1].y - this->P[0].y));
    this->P[9].Apply();
    glEnd();
    glDisable(GL_TEXTURE_2D);
}