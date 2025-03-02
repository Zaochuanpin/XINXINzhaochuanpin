#include <iostream>
using namespace std;

int main() {
    int side;

    // 输入正方体的边长
    cout << "请输入正方体的边长: ";
    cin >> side;

    // 输出正方体的顶部
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // 输出正方体的侧面
    for (int i = 0; i < side - 2; i++) {
        for (int j = 0; j < side; j++) {
            if (j == 0 || j == side - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    // 输出正方体的底部
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
