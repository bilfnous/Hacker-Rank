#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> heap;
    make_heap(heap.begin(), heap.end(), greater<int>());
    int q = 0, n = 0, v = 0;

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> n;
        switch(n){
            case 1:
                cin >> v;
                heap.push_back(v);
                push_heap(heap.begin(), heap.end(), greater<int>());
                break;
            case 2:
                {
                cin >> v;
                vector<int>::iterator it;
                for(it = heap.begin(); it != heap.end(); it++){
                    if (*it == v) {
                        heap.erase(it);
                        break;
                    }
                }
                make_heap(heap.begin(), heap.end(), greater<int>());
                }
                break;
            case 3:
                cout << heap.front() << endl;
                break;
        }

    }
    return 0;
}
