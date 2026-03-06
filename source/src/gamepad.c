#include <gamepad.h>
#include <string.h>

typedef struct {
    bool button_sel;
    bool dir_sel;
    gamepad_state controller;
} gamepad_context;

static gamepad_context ctx = {0};

bool gamepad_button_sel() {
    return ctx.button_sel;
}

bool gamepad_dir_sel() {
    return ctx.dir_sel;
}

void gamepad_set_sel(u8 value) {
    ctx.button_sel = value & 0x20;
    ctx.dir_sel = value & 0x10;
}

gamepad_state *gamepad_get_state() {
    return &ctx.controller;
}

u8 gamepad_get_output() {
    u8 output = 0xFF;
    if (ctx.button_sel) output |= 0x20; else output &= ~0x20;
    if (ctx.dir_sel)    output |= 0x10; else output &= ~0x10;
    if (!ctx.button_sel) {
        if (ctx.controller.start)  output &= ~(1 << 3);
        if (ctx.controller.select) output &= ~(1 << 2);
        if (ctx.controller.b)      output &= ~(1 << 1);
        if (ctx.controller.a)      output &= ~(1 << 0);
    }
    if (!ctx.dir_sel) {
        if (ctx.controller.down)  output &= ~(1 << 3);
        if (ctx.controller.up)    output &= ~(1 << 2);
        if (ctx.controller.left)  output &= ~(1 << 1);
        if (ctx.controller.right) output &= ~(1 << 0);
    }

    return output;
}