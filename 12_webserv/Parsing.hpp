#ifndef PARSING_HPP
#define PARSING_HPP

#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <iostream>
#include <string.h>
#include <limits>
#include <cmath>
#include "Location.hpp"

#define MAX(ARG) std::numeric_limits<ARG>::

enum state {OUTSIDE, SERVER, LOCATION};
enum param {server_name, _listen, root, body_size, location, error};
enum locparam {cgi, _autoindex, _index,dir_post , ret, alias, method};


typedef struct DataLoc
{
    std::string path;
    bool get;
    bool post;
    bool del;
    bool cgi;
    bool autoindex;
    std::pair<bool, std::string> index;
    std::pair<bool, std::string> dirpost;
    std::pair<bool, std::string> ret;
    std::pair<bool, std::string> alias;
}DataLoc;

typedef struct Data
{
    std::string name;
    std::string root;
    std::string listen;
    std::string body;
    std::vector<int> ports;
    std::vector<Location> locations;
    std::vector<std::string> loc;
    std::map<std::string, std::string> errors;
    std::string error;
    int     bodymax;
    bool    good;
}Data;

std::vector<Data> parsing(const char *filename);

#endif

