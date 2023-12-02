#include "raylib.h"
#include "mygui.h"
#include "song.h"

int main() {
    InitWindow(1600, 900, "spotify-clone");
    InitAudioDevice();
    SetTargetFPS(60);

    ConfigUI();

    MusicPanel musicPanel;

    std::queue<char*> songPaths;
    std::vector<Song> songs;

    while (!WindowShouldClose()) {
        if (IsFileDropped()) {
            FilePathList droppedFiles = LoadDroppedFiles();
            for (int i = 0; i < droppedFiles.count; i++) {
                GetSongFilePaths(songPaths, droppedFiles.paths[i]);
            }
            UnloadDroppedFiles(droppedFiles);
        }

        if (!songPaths.empty()) {
            songs.push_back(LoadSong(songPaths.front()));
            songPaths.pop();
        }

        BeginDrawing();

        ClearBackground(WHITE);

        musicPanel.Draw(songs);

        DrawFPS(0,0);

        EndDrawing();
    }

    CloseWindow();
}

/*
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

            DrawText(title, 0, 50, 30, BLACK);

            {
                float aux = musicProgress;
                GuiSliderBar(Rectangle{100, 100, 500, 50}, "left", "right", &musicProgress, 0, musicLenght);
                if (aux != musicProgress && !musicList.empty()) {
                    SeekMusicStream(musicList[0], musicProgress);
                }
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
}*/
