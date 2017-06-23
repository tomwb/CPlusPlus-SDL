#include <SDL2/SDL.h>
#include "structs.h"

class Engine {
	public:
		// variaveis globais
		SDL_Window *window;
		SDL_Renderer *renderer;

		// variaveis da janela
		// char window_title[] = "My Game";
		VectorPosition window_position = {100,100};
		VectorSize window_size = {800,600};

		/*
		 * metodo que incializa o jogo
		 */
		virtual void Start () {}

		/*
		 * metodo que itera entre o jogo
		 */
		virtual void Update () {}

		/*
		 * Renderiza um quadrado na tela
		 */
		SDL_Rect ObjRectRenderer (GameObject game_obj) {
			SDL_SetRenderDrawColor(renderer, game_obj.color.r, game_obj.color.g, game_obj.color.b, 255);
			SDL_Rect obj = {game_obj.position.x, game_obj.position.y, game_obj.size.width, game_obj.size.height};
			SDL_RenderFillRect(renderer, &obj);
			return obj;
		}

		/*
		 * main
		 */
		void init()
		{
			// inicializa a biblioteca SDL
			if(SDL_Init(SDL_INIT_VIDEO) < 0)
				SDL_Log("Cant init %s", SDL_GetError());

			// cria uma janela (Titulo, positionX, PositionY, Width, Height)
			window = SDL_CreateWindow("My Game", window_position.x, window_position.y, window_size.width, window_size.height, 0);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			Start();
		    
			//Gameloop
			bool running = true;
			while(running)
			{
			  	//Detecção de Evento
				SDL_Event event;
				while(SDL_PollEvent(&event))
				{
					switch(event.type)
					{
				      	case SDL_QUIT: //Caso saia
				      		running = false;
				      	break;
				    }
				}

				///Rendering
				SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // RGBA cor de fundo
				SDL_RenderClear(renderer); // limpa a tela

				Update();

				SDL_RenderPresent(renderer); // "apresenta" a tela
			  	
			  	SDL_Delay(10); //Isso causa algo como 60 quadros por segundo.
			}
		}
};