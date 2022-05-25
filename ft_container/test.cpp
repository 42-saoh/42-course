#include <iostream>
#include <vector>
#include "vector.hpp"
#include <map>
#include "map.hpp"
#include <ctime>


int main()
{
    typedef std::vector<int> s_vec;
    typedef ft::vector<int> f_vec;
    clock_t t;
    t = clock();
    {
        s_vec vec;

        for (int i = 0; i < 10000; i++)
            vec.push_back(i);
        vec.erase(vec.begin() + 2500, vec.begin() + 7500);
        for (int i = 0; i < 20000; i++)
            vec.insert(vec.begin() + 2500, i);
        vec.insert(vec.begin() + 10000, 10000, 300000);
        s_vec vec1(vec);
        vec1.resize(60000, 50000);
        s_vec vec2 = vec;
        vec2.reserve(60000);
        for (int i = 35000; i < 60000; i++)
            vec2.push_back(i);
    }
    t = clock() - t;
    std::cout << t << std::endl;
    t = clock();
    {
        f_vec vec;

        for (int i = 0; i < 10000; i++)
            vec.push_back(i);
        vec.erase(vec.begin() + 2500, vec.begin() + 7500);
        for (int i = 0; i < 20000; i++)
            vec.insert(vec.begin() + 2500, i);
        vec.insert(vec.begin() + 10000, 10000, 300000);
        f_vec vec1(vec);
        vec1.resize(60000, 50000);
        f_vec vec2 = vec;
        vec2.reserve(60000);
        for (int i = 35000; i < 60000; i++)
            vec2.push_back(i);
    }
    t = clock() - t;
    std::cout << t << std::endl;
    typedef std::map<int, std::string> s_map;
    typedef ft::map<int, std::string> f_map;
    typedef std::pair<int, std::string> s_pair;
    typedef ft::pair<int, std::string> f_pair;
    t = clock();
    {
        s_map map;
        std::vector<s_pair> q;

        for (int i = 0; i < 10000; i++)
            map.insert(s_pair(i, "1"));
        s_map::iterator k = map.begin();
        s_map::iterator j = map.end();
        for (int i = 0; i < 2500; i++)
            k++;
        for (int i = 0; i < 2500; i++)
            j--;
        map.erase(k, j);
        for (int i = 2500; i < 7500; i++)
            q.push_back(s_pair(i, "1"));
        map.insert(q.begin(), q.end());
        s_map map1(map);
        s_map map2 = map1;
    }
    t = clock() - t;
    std::cout << t << std::endl;
    t = clock();
    {
        f_map map;
        std::vector<f_pair> q;

        for (int i = 0; i < 10000; i++)
            map.insert(f_pair(i, "1"));
        f_map::iterator k = map.begin();
        f_map::iterator j = map.end();
        for (int i = 0; i < 2500; i++)
            k++;
        for (int i = 0; i < 2500; i++)
            j--;
        map.erase(k, j);
        for (int i = 2500; i < 7500; i++)
            q.push_back(f_pair(i, "1"));
        map.insert(q.begin(), q.end());
        f_map map1(map);
        f_map map2 = map1;
    }
    t = clock() - t;
    std::cout << t << std::endl;
}