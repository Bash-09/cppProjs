#include "renderer.h"

//Loops through each pixel on the screen and gets the colour to draw
void render(olc::PixelGameEngine &pge, V2i res, Camera &cam, std::vector<Collideable*> scene) {

    for(int i = 0; i < res.x; i++) {
        for(int j = 0; j < res.y; j++) {
            float x = (float)i / (float)res.x;
            float y = 1 - (float)j / (float)res.y;

            olc::Pixel pix = getPixel({x, y}, cam, scene);
            pge.FillRect(i, j, 1, 1, pix);

        }
    }

}

//Casts ray against everything in the scene
Collision castRay(Ray &ray, std::vector<Collideable*> scene) {

    Collision col = {ray, 1000, ray.dir, nullptr};
    
    for(auto i = scene.begin(); i != scene.end(); i++) {
        col = (**i).trace(col, ray);
    }

    return col;
}

//Gets the outgoing ray for a given x/y coordinate from the camera
Ray Camera::getOutRay(V2f coords) {

    //Orthogonal view
    //V3f p = pos + x*coords.x - x/2 + y*coords.y - y/2;
    //V3f d = z;

    //Perspective view
    float l = 0.5 / tan(fov*DTR/2);
    V3f d = x*coords.x - x/2 + y*coords.y - y/2 + z*l;

    return {pos, d};
}

//Updates the stuff in the camera to calculate outgoing rays properly
void Camera::updateDir(V3f newDir) {
    V3f seed = {0, 1, 0};
    z = newDir.normalized();
    x = z.cross(seed);
    y = x.cross(z);
}

//Gets the ray for a certain pixel, casts it and gets the colour of the material it hit
olc::Pixel getPixel(V2f coords, Camera &cam, std::vector<Collideable*> scene) {

    Ray ray = cam.getOutRay(coords);
    Collision col = castRay(ray, scene);

    if(col.target == nullptr) return olc::BLACK;

    V3f colour = (col.target->mat->col);
    return olc::PixelF(colour.x, colour.y, colour.z);
}