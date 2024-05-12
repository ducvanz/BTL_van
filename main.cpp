#include"mylib.h"
using namespace std;

int main(int argc, char* argv[]) {
    if(mo_sdl()==1){
        cout<<"mo sdl khong thanh cong";
        return 1;
    }

    if(load_back()==1)
    {
        cout<<"mo background khong thanh cong";
        return 1;
    }

    // Load hình ảnh của quả sầu riêng
    pineappleTexture = loadTexture(qua);
    k_tr();
    // Load than ran
    thanTexture = loadTexture(than_ran);
    k_tr();
    // Ve background len cua so
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

    //khoi tao ban dau cho game
    khoi_tao_first();
    // Vong lap thoat game
    bool validDirection = true;

    int tm=0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                di_chuyen();
            }
        }
        // Giải phóng texture đầu rắn cũ
        SDL_DestroyTexture(headTexture);

        // Load hình ảnh đầu rắn mới
        headTexture=loadTexture(image_head);
        k_tr();

        int scoreO = score;
        bool wallCollision = testWallCollision();
        bool selfCollision = testSelfCollision();
        if (!validDirection || !wallCollision || !selfCollision) {
            cout << "Game over!\n";
            break;
        }

        bong_nho();

        if (count == 5) {
            test = true;
            bigBall = randomBigBall();
            count = 0;
        }
        if(test) tm++;
        if (tm >= 50) {
            test = false;
            tm = 0;
        }
        bong_lon(tm);

        int stepX = 0, stepY = 0;
        nhay(stepX,stepY);

        cap_nhat_vi_tri(stepX,stepY);

        draw(snake[0].x, snake[0].y);
        SDL_Delay(100);
        if (scoreO != score) cout << score << endl;
    }

    ket_thuc();
    return 0;
}


