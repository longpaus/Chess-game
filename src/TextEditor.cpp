#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <utility>
#include "Text_editor/TextEditor.h"

// Constructor
//TextEditor::TextEditor(std::string file)
//        : window(nullptr), renderer(nullptr), windowWidth(800), windowHeight(600), curr_open_file(std::move(file), running(true), font(
//        nullptr)) {
//
//}
TextEditor::TextEditor(std::string file)
        : window(nullptr), renderer(nullptr), font(nullptr), windowWidth(800), windowHeight(600), curr_open_file(std::move(file)) {
}


TextEditor::~TextEditor() {
        close();
}

bool TextEditor::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Text editor",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          windowWidth, windowHeight,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

//    if(TTF_Init() != 0) {
//        std::cerr << "Failed to start ttf engine" << TTF_GetError() << std::endl;
//        SDL_Quit();
//        return false;
//    }
//
//    TTF_Font *font = TTF_OpenFont("assets/font/OpenSans-Regular.ttf",20);
//
//    if(font == nullptr) {
//        std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        TTF_Quit();
//        SDL_Quit();
//        return false;
//    }
//
//    // Create a surface with the text
//    SDL_Color color = {255, 255, 255, 255};
//    SDL_Surface *surf = TTF_RenderText_Blended(font, "Hello, SDL2_ttf!", color);
//    if (surf == nullptr) {
//        TTF_CloseFont(font);
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        std::cerr << "TTF_RenderText Error: " << TTF_GetError() << std::endl;
//        TTF_Quit();
//        SDL_Quit();
//        return 1;
//    }
    return true;
}



void TextEditor::run() {

//    while (running) {
//        processInput();
//        update();
//        render();
//    }
    std::cout << "hello world!";
}


void TextEditor::close() {
    if(renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if(window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

void TextEditor::render() {
   ;

}

void TextEditor::update() {

}

void TextEditor::processInput() {
    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
            break;
        }
    }

}
