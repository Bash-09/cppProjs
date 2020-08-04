#include "player.h"

#define PI 3.1415926f

void Player::render(World& w, olc::PixelGameEngine& pge, olc::vi2d res) {

    /*
    * Constructs some useful vectors for later in the main rendering loop
    */
    //Normal vector (used as the plane which rays are generated on)
    olc::vf2d n = {-dir.y, dir.x};
    //Distance from player to rendering plane
    float l = n.mag() / tan((fov/2)*PI/180);
    //Leftmost point on rendering plane (each ray is taken as a vector from the player to this point + some fraction of n)
    olc::vf2d b = (dir * l) - (0.5 * n);
    //How much to multiple n by when adding to b
    float scale = 1/(float)res.x;
    //Loop for each pixel on the x-axis
    for(int x = 0; x < res.x; x++) {
        
        //Get ray direction as b + multiple of scale times n
        olc::vf2d r = b + (n * (x * scale));
        //Normalize vector
        r = r.norm();
        //Make ray
        Ray ray(pos, r);

        //Cast ray against all walls in the world to find the nearest collision
        Trace *trace = w.trace(ray);
        const Collision *col = trace->col;

        //Just go onto the next pixel if the ray didn't hit anything
        if(col == nullptr) continue;

        //Get distance from player to ray collision, do some scaling to remove fish-eye effect
        //and make walls a nice height for effective perspective
        float t = r.x * dir.x + r.y * dir.y;
        int h = (int)(10000/(t * col->t));

        //Dampen color for further away collisions (the fading you see on more distant walls)
        float atten = (float)h/100;
        if(atten > 1) atten = 1;
        if(atten < 0) atten = 0;
        //Draw the bloody wall
        pge.DrawLine({x, res.y/2 - h}, {x, res.y/2 + h}, olc::PixelF(atten, atten, atten));
        delete col;

    }

}