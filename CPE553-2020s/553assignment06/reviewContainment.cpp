
/*
 * Vehicle has a speed
 * car inherits from vehicle
 * car has an engine
 * engine has a horsepower(double)
 * car has 4 wheels
 * wheel has a tire pressure
 */
class Engine{
private:
    double horsepower;
public :
    Engine(double hp) : horsepower(hp){}
};

class wheel{
private:
    int pressure;
public:
    wheel(int p) : pressure(p){}
};
class Vehicle{
private:
    int speed;
public:
    Vehicle(int speed) : speed(speed){}
};

class Car : public Vehicle{
private:
    Engine e;
    wheel w1, w2, w3, w4;
    //wheel w[4];
public:
    Car(int speed, double hp, int p1, int p2, int p3, int p4): Vehicle(speed), e(hp), w1(p1), w2(p2), w3(p3), w4(p4){}
};
int main(){
    Car c1(55, 480, 28, 29, 31, 31);
}