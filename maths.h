#pragma once

const float PI = 2*acos(0);
const float RTD = 180/PI;
const float DTR = PI/180;

namespace bm {

/*
 *  Vectors
 *
*/


template<class T> class I;

template <class T, int dim> class V {
public:
    //Shorthand and useful values
    const int dims = dim;
    T vals[dim] = { };

    T &x = vals[0];
    T &y = vals[1];
    T &z = vals[2];
    T &w = vals[3];

    T &r = vals[0];
    T &g = vals[1];
    T &b = vals[2];
    T &a = vals[3];

    //Constructors
    V(T val) {
        for(int i = 0; i < dims; i++) {
            vals[i] = val;
        }
    }
    V() {}
    V(V &in) { //Copy data into new Vector
        for(int i = 0; i < dim; i++) {
            if(i > in.dims) {
                vals[i] = 0;
            } else {
                vals[i] = in.vals[i];
            }
        }
    }
    V(I<T> &in) {
        x = in.r;
        y = in.i;
    }
    V(T x, T y) {
        if(dim == 0) return;
        this->x = x;
        if(dim == 1) return;
        this->y = y;
    }
    V(T x, T y, T z) {
        if(dim == 0) return;
        this->x = x;
        if(dim == 1) return;
        this->y = y;
        if(dim == 2) return;
        this->z = z;
    }
    V(T x, T y, T z, T w) {
        if(dim == 0) return;
        this->x = x;
        if(dim == 1) return;
        this->y = y;
        if(dim == 2) return;
        this->z = z;
        if(dim == 3) return;
        this->w = w;
    }

    //Operator overloads
    T& operator [] (int i){
        if(i >= dims) throw "Accessing out of bounds of Vector!";
        return vals[i];
    }
    V operator + (V& rhs) {
        V<T, dim> out;
        int lim = dims;
        if(rhs.dims < dims) lim = rhs.dims;
        for(int i = 0; i < lim; i++) {
            out[i] = vals[i] + rhs[i];
        }
        return out;
    }
    void operator += (V& rhs) {
        int lim = dims;
        if(rhs.dims < dims) lim = rhs.dims;
        for(int i = 0; i < lim; i++) {
            vals[i] += rhs[i];
        }
    }
    V operator - (V<T, dim> rhs) {
        V<T, dim> out;
        int lim = dims;
        if(rhs.dims < dims) lim = rhs.dims;
        for(int i = 0; i < lim; i++) {
            out[i] = vals[i] - rhs[i];
        }
        return out;
    }
    void operator -= (V rhs) {
        int lim = dims;
        if(rhs.dims < dims) lim = rhs.dims;
        for(int i = 0; i < lim; i++) {
            vals[i] -= rhs[i];
        }
    }
    V operator * (V& rhs) {
        V<T, dim> out;
        int lim = dims;
        if(rhs.dims < lim) lim  = rhs.dims;

        for(int i = 0; i < lim; i++) {
            out[i] = vals[i] * rhs.vals[i];
        }
        return out;
    }
    V operator / (V& rhs) {
        V<T, dim> out;
        int lim = dims;
        if(rhs.dims < lim) lim  = rhs.dims;

        for(int i = 0; i < lim; i++) {
            out[i] = vals[i] / rhs.vals[i];
        }
        return out;
    }
    V operator * (T& rhs) {
        V<T, dim> out;
        for(int i = 0; i < dim; i++) {
            out[i] = vals[i] * rhs;
        }
        return out;
    }
    void operator *= (T& rhs) {
        for(int i = 0; i < dim; i++) {
            vals[i] *= rhs;
        }
    }
    void operator /= (T& rhs) {
        for(int i = 0; i < dim; i++) {
            vals[i] /= rhs;
        }
    }
    V<T, 2> operator * (I<T>& rhs) {
        return {
            x * rhs.r - y * rhs.i,
            x * rhs.i + y * rhs.r
        };
    }
    void operator *= (I<T>& rhs) {
        T tx = x;
        T ty = y;
        x = tx * rhs.r - ty * rhs.i;
        y = tx * rhs.i + ty * rhs.r;
    }
    //Adding complex numbers to vector
    void operator += (I<T>& rhs) {
        x += rhs.r;
        y += rhs.i;
    }
    V<T, 2> operator - (I<T>& rhs) {
        V<T, 2> out;
        out.x = x - rhs.r;
        out.y = y - rhs.i;
        return out;
    }
    V<T, 2> operator + (I<T>& rhs) {
        V<T, 2> out;
        out.x = x + rhs.r;
        out.y = y + rhs.i;
        return out;
    }
    void operator -= (I<T>& rhs) {
        x -= rhs.r;
        y -= rhs.i;
    }

    //Length, Magnitude, normalization
    T mag2() {
        T total = 0;
        for(int i = 0; i < dim; i++) {
            total += vals[i]*vals[i];
        }
        return total;
    }
    T mag() {
        return sqrt(mag2());
    }
    V normalize() {
        T length = mag();
        if(length == 0) return *this;
        for(int i = 0; i < dim; i++) {
            vals[i] /= length;
        }
        return *this;
    }
    //Vector multiplcation
    V mul(V v) {
        int lim = dims;
        if(v.dims < lim) lim  = v.dims;

        for(int i = 0; i < lim; i++) {
            vals[i] *= v.vals[i];
        }
        return *this;
    }
    //Dot and cross products;
    float dot(V v) {
        if(v.dims != dims) {
            throw "Vector cross between incompatible dimension!";
            return 0;
        }
        float out = 0;
        for(int i = 0; i < dims; i++) {
            out += (float)vals[i] * (float)v.vals[i];
        }
        return out;
    }
    V<T, 3> cross(V v) {
        V<T, 3> out;
        out.x = y*(T)v.z - z*(T)v.y;
        out.y = z*(T)v.x - x*(T)v.z;
        out.z = x*(T)v.y - y*(T)v.x;
        return out;
    }
    //Print method to make debugging easy
    void print() {
        std::cout << "[";
        for(int i = 0; i < dims-1; i++) {
            std::cout << vals[i] << ", ";
        }
        std::cout << vals[dims-1] << "]" << std::endl;
    }

};

template <class T> 
V<T, 3> cross(V<T, 3> a, V<T, 3> b) {
    V<T, 3> out;
    out.x = a.y*b.z - a.z*b.y;
    out.y = a.z*b.x - a.x*b.z;
    out.z = a.x*b.y - a.y*b.x;
    return out;
}

//Common Vectors
typedef V<float, 2> v2f;
typedef V<float, 3> v3f;
typedef V<float, 4> v4f;
typedef V<int, 2> v2i;
typedef V<int, 3> v3i;
typedef V<int, 4> v4i;
typedef V<double, 2> v2d;
typedef V<double, 3> v3d;
typedef V<double, 4> v4d;

/*########################################################################
 *  Matrices!!!!
 */
template <class T, int rowNum, int colNum> class M {
public:
    const int rows = rowNum;
    const int cols = colNum;

    T vals[rowNum][colNum] = { };

    M() {

    }
    M(M<T, rowNum, colNum>& in) {
        set(in);
    }
    M(T val) {
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                vals[r][c] = val;
            }
        }
    }
    //Util Functions!!!
    M identity() {

        if(rows == 1) {
            for(int c = 0; c < cols-1; c++) {
                vals[0][c] = 0;
            }
            vals[0][cols-1] = 1;
            return *this;
        }

        if(rows != cols) {
            throw "No idenetity for non-square matrix!";
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(r == c) {
                    vals[r][c] = 1;
                    continue;
                }

                vals[r][c] = 0;
            }
        }

        return *this;
    }
    M zero() {
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                vals[r][c] = 0;
            }
        }
        return *this;
    }
    void print() {
        for(int r = 0; r < rows; r++) {
            std::cout << "[";
            for(int c = 0; c < cols - 1; c++) {
                std::cout << vals[r][c] << ", ";
            }
            std::cout << vals[r][cols-1] << "]" << std::endl;
        }
    }
    void set(M<T, rowNum, colNum>& rhs) {
        for(int i = 0; i < rowNum; i++) {
            for(int j = 0; j < colNum; j++) {
                vals[i][j] = rhs.vals[i][j];
            }
        }
    }
    //Multiplying!!!
    M<T, rowNum, colNum> mul(M<T, rowNum, colNum>& rhs) {
        M<T, rowNum, colNum> outM;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < rhs.cols; c++) {
                T sum = 0;
                for(int i = 0; i < rhs.rows; i++) {
                    sum += vals[r][i] * rhs.vals[i][c];
                }
                outM.vals[r][c] = sum;
            }
        }
        return outM;
    }
    V<T, rowNum> mul(V<T, colNum>& rhs) {
        V<T, rowNum> out;

        for(int i = 0; i < rowNum; i++) {
            T total = 0;
            for(int j = 0; j < colNum; j++) {
                total += vals[i][j] * rhs[j];
            }
            out[i] = total;
        }
        return out;
    }
    M<T, rowNum, colNum> mul(T rhs) {
        for(int i = 0; i < rowNum; i++) {
            for(int j = 0; j < colNum; j++) {
                vals[i][j] *= rhs;
            }
        }
    }
    //Operator Overloads!!!
    M<T, rowNum, colNum> operator * (M& rhs) {
        return mul(rhs);
    }
    V<T, rowNum> operator * (V<T, colNum>& rhs) {
        return mul(rhs);
    }
    M operator * (T rhs) {
        M<T, rowNum, colNum> out;
        for(int i = 0; i < rowNum; i++) {
           for(int j = 0; j < colNum; j++) {
                out.vals[i][j] = vals[i][j] * rhs.vals[i][j];
            } 
        }
        return out;
    }
    void operator *= (T rhs) {
        mul(rhs);
    }
    void operator *= (M<T, rowNum, colNum>& rhs) {
        M<T, rowNum, colNum> outM;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < rhs.cols; c++) {
                T sum = 0;
                for(int i = 0; i < rhs.rows; i++) {
                    sum += vals[r][i] * rhs.vals[i][c];
                }
                outM.vals[r][c] = sum;
            }
        }
        set(outM);
    }
    M operator / (T rhs) {
        M<T, rowNum, colNum> out;
        for(int i = 0; i < rowNum; i++) {
           for(int j = 0; j < colNum; j++) {
                out.vals[i][j] = vals[i][j] / rhs.vals[i][j];
            } 
        }
        return out;
    }
    void operator += (T rhs) {
        for(int i = 0; i < rowNum; i++) {
            for(int j = 0; j < colNum; j++) {
                vals[i][j] += rhs;
            }
        }
    }
    void operator -= (T rhs) {
        for(int i = 0; i < rowNum; i++) {
            for(int j = 0; j < colNum; j++) {
                vals[i][j] -= rhs;
            }
        }
    }
    void operator /= (T rhs) {
        for(int i = 0; i < rowNum; i++) {
            for(int j = 0; j < colNum; j++) {
                vals[i][j] /= rhs;
            }
        }
    }
    M operator + (M<T, rowNum, colNum>& rhs) {
        M<T, rowNum, colNum> out;
        for(int i = 0; i < rowNum; i++) {
           for(int j = 0; j < colNum; j++) {
                out.vals[i][j] = vals[i][j] + rhs.vals[i][j];
            } 
        }
        return out;
    }
    M operator - (M<T, rowNum, colNum>& rhs) {
        M<T, rowNum, colNum> out;
        for(int i = 0; i < rowNum; i++) {
           for(int j = 0; j < colNum; j++) {
                out.vals[i][j] = vals[i][j] - rhs.vals[i][j];
            } 
        }
        return out;
    }
    //Inverting!!!
    M invert() {
        if(rowNum == 2 && colNum == 2) {
            return invert2();
        } else if(rowNum == 3 && colNum == 3) {
            return invert3();
        } else if (rowNum == 4 && colNum == 4) {
            return invert4();
        } else {
            throw "Cannot invert matrix!";
        }
    }

private:
    M invert2() {
        float a = vals[0][0];
        float b = vals[0][1];
        float c = vals[1][0];
        float d = vals[1][1];

        float invDet = 1/(a*d - b*c);

        vals[0][0] = invDet * d;
        vals[0][1] = invDet * -b;
        vals[1][0] = invDet * -c;
        vals[1][1] = invDet * a;

        return *this;
    }
    M invert3() {
        T detA = vals[1][1]*vals[2][2] - vals[1][2]*vals[2][1];
        T detB = vals[1][0]*vals[2][2] - vals[1][2]*vals[2][0];
        T detC = vals[1][0]*vals[2][1] - vals[1][1]*vals[2][0];
        T detD = vals[0][1]*vals[2][2] - vals[0][2]*vals[2][1];
        T detE = vals[0][0]*vals[2][2] - vals[2][0]*vals[0][2];
        T detF = vals[0][0]*vals[2][1] - vals[0][1]*vals[2][0];
        T detG = vals[0][1]*vals[1][2] - vals[0][2]*vals[1][1];
        T detH = vals[0][0]*vals[1][2] - vals[0][2]*vals[1][0];
        T detI = vals[0][0]*vals[1][1] - vals[1][0]*vals[0][1];

        T det = vals[0][0]*vals[1][1]*vals[2][2] + vals[0][1]*vals[1][2]*vals[2][0] + vals[0][2]*vals[1][0]*vals[2][1] 
        -(vals[0][1]*vals[1][0]*vals[2][2] + vals[0][0]*vals[1][2]*vals[2][1] + vals[0][2]*vals[1][1]*vals[2][0]);

        detB *= -1;
        detD *= -1;
        detF *= -1;
        detH *= -1;

        det = 1/det;

        vals[0][0] = det * detA;
        vals[0][1] = det * detD;
        vals[0][2] = det * detG;
        vals[1][0] = det * detB;
        vals[1][1] = det * detE;
        vals[1][2] = det * detH;
        vals[2][0] = det * detC;
        vals[2][1] = det * detF;
        vals[2][2] = det * detI;

        return *this;
    }
    M invert4() {
        return *this;
    }
};

typedef M<float, 2, 2> m2;
typedef M<float, 3, 3> m3;
typedef M<float, 4, 4> m4;



/*########################################################################
 *  Complex Numbers!!!!!
 *
 *
 */
template<class T> 
class I {
public:
    T r = 0;
    T i = 0;

    I(I& in) {
        r = in.r;
        i = in.i;
    }

    I(V<T, 2>& in) {
        r = in.x;
        i = in.y;
    }

    I(float angle) {
        rotDegrees(angle);
    }

    I(T x, T y) {
        r = x;
        i = y;
    }

    //Sets this complex number to be a rotation of <angle> degrees
    I<T> rotDegrees(float angle) {
        r = cos(angle*DTR);
        i = sin(angle*DTR);
        return *this;
    }
    //Sets this complex number to be a rotation of <angle> radians
    I<T> rotRad(float angle) {
        r = cos(angle);
        i = sin(angle);
        return *this;
    }

    I<T> operator + (I<T>& rhs) {
        I<T> out;
        out.r = r + rhs.r;
        out.i = i + rhs.i;
        return out;
    }

    I<T> operator + (V<T, 2>& rhs) {
        I<T> out;
        out.r = r + rhs.x;
        out.i = i + rhs.y;
        return out;
    }

    I<T> operator - (I<T>& rhs) {
        I<T> out;
        out.r = r - rhs.r;
        out.i = i - rhs.i;
        return out;
    }

    I<T> operator - (V<T, 2>& rhs) {
        I<T> out;
        out.r = r - rhs.x;
        out.i = i - rhs.y;
        return out;
    }

    void operator += (I<T>& rhs) {
        r += rhs.r;
        i += rhs.i;
    }
    void operator += (V<T, 2>& rhs) {
        r += rhs.x;
        i += rhs.y;
    }
    void operator -= (I<T>& rhs) {
        r -= rhs.r;
        i -= rhs.i;
    }
    void operator -= (V<T, 2>& rhs) {
        r -= rhs.x;
        i -= rhs.y;
    }

    void operator *= (T& rhs) {
        r *= rhs;
        i *= rhs;
    }
    I<T> operator * (T& rhs) {
        I<T> out;
        out.r = r * rhs;
        out.i = i * rhs;
        return out;
    }
    void operator /= (T& rhs) {
        r /= rhs;
        i /= rhs;
    }
    I<T> operator / (T& rhs) {
        I<T> out;
        out.r = r / rhs;
        out.i = i / rhs;
        return out;
    }

    
    I<T> operator * (I<T> rhs) {
        return {
            r * rhs.r - i * rhs.i,
            r * rhs.i + i * rhs.r
        };
    }
    v2f operator * (v2f rhs) {
        return {
            r * rhs.x - i * rhs.y,
            r * rhs.y + i * rhs.x
        };
    }
    void operator *= (I<T> rhs) {
        T tr = r;
        T ti = i;
        r = tr * rhs.r - ti * rhs.i;
        i = tr * rhs.i + ti * rhs.r;
    }

    float angle() {
        return atan(i / r);
    }
    float angleD() {
        return angle() * DTR;
    }

    float mag2() {
        return r*r + i*i;
    }
    float mag() {
        return sqrt(mag2());
    }
    float modulus() {
        return mag();
    }
    I<T> arg() {
        i *= -1;
        return *this;
    }

};

typedef I<float> cn;


}