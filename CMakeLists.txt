cmake_minimum_required(VERSION 3.2)
project(Prog3D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# EXECUTABLE
#########################################################

set(SOURCE_FILES main.hpp main.cpp
        Fenetre.hpp Fenetre.cpp

        Geometry/Matrice.hpp
        Geometry/Point.hpp Geometry/Point.cpp
        Geometry/Segment.hpp Geometry/Segment.cpp
        Geometry/Vecteur.hpp Geometry/Vecteur.cpp
        Geometry/Droite.hpp Geometry/Droite.cpp
        Geometry/Plan.hpp Geometry/Plan.cpp
        Geometry/Triangle.hpp Geometry/Triangle.cpp
        Geometry/Rectangle.hpp Geometry/Rectangle.cpp
        Geometry/Box.hpp Geometry/Box.cpp

        Geometry/Curve.hpp Geometry/Curve.cpp
        Geometry/Surface.hpp Geometry/Surface.cpp

        Shapes/Cylinder.hpp Shapes/Cylinder.cpp
        Shapes/Cone.hpp Shapes/Cone.cpp
        Shapes/Ball.hpp Shapes/Ball.cpp
        Shapes/Voxel.hpp Shapes/Voxel.cpp
        Shapes/Volume.hpp Shapes/Volume.cpp
        Shapes/OctreePoint.hpp Shapes/OctreePoint.cpp
        Shapes/Grille.hpp Shapes/Grille.cpp
        Shapes/Mesh.hpp Shapes/Mesh.cpp
        Shapes/DynamicMesh.hpp Shapes/DynamicMesh.cpp
        Shapes/House.hpp Shapes/House.cpp

        Files/OFF.hpp Files/OFF.cpp
        Files/stb_image.h Files/stb_image_write.h
        Files/IMGLoader.hpp Files/IMGLoader.cpp

        Raycaster.hpp Raycaster.cpp
        Lumiere.hpp Lumiere.cpp
        Camera.hpp Camera.cpp

        Tools/Timer.hpp Tools/Timer.cpp
        Tools/Color.hpp Tools/Color.cpp

        UI/Widget.hpp UI/Widget.cpp
        UI/Bouton.hpp UI/Bouton.cpp
        UI/Switch.hpp UI/Switch.cpp
        UI/GraphFIFO.hpp UI/GraphFIFO.cpp
        UI/FPS_Counter.hpp UI/FPS_Counter.cpp
        UI/Tab.hpp UI/Tab.cpp
        UI/Layout.hpp UI/Layout.cpp

        Exercices/Exercice.hpp Exercices/Exercice.cpp
        Exercices/TP1.hpp Exercices/TP1.cpp
        Exercices/TP2.hpp Exercices/TP2.cpp
        Exercices/TP3.hpp Exercices/TP3.cpp
        Exercices/TP4.hpp Exercices/TP4.cpp
        Exercices/TP5.hpp Exercices/TP5.cpp
        Exercices/TP6.hpp Exercices/TP6.cpp
        Exercices/TP7.hpp Exercices/TP7.cpp
        Exercices/TP8.hpp Exercices/TP8.cpp
        Exercices/TP9.hpp Exercices/TP9.cpp
        Exercices/TP10.hpp Exercices/TP10.cpp
        Exercices/TP11.hpp Exercices/TP11.cpp)

add_executable(Prog3D ${SOURCE_FILES})

target_link_libraries(Prog3D ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


add_custom_command(
        TARGET Prog3D POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
                ./Ressources)
add_custom_command(
        TARGET Prog3D POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/Ressources/
                ./Ressources)