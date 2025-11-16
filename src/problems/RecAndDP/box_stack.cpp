#include <vector>
#include <iostream>
#include "../../Utils/print_funcs.cpp"
using namespace std;

struct Box {
    int length;
    int depth;
    int height;
};

int get_max_height (const vector<Box>& boxes) {
    vector<int> max_height(boxes.size(), 0);
    int total_max = 0, cur_max = 0;

    for (int i=0; i<boxes.size(); ++i) {
        cur_max = 0;
        for (int j=i-1; j>=0; --j) {
            if (max_height[j] > cur_max &&
                boxes[j].height > boxes[i].height &&
                boxes[j].depth > boxes[i].depth &&
                boxes[j].length > boxes[i].length )
                cur_max = max_height[j];
        }
        max_height[i] = cur_max+boxes[i].height;
        if (max_height[i] > total_max) {
            total_max = max_height[i];
        }
    }
    print_vec(max_height);
    return total_max;
}

int main() {
    vector<Box> boxes {
        Box{5,6,4},
        Box{4,5,7},
        Box{3,3,3},
        Box{2,2,2},
    };
    cout << get_max_height(boxes) << endl;
}