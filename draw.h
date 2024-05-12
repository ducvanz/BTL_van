#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

// Ve lai sau moi thao tac
void draw(int x, int y) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Ve background
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    // Ve ran
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 1; i < snake.size(); ++i) {
        SDL_Rect destRect = { snake[i].x - r, snake[i].y - r, 2 * r, 2 * r };
        SDL_RenderCopy(renderer, thanTexture, NULL, &destRect);
    }

    // Ve qua bong nho
    SDL_Rect ballRect = { ball.x - r, ball.y - r, 2 * r, 2 * r };
    SDL_RenderCopy(renderer, pineappleTexture, NULL, &ballRect);

    // Ve qua bong lon
    if ((bigBall.x != 0 || bigBall.y != 0) && test) {
        SDL_Rect bigBallRect = { bigBall.x - p, bigBall.y - p, 2 * p, 2 * p };
        SDL_RenderCopy(renderer, pineappleTexture, NULL, &bigBallRect);
    }

    // Ve dau ran
    SDL_Rect headRect = { x - r, y - r, 2 * r , 2 * r  };
    SDL_RenderCopy(renderer, headTexture, NULL, &headRect);

    SDL_RenderPresent(renderer);
}

// Random vi tri qua bong
void placeBall() {
    srand(time(0));
    ball.x = rand() % (width - 2 * r) + r;
    ball.y = rand() % (height - 2 * r) + r;
}

// Random qua bong lon
Circle randomBigBall() {
    Circle bigball;
    srand(time(0));
    bigball.x = rand() % (width - 2 * p) + p;
    bigball.y = rand() % (height - 2 * p) + p;

    bool check = true;
    for (Circle c : snake) {
        if ((bigball.x >= c.x - r && bigball.x <= c.x + r) && (bigball.y >= c.y - r && bigball.y <= c.y + r)) {
            return randomBigBall();
        }
    }

    return bigball;
}

#endif // DRAW_H_INCLUDED
