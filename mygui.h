#ifndef SPOTIFY_CLONE_MYGUI_H
#define SPOTIFY_CLONE_MYGUI_H
#include "raylib.h"
#include "song.h"
#include "vector"
#include "set"
#define RAYGUI_IMPLEMENTATION   //DO NOT DELETE
#include "raygui.h"

void ConfigUI() {
    //GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(DARKGRAY));
    //GuiSetStyle(SLIDER, BORDER + 2*3, ColorToInt(RED));
}

void DrawSong(const Song &song, int x, int y) {
    DrawText(song.title.c_str(), 110 + x, 20 + y, 20, BLACK);
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
    void Draw(std::set<Song> &songs, std::queue<Song> &songQueue) {
        content.height = float(songs.size() * itemHeight);

        GuiScrollPanel(bounds, nullptr, content, &scroll, &view);

        BeginScissorMode((int)view.x, (int)view.y, (int)view.width, (int)view.height);

        Vector2 mousePoint = GetMousePosition();

        int i = 0;
        for (auto &song : songs) {
            Rectangle itemRec = {view.x + scroll.x, view.y + scroll.y + float(i * itemHeight), content.width, (float)itemHeight};
            DrawSong(song, (int)itemRec.x, (int)itemRec.y);

            if (CheckCollisionPointRec(mousePoint, itemRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                //std::queue<Song> empty;
                //empty.push(song);
                if (songQueue.empty()) {
                    SeekMusicStream(song.music, 0.0f);
                    PlayMusicStream(song.music);
                }
                songQueue.push(song);
                //songQueue = empty;
            }
            i++;
        }

        EndScissorMode();
    }
} MusicPanel;

#endif //SPOTIFY_CLONE_MYGUI_H
