// fire_escape.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>

bool is_expand(int m, int n, int max_m, int max_n, int map[][7]) {
    if (m < 0 || m >= max_m) {
        return false;
    }
    else if (n < 0 || n >= max_n) {
        return false;
    } else if (map[m][n] == 0) {
        map[m][n] = 4;
        return true;
    }
    else {
        return false;
    }
}

void get_fire_map(int map[][7], int m, int n, std::map<std::pair<int, int>, int>& fire_map) {
    std::vector<std::pair<int, int>> fir_point_vec;
    // init
    int time = 0;
    int start = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                std::pair<int, int> temp = { i, j };
                fire_map[temp] = time;
                fir_point_vec.push_back(std::move(temp));            
            }
        }
    }
    // expand
    while (true) {
        time++;
        std::vector<std::pair<int, int>> fir_point_vec_temp;
        for (int i = start; i < fir_point_vec.size(); i++) {
            int x = fir_point_vec[i].first;
            int y = fir_point_vec[i].second;
            for (int gap_x = -1; gap_x < 2; gap_x ++) {
                for (int gap_y = -1; gap_y < 2; gap_y ++) {
                    if (abs(gap_x) + abs(gap_y) != 1) {
                        continue;
                    }
                    if (is_expand(x + gap_x, y + gap_y, m, n, map)) {
                        std::pair<int, int> temp = { x + gap_x, y + gap_y };
                        fire_map[temp] = time;
                        fir_point_vec_temp.push_back(std::move(temp));
                    }
                }
            }
        }
        if (fir_point_vec_temp.size() == 0) {
            break;
        }
        fir_point_vec.clear();
        fir_point_vec = fir_point_vec_temp;
        start = 0;
    }
}

bool is_valid(int i, int j, int map[][7], int m, int n, std::map<std::pair<int, int>, int>& fire_map) {
    std::pair<int, int> temp = { i, j };
    if (i < 0 || i >= m) { // 不可越界
        return false;
    }
    else if (j < 0 || j >= n) { //不可越界
        return false;
    }
    else if (map[m][n] == 2) { // 不可撞
        return true;
    }
    else if (fire_map[temp] < 0) { // 时间
        return false;
    } 

    return true;
}

int search_path(int i, int j,int map[][7], int m, int n, std::map<std::pair<int, int>, int>& fire_map,int chain_minite, int max_mimite) {
    if (i == 4 && j == 5) {
        std::pair <int, int> temp = { i, j };
        return std::max(max_mimite, std::min(chain_minite, fire_map[temp]));
    }
    for (auto& o : fire_map) {
        o.second -= 1;
    }


    if (is_valid(i, j - 1, map, m, n, fire_map)) {
        
        int minites = search_path(i, j - 1, map, m, n, fire_map, chain_minite, max_mimite);
        max_mimite = std::max(minites, max_mimite);
    }
    if (is_valid(i, j + 1, map, m, n, fire_map)) {
        int minites = search_path(i, j - 1, map, m, n, fire_map, chain_minite, max_mimite);
        max_mimite = std::max(minites, max_mimite);
    }
    if (is_valid(i - 1, j, map, m, n, fire_map)) {
        int minites = search_path(i, j - 1, map, m, n, fire_map, chain_minite, max_mimite);
        max_mimite = std::max(minites, max_mimite);
    }
    if (is_valid(i + 1, j, map, m, n, fire_map)) {
        int minites = search_path(i, j - 1, map, m, n, fire_map, chain_minite, max_mimite);
        max_mimite = std::max(minites, max_mimite);
    }
    return max_mimite;
}

int main()
{
    std::map<std::pair<int, int>, int> fire_map;
    int grid[5][7] = {{0, 2, 0, 0, 0, 0, 0},
                       {0, 0, 0, 2, 2, 1, 0},
                       {0, 2, 0, 0, 1, 2, 0},
                       {0, 0, 2, 2, 2, 0, 2},
                       {0, 0, 0, 0, 0, 0, 0}};
    int grid_test[5][7] = { 1 };
    std::memcpy(grid_test, grid, sizeof(grid));
    get_fire_map(grid_test, 5, 7, fire_map);

    std::cout << grid << std::endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
