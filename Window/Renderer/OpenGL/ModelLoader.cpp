#include "../ModelLoader.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace ModelLoader{ 

    GLuint createVAO() {
        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        return VertexArrayID;
    }

}
