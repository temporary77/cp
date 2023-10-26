#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct vec2 {
    double x, y;
};

struct vec3 {
    double x, y, z;
};

struct vec4 {
    double x, y, z, w;
};

const double nc = 0.1, fc = 1000;
const double sqrt2 = 1.414;
const double pi = 3.14;
const double fov = pi/3;
const char charset[20] = ".,-~:;=!*#$@";

vec3 getRotatedPoint(vec2 point, double phi, double a, double b, double c) {
    vec3 rotated =
    {
        .x = point.x*(cos(c)*cos(b)*cos(phi)-sin(phi)*(sin(c)*sin(a)+cos(c)*sin(b)*cos(a))) + point.y*(cos(c)*sin(b)*sin(a)-sin(c)*cos(a)),
        .y = point.x*(sin(c)*cos(b)*cos(phi)-sin(phi)*(sin(c)*sin(b)*cos(a)-cos(c)*sin(a))) + point.y*(cos(c)*cos(a)+sin(c)*sin(b)*sin(a)),
        .z = point.x*(-sin(b)*cos(phi)-cos(b)*cos(a)*sin(phi)) + point.y*cos(b)*sin(a)
    };

    return rotated;
}

vec3 getPerspectiveMatrix(vec4 projection, double S, double A, double nc, double fc) {
    double w1 = projection.w;
    vec4 perspective =
    {
        .x = projection.x*(S/A),
        .y = projection.y*S,
        .z = projection.z*(fc/((nc-fc)))-1,
        .w = projection.z*(nc*fc/((nc-fc)))
    };
    perspective = {perspective.x/perspective.w,perspective.y/perspective.w,perspective.z/perspective.w,perspective.w/perspective.w};
    vec3 storage = {perspective.x,perspective.y,perspective.z};
    return storage;
}
int main() {

    double r1, r2, t, p, xi, yi, zi, xd, yd, zd, sw, sh, f;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&r1,&r2,&t,&p,&xi,&yi,&zi,&xd,&yd,&zd,&sw,&sh,&f);
    for (int frame = 0; frame < f; ++frame) {
        double depthbuffer[201][201] = {}, framebuffer[201][201] = {};
        for (double theta = 0; theta <= 2*pi; theta += t) {
            vec2 crclpoint = {r1*cos(theta)+r2,r1*sin(theta)};
            vec2 nrml = {cos(theta),sin(theta)};
            for (double phi = 0; phi <= 2*pi; phi += p) {

                vec3 crclpointd = getRotatedPoint(crclpoint,phi,xi+frame*xd,yi+frame*yd,zi+frame*zd);

                crclpointd = {crclpointd.x,crclpointd.y,crclpointd.z+1.5*(r1+r2)};

                vec3 nrmld = getRotatedPoint(nrml,phi,xi+frame*xd,yi+frame*yd,zi+frame*zd);

                vec3 storage = getPerspectiveMatrix({crclpointd.x,crclpointd.y,crclpointd.z,1},1/(tan(fov/2)),sh/sw,nc,fc);

                double absolutenrmld = sqrt(nrmld.x*nrmld.x+nrmld.y*nrmld.y+nrmld.z*nrmld.z);

                vec3 nrmlupsymbold = {nrmld.x/absolutenrmld,nrmld.y/absolutenrmld,nrmld.z/absolutenrmld};

                double L = 0*nrmlupsymbold.x+sqrt2/2*nrmlupsymbold.y-sqrt2/2*nrmlupsymbold.z;

                int scrx = int(sw/2+storage.x);

                int scry = int(sh/2-storage.y);

                if (scrx < 0 || scrx >= sw || scry < 0 || scry >= sh || L < 0) {
                    continue;
                }
                if (1/storage.z > depthbuffer[scry][scrx]) {
                    depthbuffer[scry][scrx] = 1/storage.z;
                    framebuffer[scry][scrx] = L;
                }
            }
        }
        for (int y = 0; y < sh; ++y) {
            for (int x = 0; x < sw; ++x) {
                double brightness = framebuffer[y][x];
                char pixel;
                if (framebuffer[y][x] > 0) {
                    pixel = charset[int(brightness*11)];
                } else {
                    pixel = ' ';
                }
                printf("%c",pixel);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
