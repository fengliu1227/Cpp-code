#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
/*  HW5A- Shapes
 *  Author : Feng Liu
 */
/*
	suggestion:
for this assignment:
  */
class Shape{
public:
    double x;
    double y;
    Shape(double x, double y): x(x), y(y){}
    virtual void draw(ostream& s) = 0;
};

class Polygon : public Shape{
private:
    double r;
    int n;
    const double PI = 3.14159265359;
public:
    Polygon(double x, double y, double r, int n) : Shape(x, y), r(r), n(n) {}
    void draw(ostream&/* type */ s) {
        double theta01 = (n - 2) * PI / n;
        double theta02 = theta01 / 2;
        double theta03 = PI / 2 - theta02;
        double theta04 = this -> PI * 2 / n;
        s << x + r * sin(theta03) << " " << y - r * cos(theta03) << " moveto" << endl;
        for (int i = 1; i < this -> n; i ++) {
            theta03 = theta04 + theta03;
            s << x + r * sin(theta03) << " " << this -> y - this -> r * cos(theta03) << " lineto" << endl;
        }
        s << "closepath" << endl;
        s << "stroke" << endl;
    }
};

class Circle : public Shape{
private:
    double r;
public:
    Circle(double x,double y,double r): Shape(x,y),r(r){}
    void draw(ostream& s) {
        s << x << " " << y << " " << r << " " << 0 << " " << 360 << " " << "arc stroke" << endl;
    }

};

class Line : public Shape{
private:
    double x2;
    double y2;
public:
    Line(double x, double y, double x2, double y2) : Shape(x,y), x2(x2), y2(y2){}
    void draw(ostream& s){
        s << x << " " << y << " " << "moveto" << endl;
        s << x2 << " " << y2 << " " << "lineto" << endl;
        s << "stroke" << endl;
    }
};

class FilledRect : public Shape{
private:
    double w;
    double h;
public:
    FilledRect(double x, double y, double width, double height) : Shape(x,y), w(width), h(height){}
    void draw (ostream& s){
        s << x << " " << y << " " << "moveto" << endl;
        s << x + w << " " << y << " " << "lineto" << endl;
        s << x + w << " " << y + h << " " << "lineto" << endl;
        s << x << " " << y + h << " " << "lineto" << endl;
        s << "closepath" << endl;
        s << "fill" << endl;
    }
};

class Rect : public Shape{
private:
    double w;
    double h;
public:
    Rect(double x, double y, double width, double height) : Shape(x,y), w(width), h(height){}
    void draw(ostream& s){
        s << x << " " << y << " " << "moveto" << endl;
        s << x + w << " " << y << " " << "lineto" << endl;
        s << x + w << " " << y + h << " " << "lineto" << endl;
        s << x << " " << y + h << " " << "lineto" << endl;
        s << "closepath" << endl;
        s << "stroke" << endl;
    }

};

class FilledCircle : public Shape{
private:
    double r;
public:
    FilledCircle(double x,double y,double r): Shape(x,y),r(r){}
    void draw(ostream& s) {
        s << x << " " << y << " " << r << " " << 0 << " " << 360 << " " << "arc fill" << endl;
    }

};
class Drawing{
private:
	ofstream f;
	vector<Shape*> shapes;
	int loop = 0;
	int a, b, c;
public:
	Drawing(string filename) : f(filename.c_str()), shapes(){
	}
	void add( Shape* s ) {
    shapes.push_back(s);
	}

	void draw() {
	    int numShapes = shapes.size();
		for (int i = 0; i < numShapes; i++) {
            shapes[i]->draw(f);

            if (i == 7){
                f << a << " " << b << " " << c << " " << "setrgbcolor" << endl;
            }
        }

	}

	void setrgb (int a, int b, int c){
	    if(loop == 0){
            f << a << " " << b << " " << c << " " << "setrgbcolor" << endl;
            ++loop;
	    }
	     this -> a = a; this -> b = b; this -> c = c;
	}
};


int main() {
	ofstream f();
	Drawing d("test2.ps");
	d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
	d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
	d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
	for (int x = 0; x < 600; x += 100)
		d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
	d.setrgb(0,1,0); // the rest are green

	d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
	d.add(new Line(400,500, 600,550));
	d.add(new Polygon(200,200, 50, 6));
	d.draw();
}
