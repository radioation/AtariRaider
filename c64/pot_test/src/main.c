#include <c64.h>
#include <conio.h>
#include <stdint.h>
#include <peekpoke.h>

#define SID_POTX_ADDR 0xD419
#define SID_POTY_ADDR 0xD41A

#define SCREEN_WIDTH   40
#define SCREEN_HEIGHT  25

#define DOT_X_MIN       1
#define DOT_X_MAX      38
#define DOT_Y_MIN       2
#define DOT_Y_MAX      23

static uint8_t map_paddle(
    uint8_t value,
    uint8_t min_value,
    uint8_t max_value)
{
    uint16_t range;

    range = max_value - min_value;

    return min_value +
        (uint8_t)(((uint16_t)value * range) / 255);
}

static void draw_dot(uint8_t x, uint8_t y)
{
    gotoxy(x, y);
    cputc('*');
}

static void erase_dot(uint8_t x, uint8_t y)
{
    gotoxy(x, y);
    cputc(' ');
}

int main(void)
{
    uint8_t pot_x;
    uint8_t pot_y;

    uint8_t x;
    uint8_t y;

    uint8_t old_x = 0;
    uint8_t old_y = 0;
    uint8_t old_valid = 0;

    clrscr();

    bordercolor(COLOR_BLACK);
    bgcolor(COLOR_BLACK);
    textcolor(COLOR_WHITE);

    gotoxy(0, 0);
    cprintf("C64 RAIDER STICK TEST");

    while (1) {
         // SID paddle registers.
         // POTX = $D419
         // POTY = $D41A
        pot_x = PEEK(SID_POTX_ADDR);
        pot_y = PEEK(SID_POTY_ADDR);

        x = map_paddle(
            pot_x,
            DOT_X_MIN,
            DOT_X_MAX);

        y = DOT_Y_MAX - map_paddle(
            pot_y,
            0,
            DOT_Y_MAX - DOT_Y_MIN);

        if (!old_valid || x != old_x || y != old_y) {
            if (old_valid) {
                erase_dot(old_x, old_y);
            }

            draw_dot(x, y);

            old_x = x;
            old_y = y;
            old_valid = 1;
        }

        // print out paddle readings.
        gotoxy(0, 24);
        cprintf( "X:%3u Y:%3u", pot_x, pot_y);
    }

    return 0;
}
