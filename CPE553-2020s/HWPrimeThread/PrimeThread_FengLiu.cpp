#include <iostream>
#include <thread>
#include <unistd.h>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

uint32_t count1;
uint32_t count2;
const long long N = 1e7;
int prime[N];
bool is_prime[N];

void countPrimes(uint32_t a, uint32_t b, uint32_t* primeCount) {
	uint32_t count = 0;
	// write your prime number count code here...
    memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	if(a <= 2){
        for(int i = a; i <= b; i ++){
            if(is_prime[i]){
                ++count;
                for(int j = 2 * i; j <= b; j += i){
                    is_prime[j] = false;
                }
            }
        }
	}
	else{
	    for(int i = 2; i <= b; ++i){
            if(is_prime[i]){
                for(int j = 2 * i; j <= b; j += i){
                    is_prime[j] = false;
                }
            }
        }
	    for(int i = a; i <= b; ++i){
	        if(is_prime[i]){
	            ++count;
	        }
	    }
	}
  (*primeCount) = count;

}



int main() {
//   benchmark how long countPrimes takes for a single thread
	const uint32_t n = 1000000;
	auto start1 = high_resolution_clock::now();
	countPrimes(1,  n, &count1);
	auto stop1 = high_resolution_clock::now();
	auto time1 = duration_cast<microseconds>(stop1 - start1);
	double runningtime1 = 1.0 * time1.count();
    cout << count1 << '\n';

	count1 = 0;
//	 now benchmark with 2 threads
    auto start2 = high_resolution_clock::now();
	thread t1( countPrimes, 1,  n/2, &count1);
	thread t2( countPrimes, n/2+1, n, &count2 );
	auto stop2 = high_resolution_clock::now();
	auto time2 = duration_cast<microseconds>(stop2 - start2);
	double runningtime2 = 1.0 * time2.count();

	t1.join();
	t2.join();
	cout << count1 + count2 << '\n';

	cout << "The running time for one thread:  " << runningtime1 << "\n\n";
	cout << "the running time for two threads: " << runningtime2 << "\n";
}