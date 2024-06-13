//
// Created by Hoang Long Pham on 5/6/2024.
//

#ifndef TEXT_EDITOR_TEXTEDITOR_H
#define TEXT_EDITOR_TEXTEDITOR_H

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
class TextEditor {
public:
    TextEditor(std::string file);
    ~TextEditor();
    bool init();
    void run();
    void processInput();
    void update();
    void render();
    void close();

private:
    std::string curr_open_file;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<std::string> lines;
    int windowWidth;
    int windowHeight;
    bool running;
    TTF_Font *font;
};


#endif //TEXT_EDITOR_TEXTEDITOR_H
