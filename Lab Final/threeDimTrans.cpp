#include <iostream>
#include <cmath>
#include <graphics.h>
#include <vector>
using namespace std;

// 3D point structure
struct Point3D {
    float x, y, z;
    Point3D(float x=0, float y=0, float z=0) : x(x), y(y), z(z) {}
};

// Project 3D to 2D (orthographic, ignoring z for simplicity)
pair<int,int> project(Point3D p, int cx, int cy, float scale) {
    int x2d = cx + p.x * scale;
    int y2d = cy - p.y * scale; // invert Y because screen origin top-left
    return {x2d, y2d};
}

// Draw cube from 8 vertices
void drawCube(vector<Point3D> &verts, int cx, int cy, float scale) {
    // Define edges (12 edges of a cube)
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0}, // bottom face
        {4,5},{5,6},{6,7},{7,4}, // top face
        {0,4},{1,5},{2,6},{3,7}  // vertical edges
    };
    for (auto &e : edges) {
        auto p1 = project(verts[e[0]], cx, cy, scale);
        auto p2 = project(verts[e[1]], cx, cy, scale);
        line(p1.first, p1.second, p2.first, p2.second);
    }
}

int main() {
    initwindow(800, 600);

    // Initial cube vertices (centered at origin, side length = 2)
    vector<Point3D> vertices = {
        {-1,-1,-1}, { 1,-1,-1}, { 1,-1, 1}, {-1,-1, 1}, // bottom
        {-1, 1,-1}, { 1, 1,-1}, { 1, 1, 1}, {-1, 1, 1}  // top
    };

    int cx = 400, cy = 300;   // screen center
    float scale = 80;         // scaling factor for projection
    float angle = 0;          // rotation angle (radians)

    // 1. Original cube
    setcolor(WHITE);
    drawCube(vertices, cx, cy, scale);
    delay(2000);
    cleardevice();

    // 2. Translate by (2, 2, 2)
    vector<Point3D> translated = vertices;
    for (auto &p : translated) {
        p.x += 2; p.y += 2; p.z += 2;
    }
    drawCube(translated, cx, cy, scale);
    delay(2000);
    cleardevice();

    // 3. Rotate about Y‑axis by 45° (π/4)
    angle = M_PI / 4;
    vector<Point3D> rotated = vertices;
    for (auto &p : rotated) {
        float xnew = p.x * cos(angle) + p.z * sin(angle);
        float znew = -p.x * sin(angle) + p.z * cos(angle);
        p.x = xnew;
        p.z = znew;
    }
    drawCube(rotated, cx, cy, scale);
    delay(2000);
    cleardevice();

    // 4. Scale by factor 1.5 in all directions
    vector<Point3D> scaled = vertices;
    float sf = 1.5;
    for (auto &p : scaled) {
        p.x *= sf; p.y *= sf; p.z *= sf;
    }
    drawCube(scaled, cx, cy, scale);
    delay(2000);
    cleardevice();

    // Bonus: show all transformations together (translated, then rotated, then scaled)
    vector<Point3D> combined = vertices;
    // Translate
    for (auto &p : combined) { p.x += 2; p.y += 2; p.z += 2; }
    // Rotate
    for (auto &p : combined) {
        float xnew = p.x * cos(angle) + p.z * sin(angle);
        float znew = -p.x * sin(angle) + p.z * cos(angle);
        p.x = xnew; p.z = znew;
    }
    // Scale
    for (auto &p : combined) {
        p.x *= sf; p.y *= sf; p.z *= sf;
    }
    setcolor(YELLOW);
    drawCube(combined, cx, cy, scale);
    outtextxy(10, 10, "Combined: Translate, Rotate, Scale");

    getch();
    closegraph();
    return 0;
}