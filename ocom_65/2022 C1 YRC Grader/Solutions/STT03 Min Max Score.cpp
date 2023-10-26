#include <bits/stdc++.h>
using namespace std;

struct person {
    char *room, *name;
    int number;
    double gpa;
    person(): room(NULL), name(NULL), number(0), gpa(0) {}
    person(const char *r, const char *n, int no, double g): number(no), gpa(g) {
        room = new char[strlen(r)];
        strcpy(room, r);
        name = new char[strlen(n)];
        strcpy(name, n);
    }
    bool operator < (const person &rhs) const {
        if(gpa != rhs.gpa){
            return gpa < rhs.gpa;
        } else {
            int t = strcmp(room, rhs.room);
            if(t != 0){
                return t < 0;
            } else if(number != rhs.number){
                return number < rhs.number;
            }
        }
        return strcmp(name, rhs.name) < 0;
    }
};

const int LR = 10;
const int LN = 100;

char room[LR + 5], name[LN + 5];

int main(){

    char cmd;
    person mn = person("", "", 0, 1e308);
    person mx = person("", "", 0, 0);
    double sum = 0;
    int n = 0;
    do {
        int no;
        double gpa;
        scanf("%s%d%s%lf", room, &no, name, &gpa);
        person p = person(room, name, no, gpa);
        if(p < mn){
            mn = p;
        }
        if(mx < p){
            mx = p;
        }
        sum += gpa;
        ++n;
        scanf(" %c", &cmd);
    } while(cmd == 'Y' || cmd == 'y');
    printf("%.2lf\n", sum / n);
    printf("MAX : Name : %s Classroom : %s Number : %d GPA : %.2lf\n", mx.name, mx.room, mx.number, mx.gpa);
    printf("MIN : Name : %s Classroom : %s Number : %d GPA : %.2lf", mn.name, mn.room, mn.number, mn.gpa);

    return 0;
}
