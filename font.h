#ifndef SPOTIFY_CLONE_FONT_H
#define SPOTIFY_CLONE_FONT_H
#include "raylib.h"
#include "atlas.h"
#include "atlas.png.h"

Font defaultFont;
Shader defaultShader;

const char shaderCode[] = "#version 330\n"
                          "\n"
                          "// Input vertex attributes (from vertex shader)\n"
                          "in vec2 fragTexCoord;\n"
                          "in vec4 fragColor;\n"
                          "\n"
                          "// Input uniform values\n"
                          "uniform sampler2D texture0;\n"
                          "uniform vec4 colDiffuse;\n"
                          "\n"
                          "// Output fragment color\n"
                          "out vec4 finalColor;\n"
                          "\n"
                          "// NOTE: Add here your custom variables\n"
                          "\n"
                          "void main()\n"
                          "{\n"
                          "    // Texel color fetching from texture sampler\n"
                          "    // NOTE: Calculate alpha using signed distance field (SDF)\n"
                          "    float distanceFromOutline = texture(texture0, fragTexCoord).a - 0.5;\n"
                          "    float distanceChangePerFragment = length(vec2(dFdx(distanceFromOutline), dFdy(distanceFromOutline)));\n"
                          "    float alpha = smoothstep(-distanceChangePerFragment, distanceChangePerFragment, distanceFromOutline);\n"
                          "\n"
                          "    // Calculate final fragment color\n"
                          "    finalColor = vec4(fragColor.rgb, fragColor.a*alpha);\n"
                          "}";

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
    //defaultShader = LoadShader(nullptr, "sdf.fs");
    defaultShader = LoadShaderFromMemory(nullptr, shaderCode);
}

void UnloadDefaultFont() {
    UnloadFont(defaultFont);
    UnloadShader(defaultShader);
}

#endif //SPOTIFY_CLONE_FONT_H
