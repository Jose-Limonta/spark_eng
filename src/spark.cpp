/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 *
 * */

#include "includes.h"



int main() {
	constexpr int ANCHO_W = 800;
	constexpr int ALTO_W  = 450;

	using namespace spark;
	using namespace graphics;
	using namespace math;

    timer tm {};
    unsigned short fps {0};
    float x_mouse_pos {0.0f}, y_mouse_pos {0.0f};
    
	window w {"SPARK2", ANCHO_W, ALTO_W};

	shader* shad1 = new shader { "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
			                     "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag" };
	shader* shad2 = new shader { "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
			                     "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag" };
    
    tileLayer layer1 {shad1};
    tileLayer layer2 {shad2};

    srand(time(NULL));
    for (float _y = ABA_W; _y < ARR_W; _y += 0.1){
        for (float _x = IZQ_W; _x < DER_W; _x += 0.1){
            layer1.add( new sprite {_x,_y, 0.09f, 0.09f, vec4(0,0,rand()%1000/1000.0f,0)});
        }
    }


    layer1.add(new sprite {0,0, 4.0f, 4.0f, vec4(0.7,0,0,0)});
    layer2.add(new sprite {-2,-2, 4.0f, 4.0f, vec4(0.7,0,0,0)});
    tm.reset();

	while(!w.cerrado()){
        w.clear();
		w.mouse_position(x_mouse_pos , y_mouse_pos );
        x_mouse_pos =  (x_mouse_pos  * (DER_W * 2)/ANCHO_W) - DER_W;
        y_mouse_pos =  ARR_W - (y_mouse_pos * (ARR_W * 2)/ALTO_W);

        shad1->enable();
        shad1->setUniform2f("light_pos", vec2 {x_mouse_pos, y_mouse_pos} );
        shad2->enable();
        shad2->setUniform2f("light_pos", vec2 {x_mouse_pos, y_mouse_pos} );

        layer1.render();
        layer2.render();
		w.update();

        if (tm.get_diff() >= 1){
            std::cout << "FPS : " << fps <<std::endl;
            tm.reset();
            fps = 0;
        }
        fps++;
	}

	return (0);
}