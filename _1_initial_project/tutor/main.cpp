#include <SDL.h>
#undef main
#include <GL/glew.h>
#include <vector>
#include <memory>

SDL_Window *mainwindow; /* Our window handle */
SDL_GLContext maincontext;

struct GLWindowParams
{
	int gl_major_version; // 3
	int gl_minor_version; // 3
	int gl_doublebuffer; // 1
	int gl_depth_size; // 24

	GLWindowParams(int t_gl_major_ver, int t_gl_minor_version, int t_gl_db, int t_gl_depth_size)
	{
		gl_major_version = t_gl_major_ver;
		gl_minor_version = t_gl_minor_version;
		gl_doublebuffer = t_gl_db;
		gl_depth_size = t_gl_depth_size;
	}
};

struct WindowParam
{
	char* caption;
	int w;
	int h;

	WindowParam(char* t_caption, int t_w, int t_h)
	{
		caption = t_caption;
		w = t_w;
		h = t_h;
	}
};

bool CreateWindow(GLWindowParams t_gl_params, WindowParam t_param)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
	{
		//sdldie("Unable to initialize SDL"); /* Or die on error */
		//printf("%s: %s\n", msg, SDL_GetError());
		SDL_Quit();
		return false;
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, t_gl_params.gl_major_version);//3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, t_gl_params.gl_minor_version);//3);

	/* Turn on double buffering with a 24bit Z buffer.
	 * You may need to change this to 16 or 32 for your system */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, t_gl_params.gl_doublebuffer);//1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, t_gl_params.gl_depth_size);//24);

	/* Create our window centered at 512x512 resolution */
	mainwindow = SDL_CreateWindow(t_param.caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		t_param.w, t_param.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	/* Create our opengl context and attach it to our window */
	maincontext = SDL_GL_CreateContext(mainwindow);

	/* This makes our buffer swap syncronized with the monitor's vertical refresh */
	SDL_GL_SetSwapInterval(1);
	//-----------------------------------------------------------
	//INIT GLEW
	//------------------------------------------------------------
	glewInit();
	//------------------------------------------------------------
	return true;
}

void DestroyWindow()
{
	SDL_GL_DeleteContext(maincontext);
	SDL_DestroyWindow(mainwindow);
	SDL_Quit();
}

void SwapBuffers()
{
	SDL_GL_SwapWindow(mainwindow);
}

void main()
{
	bool m_isQute = true; 
	
	CreateWindow(GLWindowParams(3, 3, 1, 24), WindowParam("OBJviewer", 512, 512));
	
	//-----------------------------------------------------------
	while (m_isQute)
	{
		SDL_Event event;
		/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
		/* more events on the event queue, our while loop will exit when */
		/* that occurs.                                                  */
		while( SDL_PollEvent( &event ) )
		{
			if (event.key.type == SDL_QUIT)
				m_isQute = false;
		}
		
		SwapBuffers();
		
	}
	//-----------------------------------------------------------

	DestroyWindow();
}