// brew install sdl2
// clang++ -std=c++11 -stdlib=libc++ game.cpp -I/usr/local/include -L/usr/local/lib -lSDL2 -o game
// https://abaixonivel.wordpress.com/tutoriais/sdl2/seu-primeiro-game-em-sdl-p1/

#include <SDL2/SDL.h>
#include "core/engine.h"
#include "Assets/Objects/square.h"

class Game: public Engine {
	public:

		// GameObject retangulo;
		Square retangulo;
		
		/*
		 * metodo que incializa o jogo
		 */
		void Start () {
			// retangulo.size = {100,100};
			// retangulo.position = {350,250};
			// retangulo.color = {0,0,255};
		}

		/*
		 * metodo que itera entre o jogo
		 */
		void Update () {
			// ObjRectRenderer(retangulo);
		}
};

/*
 * main
 */
int main(int argc, char **argv)
{
	Game mygame;
	mygame.init();
}