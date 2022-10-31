/* Count word appearence in text. With unordered_map*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "performance.h"

std::unordered_map<std::string, int> umap = {};

const char *text = "An iterator type whose category, value, difference, pointer and"
                   "reference types are the same as iterator. This iterator"
                   "can be used to iterate through a single bucket but not across buckets\0";

#define FROMFILE 1

#define MAX_WORD_LEN 100
static void count()
{
    TIME_MEASURE_START(umap);

    int pos = 0;
    int wpos = 0;
    char wordbuf[MAX_WORD_LEN];
    std::ifstream in("../static/sample.txt");
    char c;
    int maxcnt = 0;

#if FROMFILE
    if (!in.is_open())
    {
        std::cerr << "Can't open file\n";
        return;
    }

    while (in.good())
    {
        in.get(c);
#else
    while (1)
    {
        c = text[pos];
#endif
        c = tolower(c);

        if (c == EOF || c == '\0')
        {
            std::cout << "EOF!\n";
            break;
        }
        else if ('a' <= c && c <= 'z')
        {
            wordbuf[wpos] = c;
            wpos++;
        }
        else if (c == ' ')
        {
            if (wpos != 0)
            {
                wordbuf[wpos] = '\0';
                if (umap[wordbuf])
                {
                    umap[wordbuf] += 1;
                    if (maxcnt < umap[wordbuf]){
                        maxcnt = umap[wordbuf];
                    }
                }
                else
                {
                    umap[wordbuf] = 1;
                }
            }
            wpos = 0;
        }

        pos++;
    }

#if FROMFILE
    in.close();
#endif
    printf("%-20s %-20s\n", "Word", "Count");
    printf("======================================\n");
    for (auto elem : umap)
    {       
        if (elem.second > maxcnt / 10)
            printf("%-20s %-20d\n", elem.first.c_str(), elem.second);
    }
    
    TIME_MEASURE_END(umap); 
}

int main()
{
    count();
}