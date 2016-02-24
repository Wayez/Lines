#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	if (x0 > x1){
		draw_line(x1, y1, x0, y0, s, c);
	}
	else {
		int slope, x, y, A, B, d;
		x = x0;
		y = y0;
		A = y1 - y0;
		B = -(x1 - x0);
		slope = find_slope(x0, y0, x1, y1);
		if (slope == 1){
			d = 2 * A + B;
			while (x <= x1){
				plot(s, c, x, y);
				if (d > 0){
					y += 1;
					d += 2 * B;
				}
				x += 1;
				d += 2 * A;
			}
		}
		if (slope == 2){
			d = A + 2 * B;
			while (y <= y1){
				plot(s, c, x, y);
				if (d < 0){
					x += 1;
					d += 2 * A;
				}
				y += 1;
				d += 2 * B;
			}
		}
		if (slope == 3){
			d = A - 2 * B;
			while (y >= y1){
				plot(s, c, x, y);
				if (d > 0){
					x += 1;
					d -= 2 * A;
				}
				y -= 1;
				d += 2 * B;
			}
		}
		if (slope == 4){
			d = 2 * A - B;
			while (x <= x1){
				plot(s, c, x, y);
				if (d > 0){
					y -= 1;
					d += 2 * B;
				}
				x += 1;
				d -= 2 * A;
			}
		}
	}
}

int find_slope(int x0, int y0, int x1, int y1){
	double m;
	if (x1 == x0){
		return 2;
	}
	m = (y1 - y0) / (x1 - x0);
	if (m >= 0 && m < 1){
		return 1;
	}
	if (m >= 1){
		return 2;
	}
	if (m < 0 && m >= -1){
		return 4;
	}
	return 3;
}

