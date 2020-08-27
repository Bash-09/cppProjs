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
    Vec(Vec &rhs);
    Vec(Im<T> &rhs);

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
    Vec add(const Im<T>& rhs);

    Vec added(const Vec &rhs);
    Vec added(const Im<T> &rhs);

    Vec mul(const Vec &rhs);
    Vec mul(const T rhs);
    Vec mul(const Im<T> &rhs);

    Vec mulled(const Vec &rhs);
    Vec mulled(const T rhs);
    Vec mulled(const Im<T> &rhs);

    Vec div(const Vec &rhs);

    Vec divved(const Vec &rhs);

    //Operators
    Vec operator - () {return(mulled(-1));}
    Vec operator + (const Vec &rhs) {return(added(rhs));}
    Vec operator - (const Vec &rhs) {return(added(-rhs));}
    Vec operator * (const Vec &rhs) {return(mulled(rhs));}
    Vec operator * (const Im<T> &rhs) {return(mulled(rhs));}
    Vec operator * (const T &rhs) {return(mulled(rhs));}
    Vec operator / (const Vec &rhs) {return(divved(rhs));}
    Vec operator / (const T rhs) {return(mulled(1/rhs));}
    void operator += (const Vec &rhs) {add(rhs);}
    void operator += (const T rhs) {add(rhs);}
    void operator -= (const T rhs) {add(-rhs);}
    void operator -= (const Vec &rhs) {add(-rhs);}
    void operator *= (const Vec &rhs) {mul(rhs);}
    void operator *= (const Im<T> &rhs) {mul(rhs);}
    void operator *= (const T rhs) {mul(rhs);}
    void operator /= (const Vec &rhs) {div(rhs);}
    void operator /= (const T rhs) {mul(1/rhs);}

};

Vec::Vec() {
    
}

template<class T> Vec<T, 3> cross(const Vec<T, 3> &a, const Vec<T, 3> &b);

template<class T, int dims> class Mat {
private:

public:
    const int size = dims;

    T vals[dims][dims] = {};

    Mat();
    Mat(const Mat<T, dims> &rhs);
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
    Vec<T, dims> mulled(const Vec<T, dims> &rhs);

    //Operator overloads
    Mat operator - () {return(mulled(-1));}
    Mat operator + (const Mat &rhs) {return(added(rhs));}
    Mat operator - (const Mat &rhs) {return(added(-rhs));}
    Mat operator * (const Mat &rhs) {return(mulled(rhs));}
    Vec<T, dims> operator * (const Vec<T, dims> &rhs) {return(mulled(rhs));}
    Mat operator * (const T &rhs) {return(mulled(rhs));}
    Mat operator / (const T rhs) {return(mulled(1/rhs));}
    void operator += (const Mat &rhs) {add(rhs);}
    void operator += (const T rhs) {add(rhs);}
    void operator -= (const Mat &rhs) {add(-rhs);}
    void operator *= (const Mat &rhs) {mul(rhs);}
    void operator *= (const T rhs) {mul(rhs);}
    void operator /= (const T rhs) {mul(1/rhs);}

};

template<class T> class Im {
public:
    T r = 0;
    T i = 0;

    //Constructors
    Im();
    Im(const Im &rhs);
    Im(const Vec<T, 2> &rhs);
    Im(float angle);
    Im(T r, T i);

    //Useful
    template<class O>
    static Im<O> create(float angle);

    Im rotRad(float angle);
    Im rotDeg(float angle);

    float angleRad();
    float angleDeg();

    float mag2();
    float mag();

    float modulus();
    Im argument();

    //Arithmetic
    Im add(const Im &rhs); 
    Im add(const Vec<T, 2> &rhs);
    Im add(const T rhs);

    Im added(const Im &rhs);
    Im added(const Vec<T, 2> &rhs);
    Im added(const T rhs);

    Im mul(const Im &rhs);
    Vec<T, 2> mul(const Vec<T, 2> &rhs);
    Im mul(const T rhs);

    Im mulled(const Im &rhs);
    Vec<T, 2> mulled(const Vec<T, 2> &rhs);
    Im mulled(const T rhs);

    //Operator overloads
    Im operator - () {return(Im<T>{-r, -i});}
    Im operator + (const Im &rhs) {return(added(rhs));}
    Im operator + (const Vec<T, 2> &rhs) {return(added(rhs));}
    Im operator + (const T rhs) {return(added(rhs));}
    Im operator - (const Im &rhs) {return(added(-rhs));}
    Im operator - (const Vec<T, 2> &rhs) {return(added(-rhs));}
    Im operator - (const T rhs) {return(added(rhs));}
    Im operator * (const Im &rhs) {return(mulled(rhs));}
    Vec<T, 2> operator * (const Vec<T, 2> &rhs) {return(mulled(rhs));}
    Im operator * (const T rhs) {return(mulled(rhs));}
    Im operator / (const T rhs) {return(mulled(1/rhs));}
    void operator += (const Im &rhs) {add(rhs);}
    void operator += (const Vec<T, 2> &rhs) {add(rhs);}
    void operator += (const T rhs) {add(rhs);}
    void operator -= (const Im &rhs) {add(-rhs);}
    void operator -= (const Vec<T, 2> &rhs) {add(-rhs);}
    void operator -= (const T rhs) {add(-rhs);}
    void operator *= (const Im &rhs) {mul(rhs);}
    void operator *= (const T rhs) {mul(rhs);}
    void operator /= (const T rhs) {mul(1/rhs);}

};