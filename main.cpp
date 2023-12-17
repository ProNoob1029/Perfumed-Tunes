#include "raylib.h" //se ocupa de audio, video, imput
#include "mygui.h" //fisier in care sunt elemente de interfata
#include "song.h" //fisier in care sunt definite functiile unei piese
#include "set" //librarie pentru multimea cu piese
#include "font.h"
#include "icon.h"

int main() {
    InitWindow(1280, 720, "Perfumed Tunes"); //creeaza fereastra+ii da nume+size
    InitAudioDevice(); //"porneste castile"-se conecteaza la audio

    //Seteaza logo-ul aplicatiei
    Image icon = LoadImageFromMemory(".png", icon_data, icon_size);
    SetWindowIcon(icon);
    UnloadImage(icon);

    SetMasterVolume(1.0f); //volumul aplicatiei
    SetTargetFPS(60); //cat de rapid isi da update/ cat de rapid deseneaza/ viteza while/s

    LoadDefaultFont();

    Color background = {23, 15, 30, 255};
    ConfigUI(background); //change colors of UI

    MusicPanel musicPanel;  //the music list on the left

    std::queue<std::string> songPaths;  //song filepaths queued for importing-fisierele sunt incarcate pe rand
    std::set<Song> songs; //o multime de piese
    std::deque<Song> songQueue; //queue-ul incepe cu urmatoarea piesa
    std::deque<Song> songBackStack;
    std::vector<Song> songSetList; //a replica of songs set
    std::vector<Song> songQueueList; // a replica of the queue
    Song songPlaying;
    Vector2 songScroll = {};
    Vector2 queueScroll = {};
    float slider = 0.0f; //piesa incepe de la timpul 0.0

    while (!WindowShouldClose()) { // verifica daca ai inchis programul (true=> stop)
        bool skipSong = IsKeyPressed(KEY_P); //daca se apasa pe tasta P=> skip

        bool playPrevious = IsKeyPressed(KEY_O); //daca se apasa tasta O=> previous song

        bool pauseSong = IsKeyPressed(KEY_SPACE); //pause

        while (songBackStack.size() > 100) {
            songBackStack.pop_back();
        }

        if (IsFileDropped()) { //verifica daca am adaugat fisierele
            FilePathList droppedFiles = LoadDroppedFiles(); //salveaza dropped files
            for (int i = 0; i < droppedFiles.count; i++) { //trecem peste dropped files
                GetSongFilePaths(songPaths, droppedFiles.paths[i]); //salvam ce MP3-uri am gasit
            }
            UnloadDroppedFiles(droppedFiles); //sterge dropped files
        }

        //daca s-a terminat piesa, o oprim
        if (IsMusicDone(songPlaying.music) && IsMusicReady(songPlaying.music)) {
            StopMusicStream(songPlaying.music); //stop the current song
            songBackStack.push_front(songPlaying);
            songPlaying = {};   //clear songPlaying
        }

        //daca lista nu e empty, atunci incarcam primul element in memorie si il scoatem din lista
        if (!songPaths.empty()) {
            songs.insert(LoadSong(songPaths.front().c_str()));  //Loads songs from songPaths queue one by one
            songPaths.pop();
        }

        if (IsMusicStreamPlaying(songPlaying.music)) {
            UpdateMusicStream(songPlaying.music);   //keeps the song playing
        }

        if (songSetList.size() != songs.size()) {
            songSetList = std::vector<Song>(songs.begin(), songs.end());
        }

        if (songQueueList.size() != songQueue.size()) {
            songQueueList = std::vector<Song>(songQueue.begin(), songQueue.end());
        }

        BeginDrawing(); //interfata

        ClearBackground(background);

        musicPanel.bounds = {0, 0, 320, 720};
        Song songClicked = {};
        int songClickedIndex = musicPanel.Draw(songSetList, songScroll);
        if (songClickedIndex > -1) {
            songClicked = songSetList[songClickedIndex];
        }

        if (IsMusicReady(songClicked.music)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                songQueue.push_back(songClicked);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                songQueue.push_front(songClicked);
            }
        }

        //daca nu e pusa nicio piesa, ii dam play la urmatoarea
        if (!songQueue.empty() && !IsMusicReady(songPlaying.music)) {
            songPlaying = songQueue.front();    //plays the next song
            songQueue.pop_front();    //remove current song from queue
            SeekMusicStream(songPlaying.music, 0.0f);   //Seek next song from start
            PlayMusicStream(songPlaying.music); //Play next song
        }

        //interfata
        if (songPlaying.hasCover) {
            DrawTextureEx(songPlaying.cover, {musicPanel.bounds.width + 20, 20}, 0.0f, (640 - 40) / 640.0f, WHITE);
        }


        if (IsMusicReady(songPlaying.music)) {
            Rectangle sliderRec = { musicPanel.bounds.width + 20, 640 - 10, 640 - 20 * 2, 60 - 20 * 2};
            ProgressBar(sliderRec, slider, songPlaying.music);

            float middle = sliderRec.x + sliderRec.width / 2;

            GuiSetStyle(DEFAULT, BORDER_WIDTH, 1);
            Rectangle playButtonRec = { middle - 50.0f / 2, sliderRec.y + sliderRec.height + 10.0f, 50, 50};
            pauseSong = pauseSong || PlayButton(playButtonRec, IsMusicStreamPlaying(songPlaying.music));

            Rectangle forwardButtonRec = { middle + 70.0f - 50.0f / 2, sliderRec.y + sliderRec.height + 10.0f, 50, 50};
            skipSong = skipSong || GuiButton(forwardButtonRec, GuiIconText(ICON_PLAYER_NEXT, nullptr));
            GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);
        }

        if (!songBackStack.empty()) {
            Rectangle backButtonRec = { 640 - 70.0f - 50.0f / 2, 640 - 10 + (60 - 20 * 2) + 10.0f, 50, 50};
            GuiSetStyle(DEFAULT, BORDER_WIDTH, 1);
            playPrevious = playPrevious || GuiButton(backButtonRec, GuiIconText(ICON_PLAYER_PREVIOUS, nullptr));
            GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);
        }

        musicPanel.bounds = { musicPanel.bounds.width + 640, 0, 320, 720};
        int removeSongIndex = musicPanel.Draw(songQueueList, queueScroll);
        if (removeSongIndex > -1) {
            songQueue.erase(songQueue.begin() + removeSongIndex);
        }

        EndDrawing();

        if (skipSong && IsMusicReady(songPlaying.music)) {    //if key P or button is pressed, skip song
            StopMusicStream(songPlaying.music);
            songBackStack.push_front(songPlaying);
            songPlaying = {};
        }

        if (playPrevious && !songBackStack.empty()) {       //if key O or button is pressed, play previous
            if (IsMusicReady(songPlaying.music)) {
                StopMusicStream(songPlaying.music);
                songQueue.push_front(songPlaying);
            }
            songPlaying = songBackStack.front();
            songBackStack.pop_front(); //lista cu piese care au fost ascultate deja
            SeekMusicStream(songPlaying.music, 0.0f);
            PlayMusicStream(songPlaying.music);
        }

        //daca se apasa space, se da pause
        if (pauseSong && IsMusicReady(songPlaying.music)) {
            if (IsMusicStreamPlaying(songPlaying.music)) {
                PauseMusicStream(songPlaying.music);
            } else {
                PlayMusicStream(songPlaying.music);
            }
        }
    }
    //daca se apasa X, se da delete la toate piesele
    for(const Song& song : songs) {
        UnloadSong(song);
    }

    UnloadDefaultFont();

    CloseWindow();
}
