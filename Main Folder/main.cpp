#include "oop.hpp"
#include "Akuarium.hpp"
#include "Snail.hpp"
#include "Mouse.hpp"
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
    std::string fps_text = "FPS: 0";
    //int cursor_x, cursor_y;
    bool running = true;
    double prevtime = time_since_start();

    Akuarium akuarium(SCREEN_WIDTH, SCREEN_HEIGHT);
    //Snail snail(SCREEN_WIDTH/2, SCREEN_WIDTH, SCREEN_HEIGHT);
    List<Coin> * coin = akuarium.getCList();
    List<Guppy> * guppy = akuarium.getGList();
    List<Piranha> * piranha = akuarium.getPList();
    List<Makanan> * makanan = akuarium.getMList();


    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        //SDL_GetMouseState(&cursor_x, &cursor_y);

        /*
        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }

        */
        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                akuarium.AddToAkuarium(new Guppy(100,100,800,600));
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
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        
        akuarium.update(sec_since_last);
        
        for(int i = 0 ; (*guppy).getAddr(i) != nullptr ; i++)
        {
            draw_image("resources/ikan.png", (*guppy).get(i).getX(), (*guppy).get(i).getY());
        }
        
		update_screen();
    }

    close();

    return 0;
}
