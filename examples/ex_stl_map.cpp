#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> umap = {};

const char* text = "Lorem ipsum dolor sit amet,"
" consectetur adipiscing elit, sed do eiusmod tempor"
" incididunt ut labore et dolore magna aliqua. Ut enim"
" ad minim veniam, quis nostrud exercitation ullamco"
" laboris nisi ut aliquip ex ea commodo consequat. "
"Duis aute irure dolor in reprehenderit in voluptate"
" velit esse cillum dolore eu fugiat nulla pariatur."
" Excepteur sint occaecat cupidatat non proident, sunt"
" in culpa qui officia deserunt mollit anim id est laborum.";

static void test()
{
    std::istringstream iss(text);

    char val;
    for (int i = 0; i < 10; i++){
        iss >> val;
        std::cout << val;
    }

    #if 0
    char *word;
    for (int i = 0; i < 4; i++){
        iss.getline(word, 20);
        std::cout << word << std::endl;
    }
    #endif
}

#define MAX_WORD_LEN 100
static void count()
{
    int pos = 0;
    int wpos = 0;
    char wordbuf[MAX_WORD_LEN];

    while(1)
    {
        char c = text[pos];
        pos++;

        if (c == '\0')
            break;    

        if (c == ' '){
            if (wpos != 0){
                wordbuf[wpos] = '\0';
                if (umap[wordbuf]){
                    umap[wordbuf] += 1;
                } else {
                    umap[wordbuf] = 1;
                }
                std::cout << wordbuf << " " << umap[wordbuf] << std::endl;
            }
            wpos = 0;
        } else {
            wordbuf[wpos] = c; 
            wpos++;
        }

        // putchar(c);
    }

}

int main()
{
    // std::unordered_map<std::string, int> umap = {};
    // test();
    count();
}