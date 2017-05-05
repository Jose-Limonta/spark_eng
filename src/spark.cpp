/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 * */

#include "graphic.h"
#include "maths.h"

#include <GL/glew.h>

int main(){

		using namespace spark;
	    using namespace graphics;
	    using namespace math;

	    window w("SPARK", 800, 450);
	    //glClearColor(0.0.f, 0.0f, 0.4f, 1.0f);

/*
	    GLfloat vert[] = {2,1,0 ,2,2,0 ,5,2,0 ,5,2,0 ,5,1,0 ,2,1,0};
	    //GLushort indices[] = {0,1,2,2,3,0};

	    GLuint vbo;
	    glGenBuffers(1, &vbo);
	    glBindBuffer(GL_ARRAY_BUFFER , vbo);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	    glVertexAttribPointer(0 , 3, GL_FLOAT, GL_FALSE, 0, 0);
	    glEnableVertexAttribArray(0);
*/
	    GLfloat vert[] = {2,1,0 ,2,2,0 ,5,2,0 ,5,1,0};
	    GLushort indices[] = {0,1,2,2,3,0};

	    vertexArray vao;

	    buffer* vbo = new buffer(vert, 4*3, 3);
	    indexBuffer ibo(indices, 6);

	    vao.addBuffer(vbo, 0);


	    shader shad("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
	    			"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag");

	    shad.enable();
	    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	    shad.setUniformMAT4("pr_mat", ortho);
	    shad.setUniformMAT4("m1_mat", mat4::tranlation(vec3(2,4 ,0)) );
	    //shad.setUniformMAT4("m1_mat", mat4::rotation(-30.0f, vec3(0,0,1)) );
	    shad.setUniform2f("light_pos", vec2(3.5, 1.5 ));
	    shad.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));



	    while(!w.cerrado()){
	        w.clear();
	        double x , y;
	        w.mouse_position(x, y);
	        shad.setUniform2f("light_pos", vec2((float) (x* 10.0f/800.0f), (float) (5.0f - (y * 9.0f/450.0f)) ));

	        vao.bind();
	        ibo.bind();

	        glDrawElements(GL_TRIANGLES, ibo.get_cont(), GL_UNSIGNED_SHORT, 0);

	        ibo.unbind();
	        ibo.unbind();

	        w.update();
	    }

	    return (0);
}
