#ifndef KHOITAO_H_INCLUDED
#define KHOITAO_H_INCLUDED
#include <iostream>
#include <vector>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
string image_head="head_right.png";
string qua="saurieng.png";
string than_ran="than_ran.png";
// Diem cua nguoi choi
int score = 0;

// Cac hang so
const int r = 12;
const int p = 2 * r;
const int step = 20;
const int width = 800;
const int height = 600;

bool test = true;
// Khai bao SDL
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// Background
const char* image = "background.png";
SDL_Texture* backgroundTexture = NULL;

// Texture cho đầu rắn
SDL_Texture* headTexture = NULL;
// Texture cho thân rắn
SDL_Texture* thanTexture = NULL;
// Texture cho quả sầu riêng
SDL_Texture* pineappleTexture = NULL;

// Toa do ran, qua bong
struct Circle {
    int x, y;
};

// Dot cua con ran
vector<Circle> snake;

// Qua bong nho
Circle ball;

// Qua bong lon
Circle bigBall;

// cac bien trong ham main
    SDL_Event e;//
    char direction = 'r'; //huong di chuyen
    bool quit = false;// thoat sdl
    int count = 0;//dem so lan an bong

#endif // KHOITAO_H_INCLUDED
