#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#define  blockSize 4096
#include <algorithm>
using namespace std;
using namespace chrono;
ofstream strm("/home/nestyme/Рабочий стол/МВС/output.txt");
double blockReading(unsigned int *data, unsigned int n,
                    unsigned int cnt,
                    unsigned int block_size = blockSize) {
	steady_clock::time_point begin = steady_clock::now();
    	for (auto j = 0; j < n; j += block_size) {
            unsigned int s = 0;
		    for (auto k = j; k < j + cnt; ++k) {
			    s += data[k];
		    }
	}
	steady_clock::time_point end = steady_clock::now();
	auto PassedTime = duration_cast<microseconds>(end - begin).count();
	strm << "разница во времени (в тактах работы) = " << PassedTime <<endl;
	return PassedTime;
}


void readDataBlocks()
{
    unsigned int n;
    n = 1 << 27;
    auto * data = (unsigned int *)calloc(n, sizeof(int));
    int i;
    for (i = 0; i < n; ++i) {
        data[i] = rand() % 100;
    }

    for (auto cnt = 1; cnt <= 65; ++cnt) {
        vector<double> seconds;
        unsigned int i1;
        i1 = 100;
        double s;
        s = 0;
        for (auto i = 0; i < i1; ++i) {
            auto t = blockReading(data, n, cnt);
            seconds.push_back(t);
            s += t;
        }
        s /= i1;

        strm << cnt << " " << s << endl;
    }
}

int main()
{
    readDataBlocks();
}