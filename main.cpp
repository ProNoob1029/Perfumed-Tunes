#include "raylib.h"
#include "mygui.h"
#include "song.h"
#include "set"

int main() {
    InitWindow(1280, 720, "spotify-clone"); //creeaza fereastra+ii da nume+size
    InitAudioDevice(); //"porneste castile"-se conecteaza la audio
    SetTargetFPS(60); //cat de rapid isi da update/ cat de rapid deseneaza/ viteza while/s

    //TODO: try sdf fonts

    ConfigUI(); //change colors of UI

    MusicPanel musicPanel;  //the music list on the left

    std::queue<std::string> songPaths;  //song filepaths queued for importing-fisierele sunt incarcate pe rand
    std::set<Song> songs; //o multime de piese
    std::queue<Song> songQueue; //
    float slider = 0.0f; //piesa incepe de la timpul 0.0

    while (!WindowShouldClose()) { // verifica daca ai inchis programul (true=> stop)
        if (IsFileDropped()) { //
            FilePathList droppedFiles = LoadDroppedFiles(); //
            for (int i = 0; i < droppedFiles.count; i++) {
                GetSongFilePaths(songPaths, droppedFiles.paths[i]);
            }
            UnloadDroppedFiles(droppedFiles);
        }

        if (!songPaths.empty()) {
            songs.insert(LoadSong(songPaths.front().c_str()));
            songPaths.pop();
        }

        for(const Song& song : songs) {
            Music music = song.music;
            if (IsMusicStreamPlaying(music)) {
                UpdateMusicStream(music);
                slider = GetMusicTimePlayed(music);
            }
        }

        if (!songQueue.empty() && !IsMusicStreamPlaying(songQueue.front().music)) {
            songQueue.pop();
        }

        if (IsKeyPressed(KEY_P) && !songQueue.empty()) {
            StopMusicStream(songQueue.front().music);
            songQueue.pop();
            if (!songQueue.empty()) {
                SeekMusicStream(songQueue.front().music, 0.0f);
                PlayMusicStream(songQueue.front().music);
            }
        }

        BeginDrawing();

        ClearBackground(WHITE);

        musicPanel.Draw(songs, songQueue);

        if (!songQueue.empty() && songQueue.front().hasCover) {
            DrawTexture(songQueue.front().cover, 640, 0, WHITE);
        }

        if (!songQueue.empty()) {
            Rectangle sliderRec = {640, 640, 640, 80};
            float temp = slider;
            GuiSliderBar(sliderRec, nullptr, nullptr, &slider, 0.0f, GetMusicTimeLength(songQueue.front().music));
            //ignore warning, slider can be changed by GuiSliderBar
            if (slider != temp) {
                SeekMusicStream(songQueue.front().music, slider);
            }
        }

        DrawFPS(0,0);

        EndDrawing();
    }

    for(const Song& song : songs) {
        UnloadSong(song);
    }

    CloseWindow();
}
