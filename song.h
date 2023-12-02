//
// Created by dragos on 02/12/23.
//

#ifndef SPOTIFY_CLONE_SONG_H
#define SPOTIFY_CLONE_SONG_H

#include <cstdlib>
#include "raylib.h"
#include "queue"
#include "cstring"
#include "id3v2lib-2.0/id3v2lib.h"

struct Song {
    Music music{};
    char title[256] = "";
    bool hasCover = false;
    Texture cover{};
};

void UnloadSong(Song song) {
    UnloadMusicStream(song.music);
    UnloadTexture(song.cover);
}

Song LoadSong(char filepath[]) {
    Song newSong;
    newSong.music = LoadMusicStream(filepath);

    ID3v2_Tag *tag = ID3v2_read_tag(filepath);

    ID3v2_ApicFrame *cover = ID3v2_Tag_get_album_cover_frame(tag);

    if (cover != nullptr) {
        Image coverImage = LoadImageFromMemory(
                TextFormat(".%s", strrchr(reinterpret_cast<char *>(cover->data->mime_type), '/') + 1),
                reinterpret_cast<const unsigned char *>(cover->data->data), cover->data->picture_size
        );
        if (coverImage.data != nullptr) {
            newSong.cover = LoadTextureFromImage(coverImage);
            newSong.hasCover = true;
        }
        UnloadImage(coverImage);
    }

    ID3v2_TextFrame *tagTitle = ID3v2_Tag_get_title_frame(tag);

    if (tagTitle != nullptr) {
        TextCopy(newSong.title, tagTitle->data->text);
    }

    free(tag);

    return newSong;
}

void GetSongFilePaths(std::queue<char*> &paths, char filepath[]) {
    if (IsPathFile(filepath)) {
        if (FileExists(filepath) && IsFileExtension(filepath, ".mp3")) {
            paths.push(filepath);
        }
    } else {
        if (DirectoryExists(filepath)) {
            FilePathList files = LoadDirectoryFiles(filepath);
            for (int i = 0; i < files.count; i++) {
                GetSongFilePaths(paths, files.paths[i]);
            }
        }
    }
}

#endif //SPOTIFY_CLONE_SONG_H
