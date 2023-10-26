#include <bits/stdc++.h>
using namespace std;

struct vector2Int {
    int x, y;
    vector2Int(): x(0), y(0) {}
    vector2Int(const int &x, const int &y): x(x), y(y) {}
};

struct mat3x3 {
    double mat[3][3];
    mat3x3(const initializer_list<initializer_list<double>> &lst){
        int i = 0;
        for(const initializer_list<double> &row : lst){
            int j = 0;
            for(const double &x : row){
                mat[i][j] = x;
                ++j;
            }
            ++i;
        }
    }
};

struct vector3 {
    double x, y, z;
    vector3(): x(0), y(0), z(0) {}
    vector3(const double &x, const double &y, const double &z): x(x), y(y), z(z) {}
    double dot(const vector3 &rhs){
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    void add(const vector3 &rhs){
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
    }
    void matTrans(const mat3x3 &trans){
        vector3 ans;
        ans.x = x * trans.mat[0][0] + y * trans.mat[0][1] + z * trans.mat[0][2];
        ans.y = x * trans.mat[1][0] + y * trans.mat[1][1] + z * trans.mat[1][2];
        ans.z = x * trans.mat[2][0] + y * trans.mat[2][1] + z * trans.mat[2][2];
        *this = ans;
    }
    double magnitude(){
        return sqrt(x * x + y * y + z * z);
    }
    void normalize(){
        const double magn = magnitude();
        x /= magn;
        y /= magn;
        z /= magn;
    }
};

struct mat4x4 {
    double mat[4][4];
    mat4x4(const initializer_list<initializer_list<double>> &lst){
        int i = 0;
        for(const initializer_list<double> &row : lst){
            int j = 0;
            for(const double &x : row){
                mat[i][j] = x;
                ++j;
            }
            ++i;
        }
    }
};

struct vector4 {
    double x, y, z, w;
    vector4(): x(0), y(0), z(0), w(0) {}
    vector4(const double &x, const double &y, const double &z, const double &w): x(x), y(y), z(z), w(w) {}
    void matTrans(const mat4x4 &trans){
        vector4 ans;
        ans.x = x * trans.mat[0][0] + y * trans.mat[0][1] + z * trans.mat[0][2] + w * trans.mat[0][3];
        ans.y = x * trans.mat[1][0] + y * trans.mat[1][1] + z * trans.mat[1][2] + w * trans.mat[1][3];
        ans.z = x * trans.mat[2][0] + y * trans.mat[2][1] + z * trans.mat[2][2] + w * trans.mat[2][3];
        ans.w = x * trans.mat[3][0] + y * trans.mat[3][1] + z * trans.mat[3][2] + w * trans.mat[3][3];
        *this = ans;
    }
    void scalarDiv(const double &scalar){
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
    }
};

const int W = 200;
const int H = 200;

const double PI = 3.14;
const double sqrt2 = 1.414;
const double fov = PI / 3;
const double nearClip = 0.1;
const double farClip = 1000;
const vector3 lightVect = vector3(0, sqrt2 / 2, - sqrt2 / 2);
const char chr[13] = ".,-~:;=!*#$@";

mat3x3 eulertoTrans(const vector3 &initEAngle, const vector3 &dEAngle, const double &phi, const int &frame){
    const double ax = initEAngle.x + dEAngle.x * frame;
    const double ay = initEAngle.y + dEAngle.y * frame;
    const double az = initEAngle.z + dEAngle.z * frame;
    return mat3x3({{cos(az) * cos(ay) * cos(phi) - sin(phi) * (sin(az) * sin(ax) + cos(az) * sin(ay) * cos(ax)), cos(az) * sin(ay) * sin(ax) - sin(az) * cos(ax), 0},
                   {sin(az) * cos(ay) * cos(phi) - sin(phi) * (sin(az) * sin(ay) * cos(ax) - cos(az) * sin(ax)), cos(az) * cos(ax) + sin(az) * sin(ay) * sin(ax), 0},
                   {- sin(ay) * cos(phi) - cos(ay) * cos(ax) * sin(phi), cos(ay) * sin(ax), 0}});
}

mat4x4 perspectiveTrans(const double &scrWidth, const double &scrHeight){
    const double s = 1 / tan(fov / 2);
    printf("s:%lf\n", s);
    return mat4x4({{s * scrWidth / scrHeight, 0, 0, 0},
                   {0, s, 0, 0},
                   {0, 0, farClip / (nearClip - farClip), -1},
                   {0, 0, nearClip * farClip / (nearClip - farClip), 0}});
}

double mxDepth[W + 5][H + 5], luminos[W + 5][H + 5];

int main(){

    int nFrames;
    double r1, r2, dtheta, dphi, scrWidth, scrHeight;
    vector3 initEAngle, dEAngle;
    scanf("%lf%lf%lf%lf", &r1, &r2, &dtheta, &dphi);
    scanf("%lf%lf%lf%lf%lf%lf", &initEAngle.x, &initEAngle.y, &initEAngle.z, &dEAngle.x, &dEAngle.y, &dEAngle.z);
    scanf("%lf%lf%d", &scrWidth, &scrHeight, &nFrames);

    const vector3 moveAway = vector3(0, 0, 1.5 * (r1 + r2));
    const mat4x4 perspec = perspectiveTrans(scrWidth, scrHeight);

    for(int frame = 0; frame < nFrames; ++frame){
        for(int i = 0; i < scrHeight; ++i){
            for(int j = 0; j < scrWidth; ++j){
                mxDepth[i][j] = 0;
                luminos[i][j] = 0;
            }
        }
        for(double theta = 0; theta <= 2 * PI; theta += dtheta){
            for(double phi = 0; phi <= 2 * PI; phi += dphi){
                vector3 pos = vector3(r1 * cos(theta) + r2, r1 * sin(theta), 0);
                vector3 norm = vector3(cos(theta), sin(theta), 0);
                mat3x3 trans = eulertoTrans(initEAngle, dEAngle, phi, frame);

                pos.matTrans(trans);
                pos.add(moveAway);

                vector4 perspecPos = vector4(pos.x, pos.y, pos.z, 1);
                perspecPos.matTrans(perspec);
                perspecPos.scalarDiv(perspecPos.w);
                vector2Int scrPos = vector2Int(scrWidth / 2 + perspecPos.x, scrHeight / 2 - perspecPos.y);
                if(scrPos.x < 0 || scrPos.x >= (int)scrWidth || scrPos.y < 0 || scrPos.y >= (int)scrHeight){
                    continue;
                }

                norm.matTrans(trans);
                norm.normalize();
                const double luminosity = norm.dot(lightVect);
                if(luminosity < 0){
                    continue;
                }

                const double depthVal = 1 / perspecPos.z;
                if(depthVal > mxDepth[scrPos.y][scrPos.x]){
                    mxDepth[scrPos.y][scrPos.x] = depthVal;
                    luminos[scrPos.y][scrPos.x] = luminosity;
                }
            }
        }
        for(int i = 0; i < scrHeight; ++i){
            for(int j = 0; j < scrWidth; ++j){
                if(luminos[i][j] > 0){
                    cout << chr[(int)(luminos[i][j] * 11)];
                } else {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
