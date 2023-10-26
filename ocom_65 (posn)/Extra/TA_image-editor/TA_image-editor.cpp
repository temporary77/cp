    #include <iostream>
    #include <sstream>
    #include <iomanip>
    #include <string>
    #include <fstream>
    #include <map>
    using namespace std;

int main(int argc, char * argv[]){
    string file = "config.txt";
    string line = "";
    string tag = "";
    string ansi = "";
    map <string, string> m;

    if(argc == 2){
        file = argv[1];
    }
    ifstream in(file, ios_base::in | ios_base::binary);
    if(!in){
        cerr<<"could not open file";
    }

    while (getline(in, line)){
        istringstream iss(line);
        if(iss>>tag>>ansi){
            auto it = m.find(tag);
            if(it == m.end()){
                m.insert(make_pair(tag,ansi));
            }

        }
    }

    for(auto x: m){
        cout<<x.second<<x.first<<endl;
    }
    cout<<"\033[0;35mhello";
    return 0;
}
