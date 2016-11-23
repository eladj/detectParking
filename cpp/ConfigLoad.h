#include <string>
#include <map>
using namespace std;
class ConfigLoad {
public:
    static void parse();
    static string trim(const string& str);
    static map<string, string> options;
    
};
