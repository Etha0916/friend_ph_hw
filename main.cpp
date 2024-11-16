#include <iostream>
#include <vector>
#include <cmath>

// 這個是用來更新速度的函式
template <typename T>
void updateVelocities(T& v1, T& v2, T m, T M) {
    T new_v1 = ((m - M) / (m + M)) * v1 + ((2 * M) / (m + M)) * v2;
    T new_v2 = ((2 * m) / (m + M)) * v1 + ((M - m) / (m + M)) * v2;
    v1 = new_v1;
    v2 = new_v2;
}

int main() {
    // 設定初始條件
    double m = 1.0; // 小物體的質量
    double M = 100.0 * m; // 大物體的質量
    std::vector<double> velocities = {0.0, -1.0}; // 初速度 {v1, v2}
    int collisionCount = 0; // 碰撞次數計數器

    // 開始模擬碰撞
    while (velocities[1] <= 0) {
        // 更新速度
        updateVelocities(velocities[0], velocities[1], m, M);

        // 模擬小物體碰到牆後反彈
        velocities[0] = -velocities[0];

        // 輸出每次碰撞後的速度
       // std::cout << "碰撞 " << collisionCount + 1 << ": v1 = " << velocities[0] << ", v2 = " << velocities[1] << std::endl;
       //第30行是用來檢查每次速度的回傳值(debug用

        collisionCount++; // 增加碰撞次數計數器
    }

    // 輸出總共需要的碰撞次數
    std::cout << "需要的碰撞次數: " << collisionCount << std::endl;

    return 0;
}
