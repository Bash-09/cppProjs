#pragma once

#include <cmath>

const float PI = 2*acos(0);
const float RTD = 180/PI;
const float DTR = PI/180;

template<class T, int dims> class Vec;
template<class T, int dims> class Mat;
template<class T> class Im;

typedef Im<float> Imf;
typedef Im<float> Imd;

typedef Vec<float, 2> V2f;
typedef Vec<float, 3> V3f;
typedef Vec<float, 4> V4f;
typedef Vec<int, 2> V2i;
typedef Vec<int, 3> V3i;
typedef Vec<int, 4> V4i;
typedef Vec<double, 2> V2d;
typedef Vec<double, 3> V3d;
typedef Vec<double, 4> V4d;

typedef Mat<float, 2> M2f; 
typedef Mat<float, 3> M3f; 
typedef Mat<float, 4> M4f; 
typedef Mat<double, 2> M2d; 
typedef Mat<double, 3> M3d; 
typedef Mat<double, 4> M4d; 


//Vectors
template<class T, int dims> class Vec {
public:
    const int size = dims;

    T vals[dims] = { };

    T &x = vals[0];
    T &y = vals[1];
    T &z = vals[2];
    T &w = vals[3];

    T &r = vals[0];
    T &g = vals[1];
    T &b = vals[2];
    T &a = vals[3];    

    Vec();
    Vec(T rhs);
    Vec(const Vec &rhs);
    Vec(const Im &rhs);

    Vec(T x, T y);
    Vec(T x, T y, T z);
    Vec(T x, T y, T z, T w);

    ~Vec();

    void print();

    //Vector functions
    T mag2();
    T mag();

    Vec normalize();
    float dot(const Vec &v);

    Vec cross(const Vec &rhs);

    //Arithmetic
    Vec add(const Vec& rhs);
    Vec add(const Im& rhs);

    Vec added(const Vec &rhs);
    Vec added(const Im &rhs);

    Vec mul(const Vec &rhs);
    Vec mul(const T rhs);
    Vec mul(const Im &rhs);

    Vec mulled(const Vec &rhs);
    Vec mulled(const T rhs);
    Vec mulled(const Im &rhs);

    Vec div(const Vec &rhs);

    Vec divved(const Vec &rhs);

    //Operators
    Vec operator - () {return(mulled(-1));}
    Vec operator + (const Vec &rhs) {return(added(rhs));}
    Vec operator - (const Vec &rhs) {return(added(-rhs));}
    Vec operator * (const Vec &rhs) {return(mulled(rhs));}
    Vec operator * (const Im &rhs) {return(mulled(rhs));}
    Vec operator * (const T &rhs) {return(mulled(rhs));}
    Vec operator / (const Vec &rhs) {return(divved(rhs));}
    Vec operator / (const T rhs) {return(mulled(1/rhs));}
    void operator += (const Vec &rhs) {add(rhs);}
    void operator += (const T rhs) {add(rhs);}
    void operator -= (const T rhs) {add(-rhs);}
    void operator -= (const Vec &rhs) {add(-rhs);}
    void operator *= (const Vec &rhs) {mul(rhs);}
    void operator *= (const Im &rhs) {mul(rhs);}
    void operator *= (const T rhs) {mul(rhs);}
    void operator /= (const Vec &rhs) {div(rhs);}
    void operator /= (const T rhs) {mul(1/rhs);}

};

template<class T> Vec<T, 3> cross(const Vec<T, 3> &a, const Vec<T, 3> &b);

template<class T, int dims> class Mat {
private:

public:
    const int size = dims;

    T vals[dims][dims]] = {};

    Mat();
    Mat(Mat<T, rowNum, colNum> &rhs);
    Mat(T val);

    void print();

    Mat identity();
    Mat zero();

    Mat invert();

    //Arithmetic
    Mat add(const T rhs);
    Mat add(const Mat &rhs);

    Mat added(const T rhs);
    Mat added(const Mat &rhs);

    Mat mul(const T rhs);
    Mat mul(const Mat &rhs);

    Mat mulled(const T rhs);
    Mat mulled(const Mat &rhs);
    Vec mulled(const Vec &rhs);

    //Operator overloads
    Vec operator - () {return(mulled(-1));}
    Vec operator + (const Mat &rhs) {return(added(rhs));}
    Vec operator - (const Mat &rhs) {return(added(-rhs));}
    Vec operator * (const Mat &rhs) {return(mulled(rhs));}
    Vec operator * (const Vec &rhs) {return(mulled(rhs));}
    Vec operator * (const T &rhs) {return(mulled(rhs));}
    Vec operator / (const T rhs) {return(mulled(1/rhs));}
    void operator += (const Mat &rhs) {add(rhs);}
    void operator += (const T rhs) {add(rhs);}
    void operator -= (const Mat &rhs) {add(-rhs);}
    void operator *= (const Mat &rhs) {mul(rhs);}
    void operator *= (const T rhs) {mul(rhs);}
    void operator /= (const T rhs) {mul(1/rhs);}

};

template<class T> class Im {

};