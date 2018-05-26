#include <SDL2/SDL.h>
#include "michal.h"
#include <stdio.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init(){; 
   bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { 
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false; 
    }
    else { ; 
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
        if( gWindow == NULL ) { 
             printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); 
        }
        else { 
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow ); 
            //Fill the surface white
            SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 0000, 0000, 0000 ) ); 
            //Update the surface 
            SDL_UpdateWindowSurface( gWindow ); 
            
        } 
    }
    return success;
}

bool LoadMedia(){
    bool success = true;

    gHelloWorld = SDL_LoadBMP("Res/kappa.bmp");
    if(gHelloWorld == NULL){
        cout<<"Unable to load image! SDL Error\n"<<SDL_GetError();
        success = false;
    }
        
   return success;
}

void close(){
    //Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(){

    if(!init()){
        cout<<"Cannot initialize"<<endl;
    }
    else{
        //Loadmedia
        if(!LoadMedia()){
            cout<<"Cannot load Media"<<endl;
        }
        else{
            //Image 
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            SDL_UpdateWindowSurface( gWindow );
            SDL_Delay(5000);
        }
    }
    close();
        
    return 0;
}