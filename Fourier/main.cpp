#define OLC_PGE_APPLICATION

#include "maths.h"
#include "pge.h"
#include "iostream"



class Main : public olc::PixelGameEngine{
public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};

olc::vi2d res = {1000, 1000};
bool fullscreen = false;
bool vsync = false;

int main() {

    Main main;
    if(main.Construct(res.x, res.y, 1, 1, fullscreen, vsync)) {
        main.Start();
    }

}


class detail {
public:
    detail() {}
    detail(int freq, float ang, float rad) {
        frequency = freq;
        angle = bm::cn(ang);
        radius = rad;
    }

    int frequency = 1;
    bm::cn angle = {0};
    float radius = 1;
};

std::vector<detail*> transform;



olc::vf2d getPos(olc::PixelGameEngine& pge, float t) {
    bm::v2f pos = {(float)res.x/2, (float)res.y/2};

    for(auto i = transform.begin(); i != transform.end(); i++) {
        bm::cn trans = {t * (*i)->frequency * 360};
        trans *= (*i)->angle;
        trans *= (*i)->radius;

        pge.DrawCircle({(int)(pos.x), (int)(pos.y)}, (*i)->radius, olc::DARK_GREY);
        pge.DrawLine({(int)(pos.x), (int)(pos.y)}, {(int)(pos.x + trans.r), (int)(pos.y + trans.i)}, olc::DARK_GREY);

        pos += trans;
    }
    return {pos.x, pos.y};
}


int imgLayer = 0;
int liveLayer = 0;
int userLayer = 0;

bool Main::OnUserCreate() {
    transform.push_back(new detail(1,   90,    90));
    transform.push_back(new detail(-1,  300,    70));
    transform.push_back(new detail(2,  12,     62));
    transform.push_back(new detail(-2,   120,    50));
    transform.push_back(new detail(3,   79,     38));
    transform.push_back(new detail(-3,  250,    25));
    transform.push_back(new detail(4,  12,     17));
    transform.push_back(new detail(-4,   90,    10));
    transform.push_back(new detail(-5,  312,    7));
    transform.push_back(new detail(5,   0,      3));

    Clear(olc::BLANK);

    imgLayer = CreateLayer();
    liveLayer = CreateLayer();
    userLayer = CreateLayer();

    SetDrawTarget(userLayer);
    Clear(olc::VERY_DARK_BLUE);
    SetDrawTarget(imgLayer);
    Clear(olc::BLANK);
    SetDrawTarget(liveLayer);
    Clear(olc::BLANK);

    SetDrawTarget(nullptr);

    EnableLayer(userLayer, true);
    EnableLayer(liveLayer, true);
    EnableLayer(imgLayer, true);

    return true;
}


int imgRes = 1000;
std::vector<olc::vf2d> drawing;


float t = 0;
bool init = true;
olc::vf2d last;
bool go = false;

bool painting = false;
std::vector<olc::vi2d> points;

int fourierRes = 12;
void calculate() {
    transform.clear();

    for(int i = 0; i < fourierRes; i++) {
        int freq = (i+1) / 2;
        if(i % 2 == 1) freq *= -1;

        bm::v2f total = {0};
        for(int j = 0; j < points.size(); j++) {
            float t = (float)j / (float)points.size();
            bm::v2f pos = {(float)(points[j].x - res.x/2), (float)(points[j].y - res.y/2)};
            bm::cn trans = {(float)-freq * 360 * t};

            pos *= trans;
            total += pos;
        }

        total /= (float)points.size();

        float angle = RTD * (float)atan(total.y / total.x);
        if(total.x < 1) angle += 180;

        transform.push_back(new detail{freq, angle, total.mag()});
    }
}



bool Main::OnUserUpdate(float fElapsedTime) {

    SetDrawTarget(userLayer);
    if(GetMouse(0).bPressed) { //Start drawing
        SetDrawTarget(imgLayer);    //Clear old stuff
        Clear(olc::BLANK);
        SetDrawTarget(liveLayer);
        Clear(olc::BLANK);
        SetDrawTarget(userLayer);
        Clear(olc::VERY_DARK_BLUE);

        points.clear(); //Reset current stuff
        t = 0;
        painting = true;
        points.push_back({GetMouseX(), GetMouseY()});
        SetDrawTarget(nullptr);
        go = true;
        return true;
    }
    if(painting) {
        if(GetMouse(0).bReleased) {
            painting = false;
            points.push_back((*points.begin()));
            DrawLine({(*(points.end()-1))}, {(*(points.end()-2))});
            calculate();
            init = true;
            return true;
        }

        olc::vi2d next = {GetMouseX(), GetMouseY()};
        if((next - (*(points.end()-1))).mag2() > 1) {
            DrawLine({(*(points.end()-1))}, {next});
            points.push_back(next);
        }

        SetDrawTarget(nullptr);
        return true;
    }

    if(!go) return true;

    SetDrawTarget(liveLayer);
    Clear(olc::BLANK);
    

    if(init) {
        last = getPos(*this, 0);
        init = false;
        return true;
    }
    t += fElapsedTime * 0.1;

    olc::vf2d next = getPos(*this, t);
    //FillCircle(next, 5);

    SetDrawTarget(imgLayer);

    DrawLine(last, next, olc::RED);


    last = next;

    SetDrawTarget(nullptr);
    return true;
}