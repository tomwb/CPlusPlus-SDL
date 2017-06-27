// brew install sdl2
// clang++ -std=c++11 -stdlib=libc++ game.cpp -I/usr/local/include -L/usr/local/lib -lSDL2 -o game
// https://abaixonivel.wordpress.com/tutoriais/sdl2/seu-primeiro-game-em-sdl-p1/
// https://wiki.libsdl.org

#include "core/engine.h"
#include "Assets/Objects/square.h"
#include "Assets/Objects/circle.h"

class Game: public Engine {
	public:

		// Objetos na cena;
		Square retangulo;
		Circle circulo;
		
		/*
		 * metodo que incializa o jogo
		 */
		void Start () {
			circulo.color = {255,255,255};
			circulo.position = {255,255};
			circulo.radius = 50;
		}

		/*
		 * metodo que itera entre o jogo
		 */
		void Update () {
			// ObjRectRenderer(retangulo);
			retangulo.position.x += 1;
			retangulo.position.y += 1;			
		}

		void Render() {
			circulo.Render(my_window);
			retangulo.Render(my_window);			
		}
};

/*
 * main
 */
int main(int argc, char **argv)
{
	Game my_game;
	my_game.init();
}