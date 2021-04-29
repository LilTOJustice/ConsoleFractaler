#include <colors.h>
#include <utility>
#include "Complex.h"
using namespace std;

//how many time to iterate mandelbrot (higher number = more precision)
size_t iterations = 20;
//Radius to determine whether that value of C tends towards infinity
#define max_radius 2
//how much to zoom in when using w/a
#define zoom_scale 0.1
//how many pixels to move by when using arrow keys (is also scaled by screen size and zoom)
#define step_size 3

bool mandelbrot_test(const Complex &c) {
    Complex result;
    for (size_t i = 0; i < iterations; i++) {
        result = (result ^ 2) + c;
    }
    return (result.real - c.real)*(result.real - c.real) + (result.imagine.coeff - c.imagine.coeff)*(result.imagine.coeff - c.imagine.coeff) < max_radius*max_radius;
}

int main() {
    int rows,cols;
    double zoom = 0.5;
    char in_set = 'x', out_set = ' ';
    pair<int,int> term_size = get_terminal_size();
    rows = term_size.first;
    cols = term_size.second;
    double cur_y = 0, cur_x = 0; //origin not relative to screen
    bool redraw = true;
    set_raw_mode(true);
    while (true) {
        if (redraw) {
            system("clear");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    double cal_row = ((rows/2 - 1) - i)/zoom + cur_y, cal_col = (j - (cols/2 - 1))/zoom + cur_x;
                    Complex c(cal_col/(cols/2), cal_row/(rows/2));
                    cout << (mandelbrot_test(c) ? in_set : out_set);
                }
                cout << '\n';
            }
            cout << "Iterations: " << iterations << ", Zoom: " << zoom << ", Position: " <<  '(' << cur_x << ',' << cur_y << ")\n";
            redraw = false;
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
        else if (ch == 'i') swap(in_set,out_set);
        else redraw = false;
    }
}
