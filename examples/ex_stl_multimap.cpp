/* Parse every word and it's position into multimap. */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

typedef std::pair<std::string, int> wp_pair;
std::multimap<std::string, int>  mmap = {};

const char *text = "An iterator type whose category, value, difference, pointer and"
                   "reference types are the same as iterator. This iterator"
                   "can be used to iterate through a single bucket but not across buckets\0";

#define MAX_WORD_LEN 100
static void count()
{
    int pos = 0;
    int wpos = 0;
    char wordbuf[MAX_WORD_LEN];
    std::ifstream in("../static/sample.txt");
    char c;
    int maxcnt = 0;

    while (1)
    {
        c = text[pos];
        c = tolower(c);

        if (c == EOF || c == '\0')
        {
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
                mmap.insert(wp_pair(wordbuf, pos));
            }
            wpos = 0;
        }

        pos++;
    }


    printf("%-20s %-20s\n", "Word", "Position");
    printf("======================================\n");
    for (auto elem : mmap)
    {
        printf("%-20s %-20d\n", elem.first.c_str(), elem.second);
    }
}

int main()
{
    count();
}