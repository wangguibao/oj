/*
 * Problem: 2503, Babelfish
 * User: LoiteringLeo
 * Memory: 14689K     Time: 2422MS
 * Language: G++    Result: Accepted
*/
#include <map>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_LEN 11

char input[MAX_LEN];

int main()
{
    map<string, string> dict;
    map<string, string>::iterator it;
    char *foreign;
    char *local;
    bool query = false;

    while (gets(input)) {
        if (query == false) {
            if (strlen(input) == 0) {
                query = true;
            }
            else {
                local = input;
                foreign = strchr(input, ' ');
                *foreign = '\0';
                foreign++;
                dict.insert(
                        pair<string, string>(string(foreign), string(local)));
            }
        }
        else {
            if (input[0] == '\0') {
                break;
            }
            it = dict.find(string(input));
            if (it != dict.end()) {
                printf("%s\n", it->second.c_str());
            }
            else {
                printf("eh\n");
            }
            foreign[0] = '\0';
        }
    }

    return 0;
}

