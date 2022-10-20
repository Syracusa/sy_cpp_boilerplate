#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> umap = {};

const char *text = "An iterator type whose category, value, difference, pointer and"
                   "reference types are the same as iterator. This iterator"
                   "can be used to iterate through a single bucket but not across buckets";

#define FROMFILE 1

#define MAX_WORD_LEN 100
static void count()
{
    int pos = 0;
    int wpos = 0;
    char wordbuf[MAX_WORD_LEN];
    std::ifstream in("../static/sample.txt");
    int out = 0;
    char c;

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

        char c = text[pos];
#endif
        c = tolower(c);

        switch (c)
        {
        case '\0':
        {
            out = 1;
            break;
        }
        case ' ':
        {
            if (wpos != 0)
            {
                wordbuf[wpos] = '\0';
                if (umap[wordbuf])
                {
                    umap[wordbuf] += 1;
                }
                else
                {
                    umap[wordbuf] = 1;
                }
            }
            wpos = 0;
            break;
        }
        case '.':
        case '!':
        case '?':
        case ':':
        case ',':
            break;
        default:
            wordbuf[wpos] = c;
            wpos++;
            break;
        }

        if (out)
            break;
        pos++;
    }
#if FROMFILE
    in.close();
#endif
    for (auto elem : umap)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }
}

int main()
{
    count();
}