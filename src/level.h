#ifndef H_TILE
#define H_TILE

#include <raylib.h>
#include <stdint.h>

typedef struct LevelData
{
    Vector2 **positions;
    uint8_t **tileIDs;
    
    uint16_t *tileCounts;
    uint16_t tileSize;
    uint16_t tileTypes;

    Vector2 indexedTilePos[17];
    Texture2D *tilesets;
} LevelData;


LevelData LoadLevelData(char* levelPath, char* tilesetPaths[]);

void DrawLevel(LevelData* levelData);

void FreeLevelData(LevelData* levelData);
#endif