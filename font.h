#ifndef SPOTIFY_CLONE_FONT_H
#define SPOTIFY_CLONE_FONT_H
#include "raylib.h"
#include "atlas.h"
#include "atlas-image.h"

Font defaultFont;
Shader defaultShader;

void LoadDefaultFont() {
    //Image img = LoadImage(ATLAS_ATLAS_IMAGE_PATH);
    Image img = LoadImageFromMemory(".png", atlas, atlasSize);
    Font fontSdf = {};
    fontSdf.baseSize = ATLAS_ATLAS_FONT_SIZE;
    fontSdf.glyphCount = ATLAS_ATLAS_SPRITE_COUNT;
    fontSdf.glyphPadding = 0;
    fontSdf.texture = LoadTextureFromImage(img);
    SetTextureFilter(fontSdf.texture, TEXTURE_FILTER_TRILINEAR);
    fontSdf.glyphs = (GlyphInfo *)malloc(ATLAS_ATLAS_SPRITE_COUNT*sizeof(GlyphInfo));
    fontSdf.recs = (Rectangle *)malloc(ATLAS_ATLAS_SPRITE_COUNT*sizeof(Rectangle));
    for (int i = 0; i < ATLAS_ATLAS_SPRITE_COUNT; i++) {
        fontSdf.recs[i] = { (float)rtpDescAtlas[i].positionX, (float)rtpDescAtlas[i].positionY, (float)rtpDescAtlas[i].sourceWidth, (float)rtpDescAtlas[i].sourceHeight };

        fontSdf.glyphs[i].value = rtpDescAtlas[i].charValue;
        fontSdf.glyphs[i].offsetX = rtpDescAtlas[i].charOffsetX;
        fontSdf.glyphs[i].offsetY = rtpDescAtlas[i].charOffsetY;
        fontSdf.glyphs[i].advanceX = rtpDescAtlas[i].charAdvanceX;

        fontSdf.glyphs[i].image = ImageFromImage(img, fontSdf.recs[i]);
    }
    UnloadImage(img);
    defaultFont = fontSdf;
    defaultShader = LoadShader(nullptr, "sdf.fs");
}

void UnloadDefaultFont() {
    UnloadFont(defaultFont);
    UnloadShader(defaultShader);
}

#endif //SPOTIFY_CLONE_FONT_H
