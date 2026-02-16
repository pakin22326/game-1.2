#include "map.h"

Map::Map(int rows, int cols, int tileSize, int maxBoxes) {
    SetRandomSeed(GetTime());
    // กำหนดค่าเริ่มต้นให้กับแมพ (1 คือกำแพงขอบสนาม)
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (y == 0 || y == rows - 1 || x == 0 || x == cols - 1) 
                data[y][x] = 1; // ขอบแมพเป็นกำแพง
            else 
                data[y][x] = 0; // ข้างในเป็นพื้นว่าง
        }
    }
    for (int i = 0; i < maxBoxes; i++) // สุ่มกล่องเพิ่มในแมพ (ตัวอย่าง)
    data[GetRandomValue(0, rows - 1)][GetRandomValue(0, cols - 1)] = 1; // ตัวอย่างการเปลี่ยนสุ่มช่องให้เป็นกล่อง
}

void Map::Draw() {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            // คำนวณตำแหน่ง Pixel จากตำแหน่ง Grid
            // ตำแหน่ง $Pixel = Grid \times tileSize$
            float posX = x * tileSize;
            float posY = y * tileSize;

            if (data[y][x] == 1) {
                // วาดกำแพง
                DrawRectangle(posX, posY, tileSize, tileSize, DARKGRAY);
            } else {
                // วาดพื้น (อาจจะวาดเส้นตารางจางๆ)
                DrawRectangleLines(posX, posY, tileSize, tileSize, LIGHTGRAY);
            }
        }
    }
}

bool Map::IsWall(float x, float y) {
    // 1. แปลง Pixel เป็นตำแหน่งใน Array (Grid)
    int col = (int)(x / tileSize);
    int row = (int)(y / tileSize);

    // 2. เช็คกัน Error: ถ้าพิกัดอยู่นอกขอบเขตแมพ ให้ถือว่าเป็นกำแพงไว้ก่อน
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return true; 
    }

    // 3. คืนค่าตามข้อมูลใน Array (1 คือกำแพง/จริง, 0 คือพื้น/เท็จ)
    return data[row][col] == 1;
}