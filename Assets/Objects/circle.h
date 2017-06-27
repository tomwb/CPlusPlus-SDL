class Circle: public GameObject
{
	public:
		int radius;

		Circle () {
			radius = 50;
		}

		void Render ( Window my_window ) {
			SDL_SetRenderDrawColor(my_window.renderer, color.r, color.g, color.b, 255);
		    for (int w = 0; w < radius * 2; w++)
		    {
		        for (int h = 0; h < radius * 2; h++)
		        {
		            int dx = radius - w; // horizontal offset
		            int dy = radius - h; // vertical offset
		            if ((dx*dx + dy*dy) <= (radius * radius))
		            {
		                SDL_RenderDrawPoint(my_window.renderer, position.x + dx, position.y + dy);
		            }
		        }
		    }
		}
	
};