#include <bits/stdc++.h>
using namespace std;

const int screenwidth = 155;
const int screenheight = 41;
const int swo = screenwidth/2;
const int sho = screenheight/2;

void draw(char **graph) {
    for (int i = 0; i < screenheight; ++i) {
        for (int j = 0; j < screenwidth; ++j) {
            printf("%c",graph[i][j]);
        }
        printf("\n");
    }
    return;
}

void axis(char **graph, int label) {
    for (int i = 0; i < screenwidth; ++i) {
        graph[sho][i] = '-';
    }
    for (int i = 0; i < screenheight; ++i) {
        graph[i][swo] = '|';
    }
    graph[sho][swo] = '+';
    if (label == 0) {
        return;
    }
    for (int i = 2*label; i <= screenwidth/2; i += 2*label) {
        graph[sho][swo+i] = '+';
        graph[sho][swo-i] = '+';
    }
    for (int i = label; i <= screenheight/2; i += label) {
        graph[sho+i][swo] = '+';
        graph[sho-i][swo] = '+';
    }
    return;
}

bool write(char **graph, int x, int y, char c) {
    x = swo+2*x;
    y = sho-y;
    if (y < 0 || y >= screenheight || x < 0 || x >= screenwidth) {return 0;}
    graph[y][x] = c;
    return 1;
}
bool plotpoint(char **graph, double mod, double x, double y, char c) {
    bool valid = write(graph,int(round(x/mod)),int(round(y/mod)),c);
    return valid;
}

int main() {
    double scale;
    printf("scale (default 20)\n> ");
    scanf("%lf",&scale);
    int label;
    printf("axis labels scale (0 for none)\n> ");
    scanf("%d",&label);
    double mod = double(scale)/20;
    char *graph[screenwidth];
    for (int i = 0; i < screenheight; ++i) {
        graph[i] = new char[screenwidth];
        for (int j = 0; j < screenwidth; ++j) {
            graph[i][j] = ' ';
        }
    }
    axis(graph,label);
    for (;;) {
        char cmd[50];
        printf("commands;\n- point\n- line\n- draw\n- end\n> ");
        scanf(" %[^\n]",cmd);
        if (strcmp(cmd,"point") == 0) {
            double xin, yin;
            char chin;
            for (;;) {
                printf("- plot a point; format: <x> <y> <char>\n- back\n> ");
                scanf(" %[back] %lf%lf %c",cmd,&xin,&yin,&chin);
                if (strcmp(cmd,"back") == 0) {
                    break;
                }
                if (plotpoint(graph,mod,xin,yin,chin) == 0) {
                    printf("point is out of bounds, anyhow\n");
                } else {
                    printf("plotted\n");
                }
                printf("|%s|",cmd);
            }
        }
        printf("|%s|",cmd);
    }
    plotpoint(graph,mod,-3,-7,'A');
    draw(graph);
    return 0;
}
