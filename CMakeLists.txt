cmake_minimum_required(VERSION 3.26)
project(OpenGL_Minimal)

set(CMAKE_CXX_STANDARD 17)

# Comme ça tout est dans le même dossier
# Au moins on trouve rapidement
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(OpenGL_Minimal main.cpp)

# Marche direct sur linux, sur windows bof du coup on utilise vcpkg qui
# fait le travail pour nous
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(OpenGL_Minimal PRIVATE GLEW::GLEW glfw glm::glm OpenGL::GL)