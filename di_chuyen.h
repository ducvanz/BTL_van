#ifndef DI_CHUYEN_H_INCLUDED
#define DI_CHUYEN_H_INCLUDED
void di_chuyen()
{
    switch (e.key.keysym.sym) {
        case SDLK_LEFT:
            image_head = "head_left.png";
            if (direction != 'r') direction = 'l';
        break;
        case SDLK_RIGHT:
            if (direction != 'l') direction = 'r';
            image_head = "head_right.png";
        break;
        case SDLK_UP:
             if (direction != 'd') direction = 'u';
             image_head = "head_up.png";
        break;
        case SDLK_DOWN:
             image_head = "head_down.png";
            if (direction != 'u') direction = 'd';
            break;
        }
}

void nhay(int &stepX,int &stepY)
{
        switch (direction) {
        case 'r':
            stepX = step;
            break;
        case 'l':
            stepX = -step;
            break;
        case 'u':
            stepY = -step;
            break;
        case 'd':
            stepY = step;
            break;
        }
}
void cap_nhat_vi_tri(int stepX,int stepY)
{
            for (int i = snake.size() - 1; i >= 1; i--) {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }

        snake[0].x += stepX;
        snake[0].y += stepY;
}
#endif // DI_CHUYEN_H_INCLUDED
