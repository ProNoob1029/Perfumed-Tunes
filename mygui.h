#ifndef SPOTIFY_CLONE_MYGUI_H
#define SPOTIFY_CLONE_MYGUI_H
#include "raylib.h"
#include "song.h"
#include "vector"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void ConfigUI() {
    //GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(DARKGRAY));
    //GuiSetStyle(SLIDER, BORDER + 2*3, ColorToInt(RED));
}

typedef struct MusicPanel {
    int itemHeight = 100;
    Rectangle bounds = {0, 0, 300, 900};
    Rectangle content = {0, 0, 286, 0};
    Vector2 scroll = {};
    Rectangle view = {};
    void Draw(std::vector<Song> &songs) {
        content.height = (float)(songs.size() * itemHeight);

        GuiScrollPanel(bounds, nullptr, content, &scroll, &view);

        BeginScissorMode((int)view.x, (int)view.y, (int)view.width, (int)view.height);

        for (int i = 0; i < songs.size(); i++) {
            DrawText(songs[i].title, (int)(74 + view.x + scroll.x), (int)(20 + view.y + scroll.y + (float)(i * itemHeight)), 20, BLACK);
            DrawTextureEx(songs[i].cover, {view.x + scroll.x, view.y + scroll.y + (float)(i * itemHeight)}, 0.0f, 64.0f / (float)std::max(songs[i].cover.height, songs[i].cover.width), WHITE);
        }

        EndScissorMode();
    }
} MusicPanel;

#endif
