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
#define ATLAS_ATLAS_SPRITE_COUNT    101
#define ATLAS_ATLAS_FONT_SIZE       39

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
static rtpAtlasSprite rtpDescAtlas[101] = {
    { "NotoSansJP-Regular-U0020", 0, 0, 11, 0, 6, 39, 0, false, 0, 0, 0, 0, 0x0020, 0, 0, 6 },
    { "NotoSansJP-Regular-U0021", 0, 0, 145, 95, 13, 30, 0, false, 3, 3, 7, 24, 0x0021, -2, 6, 8 },
    { "NotoSansJP-Regular-U0022", 0, 0, 222, 231, 17, 16, 0, false, 2, 2, 12, 12, 0x0022, -2, 6, 12 },
    { "NotoSansJP-Regular-U0023", 0, 0, 139, 153, 22, 28, 0, false, 2, 2, 17, 24, 0x0023, -3, 7, 14 },
    { "NotoSansJP-Regular-U0024", 0, 0, 61, 0, 21, 35, 0, false, 3, 2, 15, 30, 0x0024, -3, 4, 14 },
    { "NotoSansJP-Regular-U0025", 0, 0, 118, 35, 31, 30, 0, false, 2, 3, 27, 24, 0x0025, -3, 6, 24 },
    { "NotoSansJP-Regular-U0026", 0, 0, 17, 37, 26, 30, 0, false, 3, 3, 21, 24, 0x0026, -4, 6, 18 },
    { "NotoSansJP-Regular-U0027", 0, 0, 242, 208, 12, 16, 0, false, 2, 2, 7, 12, 0x0027, -2, 6, 7 },
    { "NotoSansJP-Regular-U0028", 0, 0, 17, 0, 14, 37, 0, false, 2, 3, 10, 31, 0x0028, -2, 4, 9 },
    { "NotoSansJP-Regular-U0029", 0, 0, 31, 0, 14, 37, 0, false, 2, 3, 10, 31, 0x0029, -3, 4, 9 },
    { "NotoSansJP-Regular-U002A", 0, 0, 191, 231, 18, 18, 0, false, 3, 3, 13, 12, 0x002A, -3, 5, 12 },
    { "NotoSansJP-Regular-U002B", 0, 0, 0, 231, 21, 22, 0, false, 2, 2, 17, 18, 0x002B, -3, 10, 14 },
    { "NotoSansJP-Regular-U002C", 0, 0, 209, 231, 13, 18, 0, false, 2, 3, 9, 12, 0x002C, -3, 23, 7 },
    { "NotoSansJP-Regular-U002D", 0, 0, 133, 232, 16, 11, 0, false, 2, 3, 11, 5, 0x002D, -3, 18, 9 },
    { "NotoSansJP-Regular-U002E", 0, 0, 42, 232, 13, 13, 0, false, 3, 3, 8, 7, 0x002E, -3, 23, 7 },
    { "NotoSansJP-Regular-U002F", 0, 0, 101, 0, 19, 35, 0, false, 2, 3, 14, 30, 0x002F, -4, 5, 10 },
    { "NotoSansJP-Regular-U0030", 0, 0, 21, 67, 21, 30, 0, false, 2, 3, 17, 24, 0x0030, -3, 6, 14 },
    { "NotoSansJP-Regular-U0031", 0, 0, 42, 181, 20, 28, 0, false, 2, 2, 15, 24, 0x0031, -2, 7, 14 },
    { "NotoSansJP-Regular-U0032", 0, 0, 0, 97, 21, 29, 0, false, 2, 3, 17, 24, 0x0032, -3, 6, 14 },
    { "NotoSansJP-Regular-U0033", 0, 0, 43, 66, 22, 30, 0, false, 3, 3, 16, 24, 0x0033, -4, 6, 14 },
    { "NotoSansJP-Regular-U0034", 0, 0, 47, 153, 23, 28, 0, false, 3, 2, 17, 24, 0x0034, -4, 7, 14 },
    { "NotoSansJP-Regular-U0035", 0, 0, 73, 96, 22, 29, 0, false, 3, 2, 17, 24, 0x0035, -4, 7, 14 },
    { "NotoSansJP-Regular-U0036", 0, 0, 87, 66, 21, 30, 0, false, 3, 3, 16, 24, 0x0036, -3, 6, 14 },
    { "NotoSansJP-Regular-U0037", 0, 0, 225, 180, 21, 28, 0, false, 2, 2, 17, 24, 0x0037, -3, 7, 14 },
    { "NotoSansJP-Regular-U0038", 0, 0, 187, 94, 21, 30, 0, false, 2, 3, 17, 24, 0x0038, -3, 6, 14 },
    { "NotoSansJP-Regular-U0039", 0, 0, 229, 94, 21, 30, 0, false, 2, 3, 16, 24, 0x0039, -3, 6, 14 },
    { "NotoSansJP-Regular-U003A", 0, 0, 178, 208, 13, 24, 0, false, 3, 3, 8, 18, 0x003A, -3, 12, 7 },
    { "NotoSansJP-Regular-U003B", 0, 0, 158, 124, 13, 29, 0, false, 2, 3, 9, 23, 0x003B, -3, 12, 7 },
    { "NotoSansJP-Regular-U003C", 0, 0, 112, 230, 21, 22, 0, false, 2, 3, 17, 16, 0x003C, -3, 10, 14 },
    { "NotoSansJP-Regular-U003D", 0, 0, 85, 231, 21, 18, 0, false, 2, 3, 17, 12, 0x003D, -3, 12, 14 },
    { "NotoSansJP-Regular-U003E", 0, 0, 64, 209, 21, 22, 0, false, 2, 3, 17, 16, 0x003E, -3, 10, 14 },
    { "NotoSansJP-Regular-U003F", 0, 0, 108, 95, 19, 30, 0, false, 2, 2, 14, 25, 0x003F, -3, 6, 12 },
    { "NotoSansJP-Regular-U0040", 0, 0, 209, 0, 31, 33, 0, false, 3, 3, 26, 28, 0x0040, -3, 7, 25 },
    { "NotoSansJP-Regular-U0041", 0, 0, 94, 125, 25, 28, 0, false, 2, 2, 20, 24, 0x0041, -4, 7, 16 },
    { "NotoSansJP-Regular-U0042", 0, 0, 219, 152, 23, 28, 0, false, 3, 2, 17, 24, 0x0042, -2, 7, 17 },
    { "NotoSansJP-Regular-U0043", 0, 0, 118, 65, 24, 30, 0, false, 3, 3, 18, 24, 0x0043, -3, 6, 17 },
    { "NotoSansJP-Regular-U0044", 0, 0, 24, 153, 23, 28, 0, false, 3, 2, 18, 24, 0x0044, -2, 7, 18 },
    { "NotoSansJP-Regular-U0045", 0, 0, 183, 180, 21, 28, 0, false, 3, 2, 15, 24, 0x0045, -2, 7, 15 },
    { "NotoSansJP-Regular-U0046", 0, 0, 204, 180, 21, 28, 0, false, 3, 2, 15, 24, 0x0046, -2, 7, 14 },
    { "NotoSansJP-Regular-U0047", 0, 0, 231, 64, 24, 30, 0, false, 3, 3, 19, 24, 0x0047, -3, 6, 18 },
    { "NotoSansJP-Regular-U0048", 0, 0, 70, 153, 23, 28, 0, false, 3, 2, 18, 24, 0x0048, -2, 7, 19 },
    { "NotoSansJP-Regular-U0049", 0, 0, 80, 181, 12, 28, 0, false, 3, 2, 6, 24, 0x0049, -2, 7, 7 },
    { "NotoSansJP-Regular-U004A", 0, 0, 21, 97, 20, 29, 0, false, 3, 2, 15, 24, 0x004A, -4, 7, 14 },
    { "NotoSansJP-Regular-U004B", 0, 0, 195, 152, 24, 28, 0, false, 3, 2, 18, 24, 0x004B, -2, 7, 17 },
    { "NotoSansJP-Regular-U004C", 0, 0, 22, 181, 20, 28, 0, false, 3, 2, 15, 24, 0x004C, -2, 7, 14 },
    { "NotoSansJP-Regular-U004D", 0, 0, 68, 125, 26, 28, 0, false, 3, 2, 20, 24, 0x004D, -2, 7, 21 },
    { "NotoSansJP-Regular-U004E", 0, 0, 93, 153, 23, 28, 0, false, 3, 2, 18, 24, 0x004E, -2, 7, 19 },
    { "NotoSansJP-Regular-U004F", 0, 0, 205, 64, 26, 30, 0, false, 3, 3, 20, 24, 0x004F, -3, 6, 19 },
    { "NotoSansJP-Regular-U0050", 0, 0, 0, 154, 22, 28, 0, false, 3, 2, 17, 24, 0x0050, -2, 7, 17 },
    { "NotoSansJP-Regular-U0051", 0, 0, 183, 0, 26, 34, 0, false, 3, 3, 21, 29, 0x0051, -3, 6, 19 },
    { "NotoSansJP-Regular-U0052", 0, 0, 116, 153, 23, 28, 0, false, 3, 2, 17, 24, 0x0052, -2, 7, 17 },
    { "NotoSansJP-Regular-U0053", 0, 0, 65, 66, 22, 30, 0, false, 2, 3, 18, 24, 0x0053, -3, 6, 16 },
    { "NotoSansJP-Regular-U0054", 0, 0, 0, 126, 24, 28, 0, false, 3, 2, 18, 24, 0x0054, -4, 7, 16 },
    { "NotoSansJP-Regular-U0055", 0, 0, 158, 95, 23, 29, 0, false, 3, 2, 18, 24, 0x0055, -2, 7, 19 },
    { "NotoSansJP-Regular-U0056", 0, 0, 171, 152, 24, 28, 0, false, 2, 2, 19, 24, 0x0056, -4, 7, 15 },
    { "NotoSansJP-Regular-U0057", 0, 0, 171, 124, 31, 28, 0, false, 3, 2, 26, 24, 0x0057, -4, 7, 23 },
    { "NotoSansJP-Regular-U0058", 0, 0, 119, 125, 24, 28, 0, false, 3, 2, 18, 24, 0x0058, -4, 7, 15 },
    { "NotoSansJP-Regular-U0059", 0, 0, 231, 124, 24, 28, 0, false, 3, 2, 18, 24, 0x0059, -5, 7, 14 },
    { "NotoSansJP-Regular-U005A", 0, 0, 161, 180, 22, 28, 0, false, 2, 2, 18, 24, 0x005A, -3, 7, 16 },
    { "NotoSansJP-Regular-U005B", 0, 0, 168, 0, 15, 35, 0, false, 3, 3, 9, 30, 0x005B, -2, 5, 9 },
    { "NotoSansJP-Regular-U005C", 0, 0, 82, 0, 19, 35, 0, false, 2, 3, 14, 30, 0x005C, -4, 5, 10 },
    { "NotoSansJP-Regular-U005D", 0, 0, 153, 0, 15, 35, 0, false, 3, 3, 9, 30, 0x005D, -4, 5, 9 },
    { "NotoSansJP-Regular-U005E", 0, 0, 64, 231, 21, 21, 0, false, 3, 3, 15, 15, 0x005E, -3, 6, 14 },
    { "NotoSansJP-Regular-U005F", 0, 0, 149, 232, 23, 10, 0, false, 2, 2, 19, 6, 0x005F, -4, 29, 15 },
    { "NotoSansJP-Regular-U0060", 0, 0, 239, 231, 15, 15, 0, false, 3, 3, 10, 10, 0x0060, -1, 3, 16 },
    { "NotoSansJP-Regular-U0061", 0, 0, 114, 181, 21, 25, 0, false, 3, 3, 15, 19, 0x0061, -3, 11, 15 },
    { "NotoSansJP-Regular-U0062", 0, 0, 209, 33, 22, 31, 0, false, 2, 3, 17, 25, 0x0062, -2, 5, 16 },
    { "NotoSansJP-Regular-U0063", 0, 0, 92, 206, 20, 25, 0, false, 2, 3, 16, 19, 0x0063, -3, 11, 13 },
    { "NotoSansJP-Regular-U0064", 0, 0, 61, 35, 22, 31, 0, false, 2, 3, 17, 25, 0x0064, -3, 5, 16 },
    { "NotoSansJP-Regular-U0065", 0, 0, 135, 181, 21, 25, 0, false, 2, 3, 17, 19, 0x0065, -3, 11, 14 },
    { "NotoSansJP-Regular-U0066", 0, 0, 127, 95, 18, 30, 0, false, 3, 2, 13, 26, 0x0066, -4, 5, 8 },
    { "NotoSansJP-Regular-U0067", 0, 0, 231, 33, 22, 31, 0, false, 2, 3, 18, 26, 0x0067, -3, 11, 15 },
    { "NotoSansJP-Regular-U0068", 0, 0, 0, 67, 21, 30, 0, false, 2, 3, 16, 25, 0x0068, -2, 5, 16 },
    { "NotoSansJP-Regular-U0069", 0, 0, 95, 96, 12, 29, 0, false, 2, 2, 7, 25, 0x0069, -2, 6, 7 },
    { "NotoSansJP-Regular-U006A", 0, 0, 45, 0, 16, 36, 0, false, 3, 2, 10, 31, 0x006A, -6, 6, 7 },
    { "NotoSansJP-Regular-U006B", 0, 0, 208, 94, 21, 30, 0, false, 2, 3, 17, 25, 0x006B, -2, 5, 14 },
    { "NotoSansJP-Regular-U006C", 0, 0, 105, 35, 13, 31, 0, false, 2, 3, 8, 25, 0x006C, -2, 5, 7 },
    { "NotoSansJP-Regular-U006D", 0, 0, 112, 206, 29, 24, 0, false, 2, 3, 25, 19, 0x006D, -2, 11, 24 },
    { "NotoSansJP-Regular-U006E", 0, 0, 0, 207, 21, 24, 0, false, 2, 3, 16, 19, 0x006E, -2, 11, 16 },
    { "NotoSansJP-Regular-U006F", 0, 0, 92, 181, 22, 25, 0, false, 2, 3, 18, 19, 0x006F, -3, 11, 16 },
    { "NotoSansJP-Regular-U0070", 0, 0, 183, 34, 22, 31, 0, false, 2, 3, 17, 25, 0x0070, -2, 11, 16 },
    { "NotoSansJP-Regular-U0071", 0, 0, 83, 35, 22, 31, 0, false, 2, 3, 17, 25, 0x0071, -3, 11, 16 },
    { "NotoSansJP-Regular-U0072", 0, 0, 161, 208, 17, 24, 0, false, 2, 3, 12, 19, 0x0072, -2, 11, 10 },
    { "NotoSansJP-Regular-U0073", 0, 0, 0, 182, 20, 25, 0, false, 3, 3, 15, 19, 0x0073, -4, 11, 12 },
    { "NotoSansJP-Regular-U0074", 0, 0, 62, 181, 18, 28, 0, false, 3, 2, 13, 23, 0x0074, -4, 8, 10 },
    { "NotoSansJP-Regular-U0075", 0, 0, 141, 208, 20, 24, 0, false, 2, 2, 16, 19, 0x0075, -2, 12, 16 },
    { "NotoSansJP-Regular-U0076", 0, 0, 220, 208, 22, 23, 0, false, 2, 2, 18, 19, 0x0076, -4, 12, 14 },
    { "NotoSansJP-Regular-U0077", 0, 0, 191, 208, 29, 23, 0, false, 3, 2, 24, 19, 0x0077, -4, 12, 21 },
    { "NotoSansJP-Regular-U0078", 0, 0, 21, 209, 22, 23, 0, false, 2, 2, 17, 19, 0x0078, -4, 12, 13 },
    { "NotoSansJP-Regular-U0079", 0, 0, 165, 65, 22, 30, 0, false, 2, 2, 18, 25, 0x0079, -4, 12, 14 },
    { "NotoSansJP-Regular-U007A", 0, 0, 43, 209, 21, 23, 0, false, 3, 2, 15, 19, 0x007A, -4, 12, 12 },
    { "NotoSansJP-Regular-U007B", 0, 0, 137, 0, 16, 35, 0, false, 2, 3, 11, 30, 0x007B, -3, 5, 9 },
    { "NotoSansJP-Regular-U007C", 0, 0, 0, 0, 11, 39, 0, false, 3, 2, 5, 34, 0x007C, -2, 4, 7 },
    { "NotoSansJP-Regular-U007D", 0, 0, 120, 0, 17, 35, 0, false, 3, 3, 11, 30, 0x007D, -4, 5, 9 },
    { "NotoSansJP-Regular-U007E", 0, 0, 21, 232, 21, 14, 0, false, 2, 3, 17, 8, 0x007E, -3, 14, 14 },
    { "NotoSansJP-Regular-U30E1", 0, 0, 149, 35, 29, 30, 0, false, 2, 3, 25, 25, 0x30E1, -1, 6, 26 },
    { "NotoSansJP-Regular-U30D5", 0, 0, 202, 124, 29, 28, 0, false, 3, 2, 23, 24, 0x30D5, -1, 8, 26 },
    { "NotoSansJP-Regular-U30A3", 0, 0, 41, 125, 27, 28, 0, false, 2, 3, 22, 22, 0x30A3, -1, 10, 26 },
    { "NotoSansJP-Regular-U30B9", 0, 0, 42, 96, 31, 29, 0, false, 3, 3, 25, 24, 0x30B9, -2, 7, 26 },
    { "NotoSansJP-Regular-U30C8", 0, 0, 142, 65, 23, 30, 0, false, 3, 2, 18, 26, 0x30C8, 4, 6, 26 },
    { "NotoSansJP-Regular-U000A", 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0x000A, 0, 0, 0 },
};
