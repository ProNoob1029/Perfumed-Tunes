//
// Created by dragos on 02/12/23.
//

#ifndef SPOTIFY_CLONE_SONG_H
#define SPOTIFY_CLONE_SONG_H

#include <cstdlib>
#include <codecvt>
#include "raylib.h"
#include "queue"
#include "cstring"
#include "string"
#include "locale"
#include "id3v2lib-2.0/id3v2lib.h"

struct Song {
    Music music{};
    std::string title;
    bool hasCover = false;
    Texture cover{};
};

void UnloadSong(Song &song) {
    UnloadMusicStream(song.music);
    UnloadTexture(song.cover);
}

Song LoadSong(char filepath[]) {
    Song newSong;
    newSong.music = LoadMusicStream(filepath);
    newSong.music.looping = false;

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
        if(tagTitle->data->encoding == '\001') {
            //Encoding is a bitch
            std::u16string u16title = (char16_t*)tagTitle->data->text;
            newSong.title = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(u16title);
            newSong.title = newSong.title.c_str() + 3;
        } else {
            newSong.title = tagTitle->data->text;
        }
    } else {
        std::string filename = GetFileName(filepath);
        newSong.title = filename.substr(0, filename.length() - 4);
        printf("%s\n", newSong.title.c_str());
    }

    free(tag);

    return newSong;
}

void GetSongFilePaths(std::queue<char*> &paths, char filepath[]) {
    if (IsPathFile(filepath)) {
        if (FileExists(filepath) && IsFileExtension(filepath, ".mp3")) {
            paths.push(filepath);
        }
    } else if (DirectoryExists(filepath)) {
        FilePathList files = LoadDirectoryFiles(filepath);
        for (int i = 0; i < files.count; i++) {
            GetSongFilePaths(paths, files.paths[i]);
        }
    }
}

#endif //SPOTIFY_CLONE_SONG_H
