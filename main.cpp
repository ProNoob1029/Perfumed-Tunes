#include <cstdlib>
#include "raylib.h"
#include "vector"
#include "id3v2lib-2.0/id3v2lib.h"
#include "cstring"
#include "raygui.h"

int main() {
    InitWindow(800, 800, "spotify-clone");

    InitAudioDevice();

    SetTargetFPS(60);

    bool showCover = false;
    Texture coverTexture;
    char title[128] = "";

    std::vector<Music> musicList;

    float musicProgress = 0;
    float musicLenght = 0;

    while (!WindowShouldClose()) {
        if (IsFileDropped())
        {
            FilePathList droppedFiles = LoadDroppedFiles();

            Music newMusic = LoadMusicStream(droppedFiles.paths[0]);
            newMusic.looping = false;
            PlayMusicStream(newMusic);
            musicList.push_back(newMusic);

            musicLenght = GetMusicTimeLength(musicList[0]);

            ID3v2_Tag *tag = ID3v2_read_tag(droppedFiles.paths[0]);

            ID3v2_ApicFrame *cover = ID3v2_Tag_get_album_cover_frame(tag);

            if (cover != nullptr) {
                Image coverImage = LoadImageFromMemory(".jpeg", reinterpret_cast<const unsigned char *>(cover->data->data), cover->data->picture_size);
                coverTexture = LoadTextureFromImage(coverImage);
                UnloadImage(coverImage);
                showCover = true;
            }

            ID3v2_TextFrame *tagTitle = ID3v2_Tag_get_title_frame(tag);

            if (tagTitle != nullptr) {
                strcpy(title, tagTitle->data->text);
            }

            free(tag);

            UnloadDroppedFiles(droppedFiles);
        }

        if (IsKeyPressed(KEY_C)) {
            while (!musicList.empty()) {
                UnloadMusicStream(musicList.back());
                musicList.pop_back();
            }
        }

        for (int i = 0; i < musicList.size(); i++) {
            if (IsMusicStreamPlaying(musicList[i])) {
                if (i == 0) {
                    UpdateMusicStream(musicList[0]);
                    musicProgress = GetMusicTimePlayed(musicList[0]);
                } else {
                    UpdateMusicStream(musicList[i]);
                }
            } else {
                UnloadMusicStream(musicList[i]);
                musicList.erase(musicList.begin() + i);
            }
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);

            DrawText(title, 0, 50, 30, BLACK);

            if (!musicList.empty()) {
                float aux = musicProgress;
                GuiSliderBar(Rectangle{100, 50, 500, 50}, "left", "right", &musicProgress, 0, musicLenght);
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditionsOC"
                if (aux != musicProgress) {
                    SeekMusicStream(musicList[0], musicProgress);
                }
#pragma clang diagnostic pop
            }

            if (showCover) {
                DrawTexture(coverTexture, 0, 150, WHITE);
            }

            DrawFPS(0, 0);
        EndDrawing();
    }

    for (auto music : musicList) {
        UnloadMusicStream(music);
    }

    CloseWindow();

    return 0;
}