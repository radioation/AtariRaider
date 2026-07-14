#include <atari.h>
#include <string.h>
#include <stdint.h>
#include <peekpoke.h>
#include <conio.h>

#include "pmg.h"

#define PADDL0_ADDR 624
#define PADDL1_ADDR 625
#define PADDL2_ADDR 626
#define PADDL3_ADDR 627
#define CH_ADDR     764

#define MAX_PADDLE  180

#define PM_X_MIN    48
#define PM_X_MAX    208

#define PM_Y_MIN    32
#define PM_Y_MAX    223

static uint8_t *player0;
static uint8_t *player1;


static uint8_t clamp_paddle(uint8_t v)
{
    return (v > MAX_PADDLE) ? MAX_PADDLE : v;
}

static uint8_t map_paddle_to_hpos(uint8_t p)
{
    p = clamp_paddle(p);

    return (uint8_t)(PM_X_MIN + (((uint16_t)p * (PM_X_MAX - PM_X_MIN)) / MAX_PADDLE));
}

static uint8_t map_paddle_to_y(uint8_t p)
{
      uint16_t v;

    p = clamp_paddle(p);

    v = PM_Y_MAX - (((uint16_t)p * (PM_Y_MAX - PM_Y_MIN)) / MAX_PADDLE);

    return (uint8_t)v;
}

static void erase_dot(uint8_t* player, uint8_t y)
{
    player[y - 2] = 0x00;
    player[y - 1] = 0x00;
    player[y]     = 0x00;
    player[y + 1] = 0x00;
    player[y + 2] = 0x00;
}

static void draw_dot(uint8_t* player, uint8_t y)
{
    player[y - 2] = 0x18;
    player[y - 1] = 0x18;
    player[y]     = 0x7E;
    player[y + 1] = 0x18;
    player[y + 2] = 0x18;
}

int main(void)
{
    uint16_t p = (uint16_t)pmgMem;

    uint8_t p1x;
    uint8_t p1y;
    uint8_t x1;
    uint8_t y1;
    uint8_t old_y1;
    uint8_t p2x;
    uint8_t p2y;
    uint8_t x2;
    uint8_t y2;
    uint8_t old_y2;

    clrscr();

    ANTIC.pmbase = p >> 8;
    memset(pmgMem, 0, 2048);

    OS.sdmctl = 62; // single line PM

    GTIA_WRITE.gractl = 0x03;
    GTIA_WRITE.sizep0 = 0x00;

    OS.color1 = 0x0F; // text
    OS.color2 = 0x00; // bg
    OS.color4 = 0x00;
    OS.gprior = 1;
    OS.pcolr0 = 0x47;
    OS.pcolr1 = 0x87;

    player0 = pmgMem + 1024;// In single-line PM mode, player 0 starts at PM base + 1024.
    player1 = pmgMem + 1280;// player 1 starts at PM base + 1280.


    POKE(CH_ADDR, 255);

    gotoxy(0,0);
    cprintf("A8 Raider Stick Test");

    while (1) {
      // paddles
        p1x = PEEK(PADDL0_ADDR);
        p1y = PEEK(PADDL1_ADDR);
        p2x = PEEK(PADDL2_ADDR);
        p2y = PEEK(PADDL3_ADDR);

        x1 = map_paddle_to_hpos(p1x);
        y1 = map_paddle_to_y(p1y);
        x2 = map_paddle_to_hpos(p2x);
        y2 = map_paddle_to_y(p2y);


        erase_dot(player0, old_y1);
        draw_dot(player0, y1);
        old_y1 = y1;

        erase_dot(player1, old_y2);
        draw_dot(player1, y2);
        old_y2 = y2;

        GTIA_WRITE.hposp0 = x1;
        GTIA_WRITE.hposp1 = x2;
        gotoxy( 0, 20);
        cprintf( "X1:%3u Y1:%3u", x1, y1);
        gotoxy( 26, 20);
        cprintf( "X2:%3u Y2:%3u", x2, y2);

        // sticks
        gotoxy( 9,10 );
        cputc('U');
        gotoxy( 9,14 );
        cputc('D');
        gotoxy( 7,12 );
        cputc('L');
        gotoxy( 11,12 );
        cputc('R');
        gotoxy( 13,10 );
        cputc('F'+128);
        // sticks
        gotoxy( 29,10 );
        cputc('U');
        gotoxy( 29,14 );
        cputc('D');
        gotoxy( 27,12 );
        cputc('L');
        gotoxy( 31,12 );
        cputc('R');
        gotoxy( 33,10 );
        cputc('F'+128);
    }

    // nevah!
    return 0;
}
