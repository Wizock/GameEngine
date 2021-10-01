#include "init.h"

static void error_callback(int error, const char* description){
	fprintf(stderr, "Error: %s\n", description);
}





bool initGLFW(){  
	if (!glfwInit()) {
		glfwSetErrorCallback(error_callback);
		glfwTerminate();
		return false;
	}
	else{
		return true;
	}
}

bool initGLEW()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return false;
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	return true;
}

int initaliseLibrary(){
	if (initGLEW() == true) {
		std::cout << "GLEW:\nWas Initalised correctly\n";
		return true;
	}
	if (initGLFW() == true) {
		std::cout << "GLFW:\nWas Initalised correctly\n";
		return true;
	}

	else if (initGLEW() != true) {
		std::cout << "GLEW:\nWas Initalised correctly\n";
		return false;
	}
	else if (initGLFW() != true) {
		std::cout << "GLFW:\nWas Initalised correctly\n";
		return false;
	}
}
