#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


void transfer(stack<long>& from, stack<long>& to){
    while(from.empty() == false){
        to.push(from.top());
        from.pop();
    }
}

int main() {
    stack<long> outstack;
    stack<long> instack;

    int q;
    cin >> q;
    for(int i=0; i < q; i++){
        int type;
        long param;
        cin >> type;
        switch(type){
            case 1:  // enqueue
                cin >> param;
                instack.push(param);
                break;
            case 2:  // dequeue
                if (outstack.empty()){
                    transfer(instack, outstack);
                }
                outstack.pop();
                break;
            case 3:  // print front element (guaranteed to exist)
                if (outstack.empty()){
                    transfer(instack, outstack);
                }
                cout << outstack.top() << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
