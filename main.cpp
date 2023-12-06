#include "raylib.h" //se ocupa de audio, video, imput
#include "mygui.h" //fisier in care sunt elemente de interfata
#include "song.h" //fisier in care sunt definite functiile unei piese
#include "set" //librarie pentru multimea cu piese
#include "font.h"

int main() {
    InitWindow(1280, 720, "spotify-clone"); //creeaza fereastra+ii da nume+size
    InitAudioDevice(); //"porneste castile"-se conecteaza la audio
    SetTargetFPS(60); //cat de rapid isi da update/ cat de rapid deseneaza/ viteza while/s

    LoadDefaultFont();

    Color background = {23, 15, 30, 255};
    ConfigUI(background); //change colors of UI

    MusicPanel musicPanel;  //the music list on the left

    std::queue<std::string> songPaths;  //song filepaths queued for importing-fisierele sunt incarcate pe rand
    std::set<Song> songs; //o multime de piese
    std::queue<Song> songQueue; //queue-ul incepe cu urmatoarea piesa
    Song songPlaying;
    float slider = 0.0f; //piesa incepe de la timpul 0.0

    while (!WindowShouldClose()) { // verifica daca ai inchis programul (true=> stop)
        Vector2 mousePoint = GetMousePosition(); //salveaza pozitia mouse-ului

        if (IsFileDropped()) { //verifica daca am adaugat fisierele
            FilePathList droppedFiles = LoadDroppedFiles(); //salveaza dropped files
            for (int i = 0; i < droppedFiles.count; i++) { //trecem peste dropped files
                GetSongFilePaths(songPaths, droppedFiles.paths[i]); //salvam ce MP3-uri am gasit
            }
            UnloadDroppedFiles(droppedFiles); //sterge dropped files
        }
        //daca lista nu e empty, atunci incarcam primul element in memorie si il scoatem din lista
        if (!songPaths.empty()) {
            songs.insert(LoadSong(songPaths.front().c_str()));  //Loads songs from songPaths queue one by one
            songPaths.pop();
        }
        //daca s-a terminat piesa, o oprim
        if (IsMusicDone(songPlaying.music)) {
            StopMusicStream(songPlaying.music); //stop the current song
            songPlaying = {};   //clear songPlaying
        }
        //daca nu e pusa nicio piesa, ii dam play la urmatoarea
        if (!songQueue.empty() && !IsMusicReady(songPlaying.music)) {
            songPlaying = songQueue.front();    //plays the next song
            songQueue.pop();    //remove current song from queue
            SeekMusicStream(songPlaying.music, 0.0f);   //Seek next song from start
            PlayMusicStream(songPlaying.music); //Play next song
        }

        if (IsMusicStreamPlaying(songPlaying.music)) {
            UpdateMusicStream(songPlaying.music);   //keeps the song playing
        }

        if (IsKeyPressed(KEY_P) && IsMusicReady(songPlaying.music)) {    //if key P is presed, skip song
            StopMusicStream(songPlaying.music);
            songPlaying = {};
        }
        //daca se apasa space, se da pause
        if (IsKeyPressed(KEY_SPACE) && IsMusicReady(songPlaying.music)) {
            if (IsMusicStreamPlaying(songPlaying.music)) {
                PauseMusicStream(songPlaying.music);
            } else {
                PlayMusicStream(songPlaying.music);
            }
        }

        BeginDrawing(); //interfata

        ClearBackground(background);

        musicPanel.Draw(songs, songQueue, mousePoint);

        if (songPlaying.hasCover) {
            //DrawTexture(songPlaying.cover, 640, 0, WHITE);
            DrawTextureEx(songPlaying.cover, {640 + 20, 20}, 0.0f, (640 - 40) / 640.0f, WHITE);
        }

        if (IsMusicReady(songPlaying.music)) {
            Rectangle sliderRec = {640 + 20, 640 + 20 - 10, 640 - 20 * 2, 80 - 20 * 2};
            bool mouseOnSlider = CheckCollisionPointRec(mousePoint, sliderRec);
            if (mouseOnSlider && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                SeekMusicStream(songPlaying.music, slider * GetMusicTimeLength(songPlaying.music));
            }
            if (!mouseOnSlider || IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
                slider = GetMusicTimePlayed(songPlaying.music) / GetMusicTimeLength(songPlaying.music);
            }
            GuiSliderBar(sliderRec, nullptr, nullptr, &slider, 0.0f, 1.0f);
        }

        DrawFPS(0,0);

        EndDrawing();
    }
    //daca se apasa X, se da delete la toate piesele
    for(const Song& song : songs) {
        UnloadSong(song);
    }

    UnloadDefaultFont();

    CloseWindow();
}
