#ifndef SPOTIFY_CLONE_MYGUI_H
#define SPOTIFY_CLONE_MYGUI_H
#include "raylib.h"
#include "song.h"
#include "vector"
#include "set"
#define RAYGUI_IMPLEMENTATION   //DO NOT DELETE
#include "raygui.h"

void ConfigUI(Color background) {
    GuiSetStyle(SLIDER, BORDER_WIDTH, 0);
    GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);

    Color sliderBg = {49, 37, 61, 255};


    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(background));
    GuiSetStyle(SLIDER, BASE_COLOR_NORMAL, ColorToInt(sliderBg));
    GuiSetStyle(SLIDER, BASE_COLOR_PRESSED, ColorToInt({220, 202, 233, 255}));
    GuiSetStyle(SLIDER, TEXT_COLOR_FOCUSED, ColorToInt({157, 114, 194, 255}));
    GuiSetStyle(SLIDER, TEXT_COLOR_PRESSED, ColorToInt({146, 78, 191, 255}));
}

void DrawSong(const Song &song, int x, int y) {
    DrawText(song.title.c_str(), 110 + x, 20 + y, 20, WHITE);
    if (song.hasCover) {
        DrawTextureEx(song.cover, {(float) x, (float) y}, 0.0f, 100.0f / (float)std::max(song.cover.height, song.cover.width), WHITE);
    }

    // Check button state

}

typedef struct MusicPanel {
    int itemHeight = 100;
    Rectangle bounds = {0, 0, 640, 720};
    Rectangle content = {0, 0, bounds.width - 14, 0};
    Vector2 scroll = {};
    Rectangle view = {};
    void Draw(std::set<Song> &songs, std::queue<Song> &songQueue, Vector2 &mousePoint) {
        content.height = float(songs.size() * itemHeight);

        GuiScrollPanel(bounds, nullptr, content, &scroll, &view);

        BeginScissorMode((int)view.x, (int)view.y, (int)view.width, (int)view.height);



        int i = 0;
        for (auto &song : songs) {
            Rectangle itemRec = {view.x + scroll.x, view.y + scroll.y + float(i * itemHeight), content.width, (float)itemHeight};
            DrawSong(song, (int)itemRec.x, (int)itemRec.y);

            if (CheckCollisionPointRec(mousePoint, itemRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                songQueue.push(song);
            }
            i++;
        }

        EndScissorMode();
    }
} MusicPanel;

#endif //SPOTIFY_CLONE_MYGUI_H
