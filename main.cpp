#include <iostream>

// L'ordre est important
// OpenGL (parce qu'il faut charger les fonctions, ça se fait pas tout seul malheureusement)
#include <GL/glew.h>
// Fenêtres
#include <GLFW/glfw3.h>

int main() {

    // On init glfw (pour les fenêtres)
    glfwInit();

    // Versions d'OpenGL (330 = 3.3)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Le contexte opengl est créé tout seul
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Window name", nullptr, nullptr);

    // On s'assure que le contexte OpenGL est le bon
    // Faire avant glewInit et avant de faire quoi que ce soit avec OpenGL
    // Pourquoi ? : Bonne question
    glfwMakeContextCurrent(window);

    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        std::cout << "Failed to initialize GLEW: " << glewError << std::endl;
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // Tes inputs

        // Tes commandes de rendu

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        // On clear l'écran
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Affichage
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
