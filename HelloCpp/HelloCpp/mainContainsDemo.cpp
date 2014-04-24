//
//  mainContainsDemo.cpp
//  HelloCpp
//
//  Created by Hanson on 14-1-27.
//  Copyright (c) 2014年 Hanson. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

int main() {

    int k = 1;
    int v1 = 10;
    int v2 = 20;
    int v3 = 30;
//    std::vector<int> v = {1,2};
    std::map<int, std::vector<int>> map;
    map[k].push_back(100);
    map[k].push_back(200);
    
//    map.insert({k,v});
    
//    std::vector<int> av = map[k];
////    map.insert({1,{11,22}});
//    auto ret = map.insert({k,v});
//    if (!ret.second) {
//        (ret.first)->second.push_back(1);
//        (ret.first)->second.push_back(2);
//        std::cout << "失败" << std::endl;
//    } else {
//        std::cout << "成功" << std::endl;
//    }
//    
//    auto r = map.insert({k,{200}});
//    if (!r.second) {
//        (r.first)->second.push_back(100);
//    }
    
//    (r.first)->second.push_back(100);s
//    av = map[k];
//    av.push_back(100);
//    std::cout << av.size() << std::endl;
    
//    for (int i = 0; i < av.size(); i++) {
//        std::cout << av[i] << ",";
//    }
//    std::cout << std::endl;
    
    for (int j = 0; j < map[k].size(); j++) {
        std::cout << map[k][j] << ",";
    }
    
    std::cout << std::endl;
    
//    for (const auto &pair : map) {
//        std::cout << pair.first << ": " << pair.second.size() << '\n';
//    }
    
    return 0;
}