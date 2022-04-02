#include "level.h"
#include <stdlib.h>
#include <stdio.h>

LevelData LoadLevelData(char* levelPath, char* tilesetPaths[])
{
    LevelData result = (LevelData){};
    FILE* stream = fopen(levelPath, "r+");
    if(!stream) return (LevelData){};
    uint16_t tileTypes, tileSize, tileCount = 0;
    printf("opened file successfully!\n");
    fscanf(stream, "%d\n", &tileTypes);
    fscanf(stream, "%d\n", &tileSize);
    fscanf(stream, "%*d, %*d\n", stream, stream);
    result.positions = malloc(tileTypes * sizeof(Rectangle*));
    result.tileIDs = malloc(tileTypes * sizeof(uint8_t*));
    result.tilesets = malloc(tileTypes * sizeof(Texture2D*));
    result.tileCounts = malloc(tileTypes * sizeof(uint16_t));
    printf("%d\n", tileTypes);
    result.tileTypes = tileTypes;
    result.tileSize = tileSize;

    for (int k = 0; k < tileTypes; ++k)
    {
        fscanf(stream, "%d\n", &tileCount);
        result.tileCounts[k] = tileCount;
        result.positions[k] = malloc(tileCount * sizeof(Rectangle));
        result.tileIDs[k] = malloc(tileCount * sizeof(uint8_t));
        result.tilesets[k] = LoadTexture(tilesetPaths[k]);
        for (int i = 0; i < tileCount; ++i)
        {
            fscanf(stream, "%f, %f, %d\n", &result.positions[k][i].x, &result.positions[k][i].y, &result.tileIDs[k][i]);
            //printf("%f, %f, %d\n", result.positions[k][i].x, result.positions[k][i].y,result.tileIDs[k][i]);
        }
        

    }
    
    
    int c = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result.indexedTilePos[c] = (Vector2){j * result.tileSize, i * result.tileSize};
            ++c;
        }
    }
    result.indexedTilePos[16] = (Vector2){5*result.tileSize,0};
    

    fclose(stream);
    printf("closed file successfully\n");
    return result;
}

void DrawLevel(LevelData* levelData)
{
    for (int k = 0; k < levelData->tileTypes; ++k)
    {
        for(int i = 0; i < levelData->tileCounts[k]; ++i)
        {
            DrawTexturePro(levelData->tilesets[k], 
            (Rectangle){
            levelData->indexedTilePos[levelData->tileIDs[k][i]].x,levelData->indexedTilePos[levelData->tileIDs[k][i]].y, levelData->tileSize, levelData->tileSize}
            , (Rectangle){levelData->positions[k][i].x, levelData->positions[k][i].y, levelData->tileSize,levelData->tileSize}, (Vector2){0,0}, 0, WHITE
            );
        }
    }
    
}

void FreeLevelData(LevelData* levelData)
{
    for (int i = 0; i < levelData->tileTypes; i++)
    {
        UnloadTexture(levelData->tilesets[i]);
        free(levelData->positions[i]);
        free(levelData->tileIDs[i]);
    }
    
    free(levelData->tilesets);
    free(levelData->tileIDs);
    free(levelData->positions);
    free(levelData->tileCounts);
}