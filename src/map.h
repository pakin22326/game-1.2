#ifndef MAP_H
#define MAP_H

// รวม header ไม่ใส่ใน .cpp เพราะจะได้ไม่ต้อง include ซ้ำหลายๆ ที่
#include "raylib.h"

class Map {
public:
    // กำหนดขนาด Grid (เช่น 30x30 ช่อง)
    int rows = 30;
    int cols = 30;
    int tileSize = 20; // หนึ่งช่องกว้าง 20 pixel
    int maxBoxes = 20; // จำนวนกล่องสุ่มที่จะเพิ่มในแมพ
    
    int data[100][100]; // 0 = พื้น, 1 = กำแพง

    Map(int rows, int cols, int tileSize, int maxBoxes);      // Constructor (ใช้ตั้งค่าแมพตอนเริ่มเกม)
    bool IsWall(float x, float y); // ฟังก์ชันเช็คว่าตำแหน่ง (x, y) เป็นกำแพงหรือไม่
    void Draw(); // ฟังก์ชันวาดแมพ
};

#endif