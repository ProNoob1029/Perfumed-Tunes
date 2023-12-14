#ifndef SPOTIFY_CLONE_MYGUI_H //inceputul unui fisier
#define SPOTIFY_CLONE_MYGUI_H //inceputul unui fisier
#include "raylib.h"
#include "song.h"
#include "vector" //vector cu marime variabila
#include "set"
#define RAYGUI_IMPLEMENTATION   //DO NOT DELETE
#include "raygui.h"
#include "font.h"
#include "text.h"

//schimba culorile la layout
void ConfigUI(Color background) {
    GuiSetIconScale(2);

    GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);

    Color sliderBg = {49, 37, 61, 255};
    Color neutralSlider = {157, 114, 194, 255};
    Color focusedSlider = {220, 202, 233, 255};
    Color pressedSlider = {146, 78, 191, 255};

    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(background));
    GuiSetStyle(SLIDER, BASE_COLOR_NORMAL, ColorToInt(sliderBg));
    GuiSetStyle(SLIDER, BASE_COLOR_PRESSED, ColorToInt(neutralSlider));
    GuiSetStyle(SLIDER, TEXT_COLOR_FOCUSED, ColorToInt(focusedSlider));
    GuiSetStyle(SLIDER, TEXT_COLOR_PRESSED, ColorToInt(pressedSlider));

    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(sliderBg));

    GuiSetStyle(SLIDER, BORDER, ColorToInt(neutralSlider));
    GuiSetStyle(SLIDER, BORDER + 3, ColorToInt(focusedSlider));
    GuiSetStyle(SLIDER, BORDER + 6, ColorToInt(focusedSlider));

    GuiSetStyle(BUTTON, TEXT + 0, ColorToInt(neutralSlider));
    GuiSetStyle(BUTTON, TEXT + 3, ColorToInt(focusedSlider));
    GuiSetStyle(BUTTON, TEXT + 6, ColorToInt(pressedSlider));

    //GuiSetStyle(BUTTON, BASE + 0, );
    GuiSetStyle(BUTTON, BASE + 3, ColorToInt(pressedSlider));
    GuiSetStyle(BUTTON, BASE + 6, ColorToInt(focusedSlider));

    GuiSetStyle(BUTTON, BORDER + 0, ColorToInt(neutralSlider));
    GuiSetStyle(BUTTON, BORDER + 3, ColorToInt(focusedSlider));
    GuiSetStyle(BUTTON, BORDER + 6, ColorToInt(pressedSlider));
}


//deseneaza cover-ul si titlul
void DrawSong(const Song &song, Rectangle songBox) {
    Rectangle textBox = {songBox.x + 110, songBox.y + 15, songBox.width - 110, songBox.height - 20};
    BeginShaderMode(defaultShader);
    DrawTextBoxed(defaultFont, song.title.c_str(), textBox, 32, 0, true, WHITE);
    EndShaderMode();
    if (song.hasCover) {
        DrawTextureEx(song.cover, {(float) songBox.x, (float) songBox.y}, 0.0f, 100.0f / (float)std::max(song.cover.height, song.cover.width), WHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), songBox)) {
        DrawRectangle((int)songBox.x, (int)songBox.y, (int)songBox.width, (int)songBox.height, Color{255, 255, 255, 30});
    }
}

void ProgressBar(Rectangle pos, float &slider, Music musicPlaying) {
    Vector2 mousePoint = GetMousePosition();
    bool mouseOnSlider = CheckCollisionPointRec(mousePoint, pos);
    if (mouseOnSlider && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        SeekMusicStream(musicPlaying, slider * GetMusicTimeLength(musicPlaying));
    }
    if (!mouseOnSlider || IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
        slider = GetMusicTimePlayed(musicPlaying) / GetMusicTimeLength(musicPlaying);
    }
    GuiSliderBar(pos, nullptr, nullptr, &slider, 0.0f, 1.0f);
}

bool PlayButton(Rectangle pos, bool musicPlaying) {
    const char *buttonIcon = musicPlaying?
                             GuiIconText(ICON_PLAYER_PAUSE, nullptr)
                            : GuiIconText(ICON_PLAYER_PLAY, nullptr);
    return GuiButton(pos, buttonIcon);
}

//deseneaza lista de piese
typedef struct MusicPanel {
    int itemHeight = 100;
    Rectangle bounds = {0, 0, 320, 720};
    Rectangle content = {0, 0, bounds.width - 14, 0};
    Rectangle view = {};
    int Draw(std::vector<Song> &songs, Vector2 &scroll) {
        Vector2 mousePoint = GetMousePosition();
        int result = -1;

        content.height = float(songs.size() * itemHeight);
        content.width = bounds.width - 14;

        GuiScrollPanel(bounds, nullptr, content, &scroll, &view);

        BeginScissorMode((int)view.x, (int)view.y, (int)view.width, (int)view.height);

        int i = 0;
        for (auto &song : songs) {
            Rectangle itemRec = {view.x + scroll.x, view.y + scroll.y + float(i * itemHeight), content.width, (float)itemHeight};
            DrawSong(song, itemRec);

            if (CheckCollisionPointRec(mousePoint, itemRec) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))) {
                result = i;     //adauga in queue
            }
            i++;
        }

        EndScissorMode();
        return result;
    }
} MusicPanel;

#endif //SPOTIFY_CLONE_MYGUI_H
