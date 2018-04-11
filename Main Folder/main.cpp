#include "oop.hpp"
#include "Akuarium.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>

const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    double err_msg_tick = 0;
    bool show_not_enough_money = false;
    std::string fps_text = "FPS: 0";
    //int cursor_x, cursor_y;
    bool running = true;
    double prevtime = time_since_start();
    int menu_state = 0;
    //0 = main menu
    //1 = ingame.

    Akuarium akuarium(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    List<Coin> * coin = akuarium.getCList();
    List<Guppy> * guppy = akuarium.getGList();
    List<Piranha> * piranha = akuarium.getPList();
    List<Makanan> * makanan = akuarium.getMList();
 
    akuarium.AddToAkuarium(new Guppy(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT));
    while (running) {
        if(menu_state == 0)
        {
            clear_screen();
            draw_image("resources/bg.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            handle_input();
            if (quit_pressed()) {
                running = false;
            }
            int cursor_x,cursor_y;
            const int button_x = SCREEN_WIDTH/2;
            const int start_button_y = SCREEN_HEIGHT/2 - 100;
            const int quit_button_y = SCREEN_HEIGHT/2 + 100;

            draw_image("resources/start_button.png", button_x, start_button_y);
            draw_image("resources/quit_button.png", button_x, quit_button_y);
            
            SDL_GetMouseState(&cursor_x, &cursor_y);
            for(auto button : get_tapped_buttons())
            {
                switch(button) 
                {
                    case SDL_BUTTON_LEFT:
                        if(abs(cursor_x - button_x) < 120 && abs(cursor_y - start_button_y) < 60)
                        {
                            menu_state = 1;
                        } else if(abs(cursor_x - button_x) < 120 && abs(cursor_y - quit_button_y) < 60)
                        {
                            running = false;
                        }
                        break;
                }
            }
            update_screen();
        } else
        {
            double now = time_since_start();
            double sec_since_last = now - prevtime;
            prevtime = now;

            handle_input();
            if (quit_pressed()) {
                running = false;
            }
            int cursor_x,cursor_y;
            SDL_GetMouseState(&cursor_x, &cursor_y);
            for(auto button : get_tapped_buttons())
            {
                switch(button) 
                {
                    case SDL_BUTTON_LEFT:
                        bool found = false;
                        for(int i = 0 ; (*coin).getAddr(i) != nullptr && !found; i++)
                        {
                            if(abs((*((*coin).getDataAddr(i))).getX() - cursor_x) < 20 && abs((*((*coin).getDataAddr(i))).getY() - cursor_y) < 20)
                            {
                                Coin * temp = (*coin).getDataAddr(i);
                                akuarium.setMoney(akuarium.getMoney() + (*temp).getValue());
                                (*coin).remove(*temp);
                                delete temp;
                                found = true;
                            }
                        }
                        if(!found)
                        if(akuarium.getMoney() >= 5)
                        {
                            akuarium.AddToAkuarium(new Makanan(cursor_x,0,SCREEN_HEIGHT,SCREEN_WIDTH));
                            akuarium.setMoney(akuarium.getMoney()-5);
                        }
                        else
                        {
                            show_not_enough_money = true;
                            err_msg_tick = 0;
                        }
                        break;
                }
            }
            

            // Proses masukan yang bersifat "tombol"
            for (auto key : get_tapped_keys()) {
                switch (key) {
                // g untuk spawn guppy
                case SDLK_g:
                    if(akuarium.getMoney() >= 100)
                    {
                        akuarium.AddToAkuarium(new Guppy(rand()%SCREEN_WIDTH,rand()%SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT));
                        akuarium.setMoney(akuarium.getMoney()-100);
                    } else
                    {
                        show_not_enough_money = true;
                        err_msg_tick = 0;
                    }
                    break;
                case SDLK_p:
                    if(akuarium.getMoney() >= 200)
                    {
                        akuarium.AddToAkuarium(new Piranha(rand()%SCREEN_WIDTH,rand()%SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT));
                        akuarium.setMoney(akuarium.getMoney()-200);
                    } else
                    {
                        show_not_enough_money = true;
                        err_msg_tick = 0;
                    }
                    break;
                case SDLK_m:
                    break;
                // x untuk keluar
                case SDLK_x:
                    running = false;
                    break;
                }
            }
            // Update FPS setiap detik
            frames_passed++;
            if (now - fpc_start > 1) {
                std::ostringstream strs;
                strs << "FPS: " ;
                strs << frames_passed/(now - fpc_start);
                fps_text = strs.str();;
                fpc_start = now;
                frames_passed = 0;
            }

            // Gambar ikan di posisi yang tepat.
            clear_screen();
            draw_image("resources/bg.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            //draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
            draw_text(fps_text, 10, 10, 30, 0, 0, 0);
            
            akuarium.update(sec_since_last);
            std::ostringstream stro;
            stro << "Money: " << akuarium.getMoney();
            draw_text(stro.str(), 14, SCREEN_WIDTH-200, 30, 0, 0, 0);
            if(show_not_enough_money && err_msg_tick < 5)
            {
                draw_text("Not Enough Money", 22, SCREEN_WIDTH/2-100, SCREEN_HEIGHT/4, 255, 0, 0);
                err_msg_tick += sec_since_last;
            } else if (err_msg_tick >= 5)
            {
                show_not_enough_money = false;
            }

            if((*(akuarium.getSnail())).getDirection() == 'L')
            {
                draw_image("resources/Pic/Snail/Turn/Snail1.png", (*(akuarium.getSnail())).getX(),(*(akuarium.getSnail())).getY()-50);
            } else
            {
                draw_image("resources/Pic/Snail/Turn/Snail10.png", (*(akuarium.getSnail())).getX(),(*(akuarium.getSnail())).getY()-50);
            }
            
            for(int i = 0 ; (*guppy).getAddr(i) != nullptr ; i++)
            {
                if((*guppy).get(i).getDirection() == 'L')
                {
                    if((*guppy).get(i).getGrowthStage() == 1)
                    draw_image("resources/Pic/Guppy/Guppy1_1.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
                    else if((*guppy).get(i).getGrowthStage() == 2)
                    draw_image("resources/Pic/Guppy/Guppy2_1.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
                    else if((*guppy).get(i).getGrowthStage() == 3)
                    draw_image("resources/Pic/Guppy/Guppy3_1.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
                } else
                {
                    if((*guppy).get(i).getGrowthStage() == 1)
                    draw_image("resources/Pic/Guppy/Guppy1_2.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
                    else if((*guppy).get(i).getGrowthStage() == 2)
                    draw_image("resources/Pic/Guppy/Guppy2_2.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
                    else if((*guppy).get(i).getGrowthStage() == 3)
                    draw_image("resources/Pic/Guppy/Guppy3_2.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
                }

            }

            for(int i = 0 ; (*piranha).getAddr(i) != nullptr ; i++)
            {
                if((*piranha).get(i).getDirection() == 'L')
                {
                    if((*piranha).get(i).getGrowthStage() == 1)
                    draw_image("resources/Pic/Piranha/Piranha1_1.png", (*piranha).get(i).getX(), (*piranha).get(i).getY());
                    else if((*piranha).get(i).getGrowthStage() == 2)
                    draw_image("resources/Pic/Piranha/Piranha2_1.png", (*piranha).get(i).getX(), (*piranha).get(i).getY());
                    else if((*piranha).get(i).getGrowthStage() == 3)
                    draw_image("resources/Pic/Piranha/Piranha3_1.png", (*piranha).get(i).getX(), (*piranha).get(i).getY());
                } else
                {
                    if((*piranha).get(i).getGrowthStage() == 1)
                    draw_image("resources/Pic/Piranha/Piranha1_2.png", (*piranha).get(i).getX(), (*piranha).get(i).getY());
                    else if((*piranha).get(i).getGrowthStage() == 2)
                    draw_image("resources/Pic/Piranha/Piranha2_2.png", (*piranha).get(i).getX(), (*piranha).get(i).getY());
                    else if((*piranha).get(i).getGrowthStage() == 3)
                    draw_image("resources/Pic/Piranha/Piranha3_2.png", (*piranha).get(i).getX(), (*piranha).get(i).getY());
                }

            }

            for(int i = 0 ; (*makanan).getAddr(i) != nullptr ; i++)
            {
                draw_image("resources/Pic/Food/Food2.png", (*makanan).get(i).getX(), (*makanan).get(i).getY());
            }

            for(int i = 0 ; (*coin).getAddr(i) != nullptr ; i++)
            {
                draw_image("resources/Pic/Coin Gold/Coin1.png", (*coin).get(i).getX(), (*coin).get(i).getY());
            }

            update_screen();
        }
    }
    close();

    return 0;
}
