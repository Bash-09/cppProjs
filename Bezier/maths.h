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

    //Constructors
    Vec() {

    }
    Vec(T rhs) {
        for(int i = 0; i < dims; i++) {
            vals[i] = rhs;
        }
    }
    Vec(Vec &rhs) {
        int lim = dims;
        if(rhs.size < lim) lim = rhs.size;
        for(int i = 0; i < lim; i++) {
            vals[i] = rhs[i];
        }
    }
    Vec(const Im<T> &rhs) {
        x = rhs.r;
        y = rhs.i;
    }

    Vec(T x, T y, T z = 0, T w = 0) {
        if(dims < 1) return;
        this->x = x;
        if(dims == 1) return;
        this->y = y;
        if(dims == 2) return;
        this->z = z;
        if(dims == 3) return;
        this->w = w;

    };

    ~Vec() {}

    void print() {
        std::cout << std::endl;
        std::cout << "[";
        for(int i = 0; i < dims - 1; i++) {
            std::cout << vals[i] << ", ";
        }
        std::cout << vals[dims-1] << "]" << std::endl;
    }

    //Vector functions
    T mag2() {
        T total = 0;
        for(int i = 0; i < dims; i++) {
            total += vals[i]*vals[i];
        }
        return total;
    }
    T mag() {
        T total = 0;
        for(int i = 0; i < dims; i++) {
            total += vals[i]*vals[i];
        }
        return std::sqrt(total);
    }

    Vec normalize() {
        T s = mag();
        div(s);
    }
    float dot(const Vec &rhs) {
        if(rhs.size != dims) {
            throw "Cannot dot non-equal-sized vectors!";
            return 0;
        }
        T total = 0;
        for(int i = 0; i < dims; i++) {
            total += vals[i] * rhs.vals[i];
        }
        return total;
    }

    Vec cross(const Vec &rhs) {
        if(dims != 3 || rhs.size != 3) {
            throw "Cannot cross non 3D vectors!";
            return *this;
        }
        Vec<T, 3> out;
        out.x = y*(T)rhs.z - z*(T)rhs.y;
        out.y = z*(T)rhs.x - x*(T)rhs.z;
        out.z = x*(T)rhs.y - y*(T)rhs.x;
        return out;
    }

    //Arithmetic
    Vec add(const Vec& rhs) const {
        int lim = dims;
        if(rhs.size < lim) lim = rhs.size;
        for(int i = 0; i < lim; i++) {
            vals[i] += rhs.vals[i];
        }
        return *this;
    }
    Vec add(const Im<T>& rhs) const {
        x += rhs.r;
        if(dims < 2) return *this;
        y += rhs.i;
        return *this;
    }

    Vec added(const Vec &rhs) const {
        Vec<T, dims> out;
        int lim = dims;
        if(rhs.size < lim) lim = rhs.size;
        for(int i = 0; i < lim; i++) {
            out.vals[i] = vals[i] + rhs.vals[i];
        }
        return out;
    }
    Vec added(const Im<T> &rhs) const {
        Vec<T, dims> out;
        out.x = x + rhs.x;
        if(dims < 2) return out;
        out.y = y + rhs.y;
        return out;
    }

    Vec mul(const Vec &rhs) const {
        int lim = dims;
        if(rhs.size < lim) lim = rhs.size;
        for(int i = 0; i < lim; i++) {
            vals[i] *= rhs.vals[i];
        }
        return *this;
    }
    Vec mul(const T rhs) {
        for(int i = 0; i < dims; i++) {
            vals[i] *= rhs;
        }
        return *this;
    }
    Vec mul(const Im<T> &rhs) const {
        if(dims != 2) {
            throw "Cannot multiply non-2D Vector with complex number!";
            return *this;
        }
        T tx = x;
        T ty = y;
        x = tx * rhs.r - ty * rhs.i;
        y = tx * rhs.i + ty * rhs.r;
        return *this;
    }

    Vec mulled(const Vec &rhs) const {
        Vec<T, dims> out;
        int lim = dims;
        if(rhs.size < lim) lim = rhs.size;
        for(int i = 0; i < lim; i++) {
            out.vals[i] = vals[i] * rhs.vals[i];
        }
        return out;
    }
    Vec mulled(const T rhs) const {
        Vec<T, dims> out;
        for(int i = 0; i < dims; i++) {
            out.vals[i] = vals[i] * rhs;
        }
        return out;
    }
    Vec mulled(const Im<T> &rhs) const {
        if(dims != 2) {
            throw "Cannot multiply non-2D Vector with complex number!";
            return *this;
        }
        Vec<T, 2> out;
        out.x = x * rhs.r - y * rhs.i;
        out.y = x * rhs.i + y * rhs.r;
        return out;
    }

    Vec div(const Vec &rhs) const {
        for(int i = 0; i < dims; i++) {
            vals[i] /= rhs;
        }
        return *this;
    }

    Vec divved(const Vec &rhs) const {
        Vec<T, dims> out;
        for(int i = 0; i < dims; i++) {
            out.vals[i] = vals[i] / rhs;
        }
        return out;
    }

    //Operators
    void operator = (const Vec& rhs) {
        for(int i = 0; i < dims; i++) {
            vals[i] = rhs.vals[i];
        }
    }
    T& operator [] (int index) {return(vals[index]);}
    Vec operator - () const {return(mulled(-1));}
    Vec operator + (const Vec &rhs) const {return(added(rhs));}
    Vec operator - (const Vec &rhs) const {return(added(-rhs));}
    Vec operator * (const Vec &rhs) const {return(mulled(rhs));}
    Vec operator * (const Im<T> &rhs) const {return(mulled(rhs));}
    Vec operator * (const T &rhs) const {return(mulled(rhs));}
    Vec operator / (const Vec &rhs) const {return(divved(rhs));}
    Vec operator / (const T rhs) const {return(mulled(1/rhs));}
    void operator += (const Vec &rhs) const {add(rhs);}
    void operator += (const T rhs) const {add(rhs);}
    void operator -= (const T rhs) const {add(-rhs);}
    void operator -= (const Vec &rhs) const {add(-rhs);}
    void operator *= (const Vec &rhs) const {mul(rhs);}
    void operator *= (const Im<T> &rhs) const {mul(rhs);}
    void operator *= (const T rhs) const {mul(rhs);}
    void operator /= (const Vec &rhs) const {div(rhs);}
    void operator /= (const T rhs) const {mul(1/rhs);}

};

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