//Feng Liu
// Assignment # 1 CPE 593 Algorithms and Data Structures
// Spring 2020
// Instructor: Dr. Aftab Ahmad
// I certifiy that no plagiarism or cheating was done
// in doing this assignment.

// int main(){} is located in line #65.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>
#include <map>
using namespace std;
using namespace std::chrono;

class malware{
private:
    int id;
    int* list;
public:

    malware(int id): id(id){
        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<unsigned> u(0, 10);
        list = new int[11];
        list[0] = this -> id;

        for(int i = 1; i < 11; ++i){
            list[i] = u(rng);
        }
    }
    void print() const{
        for(int i = 0; i < 11; ++i){
            cout << list[i] << "\t";
        }
        cout<<endl;
    }

    bool interview() const{
        int score = 0;
        for(int i = 1; i < 11; ++i){
            score += this -> list[i];
        }
        if(score >= 70){
            cout << "Source <"<< id <<"> reported a malware with maliciousness score of <"<< score << ">." << endl;
            return true;
        }
        return false;
    }
    bool random_interview() const{
        return true;
    }
};

int selectNum(const int& n);
void select_sequential(int* step, int n, int loop);
void select_random(int* step, int n,int loop);
void run_time(int* step1, int* step2, int n,float* t1, float* t2,int loop);
void output_run_times(int* step1, int* step2, float* sequential,float* random);


int main(){
    float time_sequential[4];
    float time_random[4];

    int step1[4];
    int step2[4];
    int loop = 0;
    for(int n = 10; n <= 10000; n*=10){
        run_time(&step1[loop], &step2[loop], n, &time_sequential[loop], &time_random[loop],loop);
        ++loop;
    }

    cout << "\n#n\t\tRunTime_sequential\t\tRunTime_random\n\n";
    output_run_times(step1,step2,time_sequential,time_random);
    cout << endl;
}

int selectNum(const int& n){
    int result = 0;
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<unsigned> u(0,n);
    result = u(rng);
    return result;
}
void select_sequential(int* step, int n, int loop){//O(n)
    bool r = true;
    vector<malware> a;
    cout << "When n = " << n << " :" << endl;
    for (int i = 1; i <= n; ++i) {
        a.push_back(malware(i));
    }
    for(int i = 0; i < n; ++i){
        if(a[i].interview()){
            cout << "The source found after interviewing <" << i + 1 << "> candidates." << endl;
            r = false;
            step[loop] = i + 1;
            break;
        }
    }
    if(r){
        step[loop] += n;
        cout <<"None of the reports met the threat threshold." << endl;
    }
    cout << endl;
    a.clear();
}

void select_random(int* step, int n,int loop){
    bool r = true;
    vector<malware> a;
    int temp = n;
    cout << "When n = " << n << " :" << endl;
    for (int i = 1; i <= n; ++i) {
        a.push_back(malware(i));
    }

    for(int i = 1; i <= n; ++i){
        int random = selectNum(temp);
        --temp;
        if(a[random].interview()){
            a.erase(a.begin() + random - i - 1);
            cout << "The source found after interviewing <" << i + 1 << "> candidates." << endl;
            r = false;
            step[loop] = i + 1;
            break;
        }
    }
    if(r){
        step[loop] = n;
        cout <<"None of the reports met the threat threshold." << endl;
    }
    cout << endl;
    a.clear();
}
void run_time(int* step1, int* step2, int n,float* t1, float* t2,int loop) {

    cout << "-------------------------------------------" <<endl;
    cout << "arrays will be picked sequential one by one" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;

    auto start = high_resolution_clock::now();
    select_sequential(&step1[loop],n,loop);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    *t1 = 1.0*duration.count();

    cout << "-------------------------------------------" <<endl;
    cout << "arrays will be picked randomly one by one" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;

    start = high_resolution_clock::now();
    select_random(&step2[loop],n,loop);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    *t2 = 1.0*duration.count();
}

void output_run_times(int* step1, int* step2, float* sequential,float* random) {
    int n = 10;
    int i = 0;
    while (n <= 10000) {
        cout << n << "\t\t" << sequential[i] << "\t\t";
        cout << "\t\t" << random[i] << "\t\t" ;
        cout << endl;
        ++i;
        n *= 10;
    }
}