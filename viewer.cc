#include <utility>
#include <functional>
#include <vector>
#include "colors.h"
#include "base.h"
using namespace std;

//VERY IMPORTANT: This number should be your screen aspect ratio (divide horizontal/vertical)
#define aspect 1.7778 //default 16:9
//how much to zoom in when using w/a
#define zoom_scale 0.1
//how many pixels to move by when using arrow keys (is also scaled by screen size and zoom, so its not really one pixel per step)
#define step_size 3


int main() {
    int rows,cols;
    long double zoom = 0.5;
    vector<complex<long double> (*)(const complex<long double>&,const complex<long double>&)> fractals = {&mandelbrot,&burning_ship,&mandelbrot3};
    size_t fractal_index = 0;
    char in_set = 'x', out_set = ' ';
    pair<int,int> term_size = get_terminal_size();
    rows = term_size.first;
    cols = term_size.second;
    double term_aspect = 1.0*cols/rows;
    double height_div = term_aspect/aspect;
    long double cur_y = 0, cur_x = 0; //origin not relative to screen
    bool redraw = true;
    set_raw_mode(true);
    long double rows_2 = 1.0*rows/2;
    long double cols_2 = 1.0*cols/2;
    while (true) {
        if (redraw) {
            show_cursor(0);
            int shh = system("clear");
            shh = shh;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    long double cal_row = ((rows_2 - 1) - i)/zoom + cur_y, cal_col = (j - (cols_2 - 1))/zoom + cur_x;
                    complex<long double> c(cal_col/(cols_2), cal_row/(rows_2)/height_div);
                    cout << (fractal(c,fractals.at(fractal_index)) ? in_set : out_set);
                }
                cout << '\n';
            }
            cout << "Iterations: " << iterations << ", Zoom: " << zoom << ", Position: " <<  '(' << cur_x << ',' << cur_y << ")\n";
            redraw = false;
            show_cursor(1);
        }
        int ch = quick_read();
        redraw = true;
        if (ch == 'w') zoom += zoom_scale*zoom;
        else if (ch == 's') zoom -= zoom_scale*zoom;
        else if (ch == RIGHT_ARROW) cur_x+=(step_size/zoom*cols/120);
        else if (ch == LEFT_ARROW) cur_x-=(step_size/zoom*cols/120);
        else if (ch == UP_ARROW) cur_y+=(step_size/zoom*rows/49);
        else if (ch == DOWN_ARROW) cur_y-=(step_size/zoom*rows/49);
        else if (ch == 'a' && iterations > 0) iterations--;
        else if (ch == 'd') iterations++;
        else if (ch == 'r') {
            cur_x = cur_y = 0;
            zoom = 0.5;
        }
        else if (ch == 'c') {
            fractal_index = (fractal_index + 1) % fractals.size();
            cur_x = cur_y = 0;
            zoom = 0.5;
            iterations = 50;
        }
        else if (ch == 'i') swap(in_set,out_set);
        else redraw = false;
        usleep(10000);
    }
}
