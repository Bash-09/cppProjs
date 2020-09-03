#define OLC_PGE_APPLICATION

#include <string>
#include <sstream>

#include "pge.h"
#include "iostream"
#include "maths.h"

class Main : public olc::PixelGameEngine{
public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};

olc::vi2d res = {600, 600};
bool fullscreen = false;
bool vsync = true;

int main() {

    Main main;
    if(main.Construct(res.x, res.y, 1, 1, fullscreen, vsync)) {
        main.Start();
    }

}

int bg = 0;
int fg = 0;

V2f p1 = {200, 400};
V2f p2 = {400, 400};

V2f cp1 = {200, 200};
V2f cp2 = {400, 200};

bool Main::OnUserCreate() {
    fg = CreateLayer(); //Create drawing layers 
    bg = CreateLayer();

    EnableLayer(bg, true); 
    EnableLayer(fg, true);

    Clear(olc::BLANK); //Clear layers
    SetDrawTarget(bg);
    Clear(olc::BLANK);
    SetDrawTarget(fg);
    Clear(olc::BLANK);

    return true;
}

bool animate = false; //State control variables
float t = 0;
bool clicked = false;
V2f* selected = nullptr;

float speed = 3; //Control variables
int lineRes = 50;

bool Main::OnUserUpdate(float fElapsedTime) {
    SetDrawTarget(bg);

    Clear(olc::BLACK);

    if(GetMouse(0).bPressed) {
        V2f pos = {(float)GetMouseX(), (float)GetMouseY()};
        
        V2f dis = pos - p1; //Detecting grabbing of points
        if(dis.mag2() < 25) {
            clicked = true;
            selected = &p1;
            goto NEXT;
        }
        dis = pos - p2;
        if(dis.mag2() < 25) {
            clicked = true;
            selected = &p2;
            goto NEXT;
        }
        dis = pos - cp1;
        if(dis.mag2() < 25) {
            clicked = true;
            selected = &cp1;
            goto NEXT;
        }
        dis = pos - cp2;
        if(dis.mag2() < 25) {
            clicked = true;
            selected = &cp2;
            goto NEXT;
        }

        dis = pos; //Detecting animate button press
        dis.x -= 30;
        dis.y -= 30;
        if(dis.mag() <= 20) {
            animate = true;
            t = 0;
        }

    }
    if(GetMouse(0).bReleased) {
        clicked = false;
        selected = nullptr;
    }

    if(clicked) {
        V2f pos = {(float)GetMouseX(), (float)GetMouseY()};
        *selected = pos;
    }
    NEXT:

    FillCircle(30, 30, 20, olc::GREEN);
    DrawString(60, 30, "Animate!", olc::GREEN);

    std::ostringstream oss;

    DrawLine(p1.x, p1.y, cp1.x, cp1.y, olc::BLUE); //This is all just 
    DrawLine(cp2.x, cp2.y, p2.x, p2.y, olc::BLUE); //Drawing a bunch
    DrawLine(cp2.x, cp2.y, cp1.x, cp1.y, olc::BLUE);//of crap

    FillCircle(p1.x, p1.y, 5);
    oss.str("");
    oss.clear();
    oss << "(" << p1.x << ", " << res.y - p1.y << ")";
    DrawString(p1.x + 10, p1.y + 10, oss.str());
    
    FillCircle(p2.x, p2.y, 5);
    oss.str("");
    oss.clear();
    oss << "(" << p2.x << ", " << res.y - p2.y << ")";
    DrawString(p2.x + 10, p2.y + 10, oss.str());

    FillCircle(cp1.x, cp1.y, 5, olc::RED);
    oss.str("");
    oss.clear();
    oss << "(" << cp1.x << ", " << res.y - cp1.y << ")";
    DrawString(cp1.x + 10, cp1.y + 10, oss.str());

    FillCircle(cp2.x, cp2.y, 5, olc::RED);
    oss.str("");
    oss.clear();
    oss << "(" << cp2.x << ", " << res.y - cp2.y << ")";
    DrawString(cp2.x + 10, cp2.y + 10, oss.str());

    V2f pa = p2 - (cp2 * 3) + (cp1 * 3) - p1;
    V2f pb = (cp2 * 3) - (cp1 * 6) + (p1 * 3);
    V2f pc = (cp1 * 3) - (p1 * 3);
    V2f pd = p1;

    oss.str("");
    oss.clear();
    oss << "x(t) = " << pa.x << "t^3 + " << pb.x << "t^2 + " << pc.x << "t + " << pd.x;
    DrawString(10, 60, oss.str());

    oss.str("");
    oss.clear();
    oss << "y(t) = " << -pa.y << "t^3 + " << -pb.y << "t^2 + " << -pc.y << "t + " << pd.y+res.y;
    DrawString(10, 80, oss.str());


    V2f a = cp1 - p1; //Vectors between main points
    V2f b = cp2 - cp1;
    V2f c = p2 - cp2;

    V2f last = p1;

    if(animate) {
        t += fElapsedTime / speed;
    }
    for(int i = 1; i < lineRes+1; i++) { //Loop to draw curved line
        float dist = (float)i/lineRes;
        if(animate) dist *= t;

        V2f lp1 = p1 + (a * dist); //Points on lines from above
        V2f lp2 = cp1 + (b * dist);
        V2f lp3 = cp2 + (c * dist);

        V2f d = lp2 - lp1; //Lines between those points
        V2f e = lp3 - lp2;

        V2f lp4 = lp1 + (d * dist); //Points on those lines
        V2f lp5 = lp2 + (e * dist);

        V2f f = lp5 - lp4; //Lines between those points
        V2f lp6 = lp4 + (f * dist); //Point on that line (the next part on the bezier curve)

        DrawLine(last.x, last.y, lp6.x, lp6.y);
        last = lp6;

        if(animate) { //Draw cool animated stuff
            SetDrawTarget(fg);
            Clear(olc::BLANK);

            DrawLine(lp1.x, lp1.y, lp2.x, lp2.y, olc::DARK_GREY);
            DrawLine(lp2.x, lp2.y, lp3.x, lp3.y, olc::DARK_GREY);
            DrawLine(lp4.x, lp4.y, lp5.x, lp5.y, olc::DARK_GREY);

            FillCircle(lp1.x, lp1.y, 3, olc::GREEN);
            FillCircle(lp2.x, lp2.y, 3, olc::GREEN);
            FillCircle(lp3.x, lp3.y, 3, olc::GREEN);
            FillCircle(lp4.x, lp4.y, 3, olc::GREEN);
            FillCircle(lp5.x, lp5.y, 3, olc::GREEN);
            FillCircle(lp6.x, lp6.y, 3, olc::RED);

            if(t >= 1) {
                animate = false;
                Clear(olc::BLANK);
            }
            SetDrawTarget(bg);
        }

    }

    SetDrawTarget(nullptr);
    return true;
}