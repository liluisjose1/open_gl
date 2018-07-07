cmake_minimum_required(VERSION 3.5) #Versión mínima de cmake 
# Project Name
PROJECT(Dino_OGL)

#########################################################
# INCLUYENDO LIBRERIA GLUT
#########################################################
find_package(GLUT REQUIRED) #buscar la libreria GlUT
include_directories(${GLUT_INCLUDE_DIRS}) # incluir los directorios 
link_directories(${GLUT_LIBRARY_DIRS}) #Linkeo de directorios 
add_definitions(${GLUT_DEFINITIONS}) #Agregar las definiciones 
#########################################################
# INCLUYENDO LIBRERIA OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})


#######################################################
# INCLUYENDO LIBRERIA SOIL
#########################################################

include_directories(${GLFW_INCLUDE_DIRS}) 
include_directories(${GLEW_INCLUDE_DIRS}) 
add_definitions(-DGLEW_STATIC) 
include_directories(${GLM_INCLUDE_DIRS}) 
include_directories(/usr/include/SOIL) 
include_directories(/usr/include/SDL2) 
link_directories(/usr/lib/SOIL) 
link_directories(/usr/lib/SDL2) 

#########################################################nea
# Incluyendo archivos 
#########################################################
add_executable(colmena_game main.cpp) # Agregando nombre del script y compilado

#########################
# Linkeo de librerías 
#########################################################
# creación del ejecutable "hello"

target_link_libraries(colmena_game ${OPENGL_LIBRARY} ${GLUT_LIBRARY} ${GLFW_STATIC_LIBRARIES} ${GLEW_LIBRARIES} SOIL SDL2) 
