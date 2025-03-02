#include <iostream>
using namespace std;

int main() {
    int length, width, height;

    // 输入长方体的长、宽、高
    cout << "请输入长方体的长度: ";
    cin >> length;
    cout << "请输入长方体的宽度: ";
    cin >> width;
    cout << "请输入长方体的高度: ";
    cin >> height;

    // 输出长方体的顶部
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // 输出长方体的侧面
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    // 输出长方体的底部
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
