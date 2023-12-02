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

void DrawSong(Song &song, int x, int y) {
    DrawText(song.title, 110 + x, 20 + y, 20, BLACK);
    DrawTextureEx(song.cover, {(float) x, (float) y}, 0.0f, 100.0f / (float)std::max(song.cover.height, song.cover.width), WHITE);
}

typedef struct MusicPanel {
    int itemHeight = 100;
    Rectangle bounds = {0, 0, 700, 900};
    Rectangle content = {0, 0, bounds.width - 14, 0};
    Vector2 scroll = {};
    Rectangle view = {};
    void Draw(std::vector<Song> &songs) {
        content.height = float(songs.size() * itemHeight);

        GuiScrollPanel(bounds, nullptr, content, &scroll, &view);

        BeginScissorMode((int)view.x, (int)view.y, (int)view.width, (int)view.height);

        for (int i = 0; i < songs.size(); i++) {
            DrawSong(songs[i], int(view.x + scroll.x), int(view.y + scroll.y + float(i * itemHeight)));
        }

        EndScissorMode();
    }
} MusicPanel;

#endif
