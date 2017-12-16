#include <stdio.h>
#include <ctime>
#define N 400000000

using namespace std;

int memoryBank[N];
bool flag = 1;
void CasheInvestigation()
    {
    for (unsigned  int w = 1; w < 30; ++w)
    {
        for (unsigned int CasheSize = 24; CasheSize <= 24; CasheSize += 4)
        {
            unsigned int place = 0;
            for (unsigned int j = 0; j < w; ++j)
            {
                for (unsigned int i = 0; i < (1 << CasheSize); ++i)
                {
                    int r1 = j * (1 << CasheSize) + i;
                    int r2= (j + 1) * (1 << CasheSize) + i;
                    memoryBank[r1] = r2;
                }
            }
            for (unsigned int i = 0; i < (1 << CasheSize); ++i)
            {
                memoryBank[w * (1 << CasheSize) + i] = i;
            }
            unsigned long long t = clock();
            place = 0;
            for (unsigned int i = 0; i < (1 << 25); ++i)
            {
                place = memoryBank[place];
            }
            if (flag == 1)
            {
                        flag -= 1;
                    printf("%d\n", CasheSize);
                }
            printf("%d %lld \n", w, clock()-t);
        }
    }
}
int main()
{
   CasheInvestigation();
}