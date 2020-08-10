#include "player.h"


#define PI 3.1415926f


//Will have to make screen depth buffer for rendering first person per barrier
void Player::renderMap(olc::PixelGameEngine *pge, olc::vi2d res) {

    pge->DrawCircle(res/2, 5);
    pge->DrawLine(res/2, {res.x/2, res.y/2 - 10});

    for(std::vector<Barrier**>::iterator i = bars.begin(); i != bars.end(); i++) {
        if(*i == nullptr) {
            i = bars.erase(i);
            continue;
        }

        olc::vf2d b1 = (**i)->p1 - pos;
        olc::vf2d b2 = (**i)->p2 - pos;

        olc::vf2d p1;
        olc::vf2d p2;

        float zoom = 0.5;

        p1.x = -dir.y*b1.x + dir.x*b1.y;
        p1.y = -dir.y*b1.y - dir.x*b1.x;

        p2.x = -dir.y*b2.x + dir.x*b2.y;
        p2.y = -dir.y*b2.y - dir.x*b2.x;

        p1 *= zoom;
        p2 *= zoom;

        //pge->DrawLine(middle + b.p1, middle + b.p2);
        pge->DrawLine(res/2 + p1, res/2 + p2);

    }
}

void Player::renderFP(olc::PixelGameEngine *pge, olc::vi2d res, Barrier* bar) {
     olc::vf2d n = {-dir.y, dir.x};
    //Distance from player to rendering plane
    float l = n.mag() / tan((fov/2)*PI/180);
    //Leftmost point on rendering plane (each ray is taken as a vector from the player to this point + some fraction of n)
    olc::vf2d b = (dir * l) - (0.5 * n);
    //How much to multiple n by when adding to b
    float scale = 1/(float)res.x;



    for(int x = 0; x < res.x; x++) {
        olc::vf2d r = b + (n * (x * scale));
        r = r.norm();

        Ray ray(pos, r);
        Collision* col = bar->trace(ray);

        if(col == nullptr) continue;

        float t = r.x * dir.x + r.y * dir.y;
        int h = (int)(10000/(t * col->t));
        //Dampen color for further away collisions (the fading you see on more distant walls)
        float atten = (float)h/100;
        if(atten > 1) atten = 1;
        if(atten < 0) atten = 0;
        //Check if barrier has a texture, if not draw line
        if(((Barrier*)col->target)->texture == nullptr) {
            pge->DrawLine({x, res.y/2 - h}, {x, res.y/2 + h}, olc::PixelF(atten, atten, atten));
        } else {
            //Otherwise draw column of pixels from texture
            Barrier* b = (Barrier*)col->target;
            float tDist = (col->pos - b->p1).mag() * b->texture->sprite->width/b->textureWidth;

            pge->DrawPartialDecal({(float)x, res.y/2-(float)h}, {1, 2*(float)h}, b->texture, {tDist, 0}, {1, (float)b->texture->sprite->height}, olc::PixelF(atten, atten, atten));
        }

        //Draw the bloody wall
        
        delete col;

    }
}

bool compareCol(Collision* a, Collision* b) {
    return(a->t > b->t);
}

//Public
void Player::renderFP(olc::PixelGameEngine *pge, olc::vi2d res) {

    olc::vf2d n = {-dir.y, dir.x};
    //Distance from player to rendering plane
    float l = n.mag() / tan((fov/2)*PI/180);
    //Leftmost point on rendering plane (each ray is taken as a vector from the player to this point + some fraction of n)
    olc::vf2d b = (dir * l) - (0.5 * n);
    //How much to multiple n by when adding to b
    float scale = 1/(float)res.x;

    //Loop for each column of pixels
    for(int x = 0; x < res.x; x++) {
        //Generate ray
        olc::vf2d r = b + (n * (x * scale));
        r = r.norm();

        Ray ray(pos, r);

        std::vector<Collision*> cols;


        //Trace all the barriers and sort collisions for distance from camera
        for(std::vector<Barrier**>::iterator i = bars.begin(); i != bars.end(); i++) {
            if(**i == nullptr) {
                i = bars.erase(i);
                continue;
            }

            Collision* c = (**i)->trace(ray);

            if(c == nullptr) continue;
            cols.push_back(c);
            
        }

        sort(cols.begin(), cols.end(), compareCol);

        //Loop through recorded collisions and render them
        for(auto col = cols.begin(); col != cols.end(); col++) {


            float t = r.x * dir.x + r.y * dir.y;
            int h = (int)(10000/(t * (*col)->t));

            //Dampen color for further away collisions (the fading you see on more distant walls)
            float atten = (float)h/100;
            if(atten > 1) atten = 1;
            if(atten < 0) atten = 0;

            if(((Barrier*)(*col)->target)->texture == nullptr) {
                pge->DrawLine({x, res.y/2 - h}, {x, res.y/2 + h}, olc::PixelF(atten, atten, atten));
            } else {

                Barrier* b = (Barrier*)(*col)->target;
                float tDist = ((*col)->pos - b->p1).mag() * b->texture->sprite->width/b->textureWidth;

                pge->DrawPartialDecal({(float)x, res.y/2-(float)h}, {1, 2*(float)h}, b->texture, {tDist, 0}, {1, (float)b->texture->sprite->height}, olc::PixelF(atten, atten, atten));
            }
            //delete *col;
            //col = cols.erase(col);
        }

        for(auto i : cols) {
            delete i;
        }
        cols.clear();

    }

}

//Private
Collision* Player::castRay(Ray& ray) {
    Collision* col = nullptr;

    for(std::vector<Barrier**>::iterator i = bars.begin(); i != bars.end(); i++) {
        if(*i == nullptr) {
            i = bars.erase(i);
            continue;
        }

        Collision* c = (**i)->trace(ray);

        if(c == nullptr) continue;
        if(col == nullptr && c->t > 0) {
            col = c;
            continue;
        } else if(c->t > 0 && c->t < col->t) {
            delete col;
            col = c;
            continue;
        }

        delete c;
    }
    return col;
}