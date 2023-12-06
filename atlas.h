//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// rTexpacker v3.0 Atlas Descriptor Code exporter v2.0                          //
//                                                                              //
// more info and bugs-report:  github.com/raylibtech/rtools                     //
// feedback and support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2020-2023 raylib technologies (@raylibtech)                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#define ATLAS_ATLAS_IMAGE_PATH      "atlas.png"
#define ATLAS_ATLAS_SPRITE_COUNT    106
#define ATLAS_ATLAS_FONT_SIZE       32

// Atlas sprite properties
typedef struct rtpAtlasSprite {
    const char *nameId;
    int originX, originY;
    int positionX, positionY;
    int sourceWidth, sourceHeight;
    int padding;
    bool trimmed;
    int trimRecX, trimRecY, trimRecWidth, trimRecHeight;

    // Atlas contains font data
    int charValue;
    int charOffsetX, charOffsetY;
    int charAdvanceX;
} rtpAtlasSprite;

// Atlas sprites array
static rtpAtlasSprite rtpDescAtlas[106] = {
    { "NotoSans-Regular-U0020", 0, 0, 45, 0, 6, 32, 0, false, 0, 0, 0, 0, 0x0020, 0, 0, 6 },
    { "NotoSans-Regular-U0021", 0, 0, 12, 86, 12, 26, 0, false, 3, 2, 7, 21, 0x0021, -3, 4, 6 },
    { "NotoSans-Regular-U0022", 0, 0, 20, 201, 16, 15, 0, false, 3, 2, 10, 10, 0x0022, -3, 4, 9 },
    { "NotoSans-Regular-U0023", 0, 0, 80, 111, 23, 25, 0, false, 3, 2, 18, 21, 0x0023, -4, 4, 15 },
    { "NotoSans-Regular-U0024", 0, 0, 111, 30, 20, 28, 0, false, 2, 2, 15, 23, 0x0024, -3, 3, 13 },
    { "NotoSans-Regular-U0025", 0, 0, 131, 30, 26, 27, 0, false, 2, 3, 21, 21, 0x0025, -3, 3, 19 },
    { "NotoSans-Regular-U0026", 0, 0, 157, 30, 25, 27, 0, false, 2, 3, 20, 21, 0x0026, -3, 3, 17 },
    { "NotoSans-Regular-U0027", 0, 0, 36, 204, 11, 15, 0, false, 3, 2, 6, 10, 0x0027, -3, 4, 5 },
    { "NotoSans-Regular-U0028", 0, 0, 189, 29, 15, 29, 0, false, 3, 2, 9, 25, 0x0028, -4, 4, 7 },
    { "NotoSans-Regular-U0029", 0, 0, 223, 0, 15, 29, 0, false, 3, 2, 9, 25, 0x0029, -4, 4, 7 },
    { "NotoSans-Regular-U002A", 0, 0, 0, 186, 20, 19, 0, false, 3, 2, 15, 15, 0x002A, -4, 3, 12 },
    { "NotoSans-Regular-U002B", 0, 0, 212, 185, 20, 20, 0, false, 2, 2, 15, 15, 0x002B, -3, 7, 13 },
    { "NotoSans-Regular-U002C", 0, 0, 170, 203, 13, 15, 0, false, 3, 2, 7, 10, 0x002C, -4, 18, 6 },
    { "NotoSans-Regular-U002D", 0, 0, 93, 204, 15, 11, 0, false, 3, 3, 10, 6, 0x002D, -4, 13, 7 },
    { "NotoSans-Regular-U002E", 0, 0, 81, 204, 12, 12, 0, false, 3, 2, 7, 7, 0x002E, -3, 18, 6 },
    { "NotoSans-Regular-U002F", 0, 0, 200, 160, 17, 25, 0, false, 2, 2, 12, 21, 0x002F, -4, 4, 8 },
    { "NotoSans-Regular-U0030", 0, 0, 43, 58, 20, 27, 0, false, 2, 3, 15, 21, 0x0030, -3, 3, 13 },
    { "NotoSans-Regular-U0031", 0, 0, 17, 161, 15, 25, 0, false, 2, 2, 10, 21, 0x0031, -2, 4, 13 },
    { "NotoSans-Regular-U0032", 0, 0, 79, 85, 20, 26, 0, false, 2, 3, 15, 21, 0x0032, -3, 3, 13 },
    { "NotoSans-Regular-U0033", 0, 0, 63, 58, 20, 27, 0, false, 2, 3, 15, 21, 0x0033, -3, 3, 13 },
    { "NotoSans-Regular-U0034", 0, 0, 235, 135, 21, 25, 0, false, 3, 2, 16, 21, 0x0034, -4, 4, 13 },
    { "NotoSans-Regular-U0035", 0, 0, 59, 85, 20, 26, 0, false, 2, 2, 15, 21, 0x0035, -3, 4, 13 },
    { "NotoSans-Regular-U0036", 0, 0, 152, 57, 20, 27, 0, false, 2, 3, 15, 21, 0x0036, -3, 3, 13 },
    { "NotoSans-Regular-U0037", 0, 0, 126, 136, 20, 25, 0, false, 2, 2, 15, 21, 0x0037, -3, 4, 13 },
    { "NotoSans-Regular-U0038", 0, 0, 103, 58, 20, 27, 0, false, 2, 3, 15, 21, 0x0038, -3, 3, 13 },
    { "NotoSans-Regular-U0039", 0, 0, 192, 58, 20, 27, 0, false, 2, 3, 15, 21, 0x0039, -3, 3, 13 },
    { "NotoSans-Regular-U003A", 0, 0, 160, 161, 12, 22, 0, false, 3, 2, 7, 17, 0x003A, -3, 8, 6 },
    { "NotoSans-Regular-U003B", 0, 0, 32, 161, 13, 25, 0, false, 3, 2, 8, 20, 0x003B, -4, 8, 6 },
    { "NotoSans-Regular-U003C", 0, 0, 93, 183, 20, 21, 0, false, 2, 3, 15, 15, 0x003C, -3, 6, 13 },
    { "NotoSans-Regular-U003D", 0, 0, 20, 186, 20, 15, 0, false, 2, 3, 15, 10, 0x003D, -3, 9, 13 },
    { "NotoSans-Regular-U003E", 0, 0, 73, 183, 20, 21, 0, false, 2, 3, 15, 15, 0x003E, -3, 6, 13 },
    { "NotoSans-Regular-U003F", 0, 0, 238, 57, 18, 27, 0, false, 2, 3, 14, 21, 0x003F, -4, 3, 10 },
    { "NotoSans-Regular-U0040", 0, 0, 218, 29, 27, 28, 0, false, 2, 2, 23, 23, 0x0040, -3, 4, 21 },
    { "NotoSans-Regular-U0041", 0, 0, 230, 110, 23, 25, 0, false, 2, 2, 19, 21, 0x0041, -4, 4, 15 },
    { "NotoSans-Regular-U0042", 0, 0, 214, 135, 21, 25, 0, false, 2, 2, 16, 21, 0x0042, -2, 4, 15 },
    { "NotoSans-Regular-U0043", 0, 0, 0, 32, 22, 27, 0, false, 2, 3, 17, 21, 0x0043, -3, 3, 14 },
    { "NotoSans-Regular-U0044", 0, 0, 126, 111, 22, 25, 0, false, 2, 2, 18, 21, 0x0044, -2, 4, 17 },
    { "NotoSans-Regular-U0045", 0, 0, 164, 136, 18, 25, 0, false, 2, 2, 14, 21, 0x0045, -2, 4, 13 },
    { "NotoSans-Regular-U0046", 0, 0, 182, 136, 18, 25, 0, false, 2, 2, 14, 21, 0x0046, -2, 4, 12 },
    { "NotoSans-Regular-U0047", 0, 0, 75, 31, 23, 27, 0, false, 2, 3, 18, 21, 0x0047, -3, 3, 17 },
    { "NotoSans-Regular-U0048", 0, 0, 148, 111, 22, 25, 0, false, 2, 2, 17, 21, 0x0048, -2, 4, 17 },
    { "NotoSans-Regular-U0049", 0, 0, 217, 160, 16, 25, 0, false, 3, 2, 10, 21, 0x0049, -4, 4, 7 },
    { "NotoSans-Regular-U004A", 0, 0, 174, 0, 15, 30, 0, false, 2, 2, 10, 25, 0x004A, -6, 4, 6 },
    { "NotoSans-Regular-U004B", 0, 0, 85, 136, 21, 25, 0, false, 2, 2, 16, 21, 0x004B, -2, 4, 14 },
    { "NotoSans-Regular-U004C", 0, 0, 146, 136, 18, 25, 0, false, 2, 2, 14, 21, 0x004C, -2, 4, 12 },
    { "NotoSans-Regular-U004D", 0, 0, 54, 111, 26, 25, 0, false, 2, 2, 21, 21, 0x004D, -2, 4, 21 },
    { "NotoSans-Regular-U004E", 0, 0, 192, 111, 22, 25, 0, false, 2, 2, 18, 21, 0x004E, -2, 4, 17 },
    { "NotoSans-Regular-U004F", 0, 0, 51, 31, 24, 27, 0, false, 2, 3, 20, 21, 0x004F, -3, 3, 18 },
    { "NotoSans-Regular-U0050", 0, 0, 106, 136, 20, 25, 0, false, 2, 2, 15, 21, 0x0050, -2, 4, 14 },
    { "NotoSans-Regular-U0051", 0, 0, 111, 0, 24, 30, 0, false, 2, 3, 20, 25, 0x0051, -3, 3, 18 },
    { "NotoSans-Regular-U0052", 0, 0, 22, 136, 21, 25, 0, false, 2, 2, 16, 21, 0x0052, -2, 4, 14 },
    { "NotoSans-Regular-U0053", 0, 0, 142, 84, 19, 27, 0, false, 2, 3, 15, 21, 0x0053, -3, 3, 12 },
    { "NotoSans-Regular-U0054", 0, 0, 43, 136, 21, 25, 0, false, 2, 2, 17, 21, 0x0054, -4, 4, 13 },
    { "NotoSans-Regular-U0055", 0, 0, 230, 84, 22, 26, 0, false, 2, 2, 17, 21, 0x0055, -2, 4, 17 },
    { "NotoSans-Regular-U0056", 0, 0, 103, 111, 23, 25, 0, false, 2, 2, 18, 21, 0x0056, -4, 4, 14 },
    { "NotoSans-Regular-U0057", 0, 0, 24, 111, 30, 25, 0, false, 2, 2, 26, 21, 0x0057, -4, 4, 21 },
    { "NotoSans-Regular-U0058", 0, 0, 170, 111, 22, 25, 0, false, 2, 2, 18, 21, 0x0058, -4, 4, 13 },
    { "NotoSans-Regular-U0059", 0, 0, 0, 112, 22, 25, 0, false, 2, 2, 17, 21, 0x0059, -4, 4, 13 },
    { "NotoSans-Regular-U005A", 0, 0, 64, 136, 21, 25, 0, false, 3, 2, 16, 21, 0x005A, -4, 4, 13 },
    { "NotoSans-Regular-U005B", 0, 0, 238, 0, 15, 29, 0, false, 3, 2, 9, 25, 0x005B, -3, 4, 7 },
    { "NotoSans-Regular-U005C", 0, 0, 0, 137, 17, 25, 0, false, 2, 2, 12, 21, 0x005C, -4, 4, 8 },
    { "NotoSans-Regular-U005D", 0, 0, 204, 29, 14, 29, 0, false, 3, 2, 9, 25, 0x005D, -4, 4, 7 },
    { "NotoSans-Regular-U005E", 0, 0, 232, 185, 21, 19, 0, false, 3, 2, 16, 15, 0x005E, -4, 4, 13 },
    { "NotoSans-Regular-U005F", 0, 0, 108, 204, 20, 10, 0, false, 3, 2, 14, 6, 0x005F, -5, 23, 10 },
    { "NotoSans-Regular-U0060", 0, 0, 67, 204, 14, 12, 0, false, 3, 2, 9, 8, 0x0060, -4, 3, 6 },
    { "NotoSans-Regular-U0061", 0, 0, 105, 161, 19, 22, 0, false, 2, 2, 14, 17, 0x0061, -3, 8, 13 },
    { "NotoSans-Regular-U0062", 0, 0, 131, 57, 21, 27, 0, false, 3, 2, 15, 22, 0x0062, -3, 3, 14 },
    { "NotoSans-Regular-U0063", 0, 0, 142, 161, 18, 22, 0, false, 2, 2, 13, 17, 0x0063, -3, 8, 11 },
    { "NotoSans-Regular-U0064", 0, 0, 83, 58, 20, 27, 0, false, 2, 2, 15, 22, 0x0064, -3, 3, 14 },
    { "NotoSans-Regular-U0065", 0, 0, 65, 161, 20, 22, 0, false, 2, 2, 15, 17, 0x0065, -3, 8, 13 },
    { "NotoSans-Regular-U0066", 0, 0, 161, 85, 18, 26, 0, false, 2, 2, 13, 22, 0x0066, -4, 3, 8 },
    { "NotoSans-Regular-U0067", 0, 0, 172, 58, 20, 27, 0, false, 2, 2, 15, 23, 0x0067, -3, 8, 14 },
    { "NotoSans-Regular-U0068", 0, 0, 39, 85, 20, 26, 0, false, 3, 2, 15, 22, 0x0068, -3, 3, 14 },
    { "NotoSans-Regular-U0069", 0, 0, 0, 86, 12, 26, 0, false, 3, 3, 6, 21, 0x0069, -3, 3, 6 },
    { "NotoSans-Regular-U006A", 0, 0, 19, 0, 15, 32, 0, false, 3, 3, 9, 27, 0x006A, -6, 3, 6 },
    { "NotoSans-Regular-U006B", 0, 0, 99, 85, 20, 26, 0, false, 3, 2, 14, 22, 0x006B, -3, 3, 12 },
    { "NotoSans-Regular-U006C", 0, 0, 196, 85, 12, 26, 0, false, 3, 2, 6, 22, 0x006C, -3, 3, 6 },
    { "NotoSans-Regular-U006D", 0, 0, 45, 183, 28, 21, 0, false, 3, 2, 22, 17, 0x006D, -3, 8, 21 },
    { "NotoSans-Regular-U006E", 0, 0, 113, 183, 20, 21, 0, false, 3, 2, 15, 17, 0x006E, -3, 8, 14 },
    { "NotoSans-Regular-U006F", 0, 0, 85, 161, 20, 22, 0, false, 2, 2, 16, 17, 0x006F, -3, 8, 14 },
    { "NotoSans-Regular-U0070", 0, 0, 22, 32, 21, 27, 0, false, 3, 2, 15, 23, 0x0070, -3, 8, 14 },
    { "NotoSans-Regular-U0071", 0, 0, 218, 57, 20, 27, 0, false, 2, 2, 15, 23, 0x0071, -3, 8, 14 },
    { "NotoSans-Regular-U0072", 0, 0, 153, 183, 17, 21, 0, false, 3, 2, 11, 17, 0x0072, -3, 8, 9 },
    { "NotoSans-Regular-U0073", 0, 0, 124, 161, 18, 22, 0, false, 2, 2, 13, 17, 0x0073, -3, 8, 11 },
    { "NotoSans-Regular-U0074", 0, 0, 233, 160, 16, 25, 0, false, 2, 3, 12, 19, 0x0074, -4, 5, 8 },
    { "NotoSans-Regular-U0075", 0, 0, 45, 161, 20, 22, 0, false, 3, 2, 15, 17, 0x0075, -3, 8, 14 },
    { "NotoSans-Regular-U0076", 0, 0, 133, 183, 20, 21, 0, false, 2, 2, 16, 17, 0x0076, -4, 8, 11 },
    { "NotoSans-Regular-U0077", 0, 0, 172, 161, 27, 21, 0, false, 2, 2, 22, 17, 0x0077, -4, 8, 18 },
    { "NotoSans-Regular-U0078", 0, 0, 172, 182, 21, 21, 0, false, 3, 2, 15, 17, 0x0078, -4, 8, 12 },
    { "NotoSans-Regular-U0079", 0, 0, 0, 59, 20, 27, 0, false, 2, 2, 16, 23, 0x0079, -4, 8, 11 },
    { "NotoSans-Regular-U007A", 0, 0, 193, 185, 19, 21, 0, false, 3, 2, 13, 17, 0x007A, -4, 8, 11 },
    { "NotoSans-Regular-U007B", 0, 0, 206, 0, 17, 29, 0, false, 3, 2, 11, 25, 0x007B, -4, 4, 8 },
    { "NotoSans-Regular-U007C", 0, 0, 34, 0, 11, 32, 0, false, 3, 2, 5, 28, 0x007C, 1, 3, 12 },
    { "NotoSans-Regular-U007D", 0, 0, 189, 0, 17, 29, 0, false, 3, 2, 11, 25, 0x007D, -4, 4, 8 },
    { "NotoSans-Regular-U007E", 0, 0, 47, 204, 20, 12, 0, false, 2, 2, 15, 7, 0x007E, -3, 11, 13 },
    { "NotoSans-Regular-U0219", 0, 0, 212, 84, 18, 27, 0, false, 2, 2, 13, 22, 0x0219, -3, 8, 11 },
    { "NotoSans-Regular-U021B", 0, 0, 158, 0, 16, 30, 0, false, 2, 3, 12, 24, 0x021B, -4, 5, 8 },
    { "NotoSans-Regular-U0103", 0, 0, 20, 59, 19, 27, 0, false, 2, 3, 14, 21, 0x0103, -3, 3, 13 },
    { "NotoSans-Regular-U00EE", 0, 0, 179, 85, 17, 26, 0, false, 2, 2, 12, 22, 0x00EE, -5, 3, 6 },
    { "NotoSans-Regular-U00E2", 0, 0, 123, 84, 19, 27, 0, false, 2, 2, 14, 22, 0x00E2, -3, 3, 13 },
    { "NotoSans-Regular-U0218", 0, 0, 0, 0, 19, 32, 0, false, 2, 3, 15, 26, 0x0218, -3, 3, 12 },
    { "NotoSans-Regular-U021A", 0, 0, 74, 0, 21, 31, 0, false, 2, 2, 17, 26, 0x021A, -4, 4, 13 },
    { "NotoSans-Regular-U0102", 0, 0, 135, 0, 23, 30, 0, false, 2, 2, 19, 26, 0x0102, -4, -1, 15 },
    { "NotoSans-Regular-U00CE", 0, 0, 95, 0, 16, 31, 0, false, 2, 3, 12, 26, 0x00CE, -4, -2, 7 },
    { "NotoSans-Regular-U00C2", 0, 0, 51, 0, 23, 31, 0, false, 2, 3, 19, 26, 0x00C2, -4, -2, 15 },
    { "NotoSans-Regular-U000A", 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0x000A, 0, 0, 0 },
};
