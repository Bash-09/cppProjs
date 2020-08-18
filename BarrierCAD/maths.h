#pragma once

namespace bm {

/*
 *  Vectors
 *
*/

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
    V() {

    }

    V(V &in) { //Copy data into new Vector
        for(int i = 0; i < dim; i++) {
            vals[i] = in.vals[i];
        }

        if(in.dims < dim) { //Zero any data the input vector might not contain
            for(int i = in.dims; i < dim; i++) {
                vals[i] = 0;
            }
        }
    }

    //Operator overloads
    T& operator [] (int i){
        if(i >= dims) throw "Accessing out of bounds of Vector!";
        return vals[i];
    }

    V operator + (V v) {
        V out = *this;
        int lim = dims;
        if(v.dims < dims) lim = v.dims;
        for(int i = 0; i < lim; i++) {
            out[i] += v[i];
        }
        return out;
    }

    void operator += (V in) {
        add(in);
    }

    V operator * (V v) {
        V out = *this;
        int lim = dims;
        if(v.dims < lim) lim  = v.dims;

        for(int i = 0; i < lim; i++) {
            out[i] *= v.vals[i];
        }
        return out;
    }
    V operator * (auto in) {
        V out = *this;
        for(int i = 0; i < dim; i++) {
            out[i] *= in;
        }
        return out;
    }

    void operator *= (V in) {
        mul(in);
    }

    V operator - (V in) {
        return *this * -1;
    }

    void operator -= (V in) {
        add(in * -1);
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

        for(int i = 0; i < dim; i++) {
            vals[i] /= length;
        }
        return *this;
    }

    //Scalar multiplication
    V mul(auto m) {
        for(int i = 0; i < dim; i++) {
            vals[i] *= m;
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

    //Add vectors
    V add(V v) {
        int lim = dims;
        if(v.dims < dims) lim = v.dims;
        for(int i = 0; i < lim; i++) {
            vals[i] += v[i];
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

    //Random print method to make things easy
    void print() {
        std::cout << "[";
        for(int i = 0; i < dims-1; i++) {
            std::cout << vals[i] << ", ";
        }
        std::cout << vals[dims-1] << "]" << std::endl;
    }

};

//Common vectors

class v2f : public V<float, 2> {
public:
    v2f(float val) {
        vals[0] = val;
        vals[1] = val;
    }
    v2f(float x, float y) {
        vals[0] = x;
        vals[1] = y;
    }
    v2f() {}
};
class v2i : public V<int, 2> {
public:
    v2i(int val) {
        vals[0] = val;
        vals[1] = val;
    }
    v2i(int x, int y) {
        vals[0] = x;
        vals[1] = y;
    }
    v2i() {}
};
class v2d : public V<double, 2> {
public:
    v2d(double val) {
        vals[0] = val;
        vals[1] = val;
    }
    v2d(double x, double y) {
        vals[0] = x;
        vals[1] = y;
    }
    v2d() {}
};

class v3f : public V<float, 3> {
public:
    v3f(float val) {
        vals[0] = val;
        vals[1] = val;
        vals[2] = val;
    }
    v3f(float x, float y, float z) {
        vals[0] = x;
        vals[1] = y;
        vals[2] = z;
    }
    v3f() {}
};
class v3i : public V<int, 3> {
public:
    v3i(int val) {
        vals[0] = val;
        vals[1] = val;
        vals[2] = val;
    }
    v3i(int x, int y, int z) {
        vals[0] = x;
        vals[1] = y;
        vals[2] = z;
    }
    v3i() {}
};
class v3d : public V<double, 3> {
public:
    v3d(double val) {
        vals[0] = val;
        vals[1] = val;
        vals[2] = val;
    }
    v3d(double x, double y, double z) {
        vals[0] = x;
        vals[1] = y;
        vals[2] = z;
    }
    v3d() {}
};

class v4f : public V<float, 4> {
public:
    v4f(float val) {
        vals[0] = val;
        vals[1] = val;
        vals[2] = val;
        vals[3] = val;
    }
    v4f(float x, float y, float z, float w) {
        vals[0] = x;
        vals[1] = y;
        vals[2] = z;
        vals[3] = w;
    }
    v4f() {}
};
class v4i : public V<int, 4> {
public:
    v4i(int val) {
        vals[0] = val;
        vals[1] = val;
        vals[2] = val;
        vals[3] = val;
    }
    v4i(int x, int y, int z, int w) {
        vals[0] = x;
        vals[1] = y;
        vals[2] = z;
        vals[3] = w;
    }
    v4i() {}
};
class v4d : public V<double, 4> {
public:
    v4d(double val) {
        vals[0] = val;
        vals[1] = val;
        vals[2] = val;
        vals[3] = val;
    }
    v4d(double x, double y, double z, double w) {
        vals[0] = x;
        vals[1] = y;
        vals[2] = z;
        vals[3] = w;
    }
    v4d() {}
};

template <class T> 
V<T, 3> cross(V<T, 3> a, V<T, 3> b) {
    V<T, 3> out;
    out.x = a.y*b.z - a.z*b.y;
    out.y = a.z*b.x - a.x*b.z;
    out.z = a.x*b.y - a.y*b.x;
    return out;
}



/*
 *  Matrices!!!!
 *
 *
 */
template <class T, int rowNum, int colNum> class M {
public:

    const int rows = rowNum;
    const int cols = colNum;

    T vals[rowNum][colNum] = { };

    M() {

    }

    M(T val) {
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                vals[r][c] = val;
            }
        }
    }

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



    template <M& rhs>
    M<T, rhs.rows, rhs.cols> mul() {
        M<T, this->rows, rhs.cols> outM;

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


};

class m2 : public M<float, 2, 2> {
};

/*

class m2 : public M<float, 2, 2> {
public:
    m2 mul(m2& rhs) {
        m2 out;

        return out;
    }

    m2 operator * (m2& rhs) {
        return mul(rhs);
    }
};

class m3 : public M<float, 3, 3> {
public:
    m3 mul(m3& rhs) {
        m3 out;

        return out;
    }
    m3 operator * (m3& rhs) {
        return mul(rhs);
    }
};

class m4 : public M<float, 4, 4> {
public:
    m4 mul(m4& rhs) {
        m4 out;

        return out;
    }
    m4 operator * (m4& rhs) {
        return mul(rhs);
    }
};
*/

}