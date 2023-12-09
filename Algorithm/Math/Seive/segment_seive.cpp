#include<iostream>
#include<vector>
using namespace std;

#define maxSize 100000
#define low 2
#define high 30

vector<bool> mark(maxSize, false);



// *****seive nth time
void segmentedSieveNth() {
    int i, j, k, size;
    size = high - low + 1;
    mark[0] = mark[1] = true;

    for (i = 2; i <= size; i++) {
        if (mark[i] == false) {
            for (j = i * i - low; j <= size; j += i) {
                mark[j] = true;
            }
        }
    }

    for (i = low; i <= high; i++) {
        if (mark[i] == false) {
            cout << i << " ";
        }
    }
}




//******************** segment seive **************


int main() {
    

    
    return 0;
}