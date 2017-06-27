class Square: public GameObject
{
	public:
		VectorSize size;

		Square () {
			size = {100,100};
		}

		void Render ( Window my_window ) {
			SDL_SetRenderDrawColor(my_window.renderer, color.r, color.g, color.b, 255);
			SDL_Rect obj = {position.x, position.y, size.width, size.height};
			SDL_RenderFillRect(my_window.renderer, &obj);

			SDL_Point center = {255,255};
		}
	
};