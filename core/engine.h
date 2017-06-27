#include <SDL2/SDL.h>
#include "structs.h"

class Window {
	public:
		// variaveis globais
		SDL_Window *window;
		SDL_Renderer *renderer;

		// variaveis da janela
		// char window_title[] = "My Game";
		VectorPosition window_position = {100,100};
		VectorSize window_size = {800,600};

		void Open () {
			// cria uma janela (Titulo, positionX, PositionY, Width, Height)
			window = SDL_CreateWindow("My Game", window_position.x, window_position.y, window_size.width, window_size.height, 0);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}

		void Clear() {
			///Rendering
			SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // RGBA cor de fundo
			SDL_RenderClear(renderer); // limpa a tela
		}

		void Render(){
			SDL_RenderPresent(renderer); // "apresenta" a tela
		}
};

class GameObject
{
	public:
		VectorColor color;
		VectorPosition position;

		GameObject () {
			position = {0,0};
			color = {0,0,0};
		}

		virtual void Render ( Window my_window ) {}	
};

class Engine {
	public:

		Window my_window;

		/*
		 * metodo que incializa o jogo
		 */
		virtual void Start () {}

		/*
		 * metodo que itera entre o jogo
		 */
		virtual void Update () {}

		/*
		 * metodo que renderiza os objetos
		 */
		virtual void Render () {}

		/*
		 * main
		 */
		void init()
		{
			// inicializa a biblioteca SDL
			if(SDL_Init(SDL_INIT_VIDEO) < 0)
				SDL_Log("Cant init %s", SDL_GetError());

			my_window.Open();

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

				my_window.Clear();

				Update();
				Render();

				my_window.Render();
			  	
			  	SDL_Delay(10); //Isso causa algo como 60 quadros por segundo.
			}
		}
};