#include "Parsing.hpp"

void initLocData(DataLoc &data)
{
    data.path.clear();
    data.get = false;
    data.post = false;
    data.del = false;
    data.cgi = false;
    data.autoindex = false;

    data.index.first = false;
    data.index.second.clear();

    data.dirpost.first = false;
    data.dirpost.second.clear();

    data.ret.first = false;
    data.ret.second.clear();

    data.alias.first = false;
    data.alias.second.clear();
}

Location parseLocation(std::string prevLoc)
{
    DataLoc loc;
    size_t  index = 0, indexEnd = 0, indexStart = 0;
    int i;
    const char *locData[] = {"allow_cgi", "allow_autoindex", "index","dir_post" ,"return", "alias", "method", NULL};

    initLocData(loc);
    if (index > prevLoc.size())
        throw std::invalid_argument(prevLoc);
    indexEnd = prevLoc.find_first_of("{", index);
    if (indexEnd > prevLoc.size())
        throw std::invalid_argument(prevLoc);
    indexEnd = prevLoc.find_last_not_of(" \t", indexEnd);
    if (indexEnd > prevLoc.size())
        throw std::invalid_argument(prevLoc);
    loc.path = prevLoc.substr(index, indexEnd - (index?index:1));
    index = prevLoc.find_first_of("{", indexEnd);
    if (index > prevLoc.size())
        throw std::invalid_argument(prevLoc);
    index++;
    while (index < prevLoc.size())
    {
        index = prevLoc.find_first_not_of(" \t", index);
        indexEnd = prevLoc.find_first_of(" \t", index);
        for (i = 0; locData[i]; i++)
        {
            if (prevLoc.compare(index, strlen(locData[i]), locData[i]) == 0)
            {
                index += strlen(locData[i]);
                indexStart = prevLoc.find_first_not_of(" \t", index);
                break ;
            }
        }
        if (index >= prevLoc.size())
            throw std::invalid_argument("invalid file");
        if(i != method)
        {
            indexEnd = prevLoc.find_first_of(";", index);
            if (indexEnd > prevLoc.size() || indexStart > prevLoc.size())
                break ;
        }
        else
        {
            indexEnd = prevLoc.find_first_of("}", index);
            if (indexEnd > prevLoc.size() || indexStart > prevLoc.size())
                break ;
        }
        switch(i)
        {
            case cgi:
            {
                if (loc.cgi)
                    throw std::invalid_argument("multiple definition : cgi");
                loc.cgi = true;
                break;
            }
            case _autoindex:
            {
                if (loc.autoindex)
                    throw std::invalid_argument("multiple definition : autoindex");
                loc.autoindex = true;
                break;
            }
            case _index:
            {
                if (!loc.index.second.empty())
                    throw std::invalid_argument("multiple definition : index");
                loc.index.second = prevLoc.substr(indexStart, indexEnd - indexStart);
                if (!loc.index.second.empty())
                    loc.index.first = true ;
                break;
            }
            case dir_post:
            {
                if (!loc.dirpost.second.empty())
                    throw std::invalid_argument("multiple definition : dirpost");
                loc.dirpost.second = prevLoc.substr(indexStart, indexEnd - indexStart);
                if (!loc.dirpost.second.empty())
                    loc.dirpost.first = true ;
                break;
            }
            case ret:
            {
                if (!loc.ret.second.empty())
                    throw std::invalid_argument("multiple definition : return");
                loc.ret.second = prevLoc.substr(indexStart, indexEnd - indexStart);
                if (!loc.ret.second.empty())
                    loc.ret.first = true ;
                break;
            }
            case alias:
            {
                if (!loc.alias.second.empty())
                    throw std::invalid_argument("multiple definition : alias");
                loc.alias.second = prevLoc.substr(indexStart, indexEnd - indexStart);
                if (!loc.alias.second.empty())
                    loc.alias.first = true ;
                break;
            }
            case method:
            {
                const char *methods[] = {"DELETE", "POST", "GET", NULL};
                while (index < prevLoc.size() && prevLoc[index] != '}')
                {
                    for (int m = 0; methods[m] && index < prevLoc.size(); m++)
                    {
                        if (prevLoc.compare(index, strlen(methods[m]), methods[m]) == 0)
                        {
                            switch(m)
                            {
                                case 0:
                                {
                                    if (loc.del == true)
                                        throw std::invalid_argument("multiple definition : DELETE");
                                    loc.del = true;
                                    break;
                                }
                                case 1:
                                {
                                    if (loc.post == true)
                                        throw std::invalid_argument("multiple definition : POST");
                                    loc.post = true;
                                    break;
                                }
                                case 2:
                                {
                                    if (loc.get == true)
                                        throw std::invalid_argument("multiple definition : GET");
                                    loc.get = true;
                                    break;
                                }
                                default:
                                    break;
                            }
                        }
                    }
                    index++;
                }
            }
            default:
                break;
        }
        index = indexEnd;
        if (index > prevLoc.size())
            break ;
        index += 1;
    }
    Location res(loc.path, loc.get, loc.post, loc.del, loc.cgi, loc.autoindex, loc.index, loc.dirpost, loc.ret, loc.alias);
    return (res);
}

std::string getLocation(size_t &index, const std::string &content, size_t &indexEnd)
{
    int level = 1;
    while(level && content[indexEnd])
    {
        if (content[indexEnd] == '{')
            level++;
        if (content[indexEnd] == '}')
            level--;
        indexEnd++;
    }
    if (index >= content.size())
        throw std::invalid_argument("location{...}");
    return (content.substr(index, indexEnd - index));
}

bool allNum(const std::string &str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        ++it;
    }
    return !str.empty() && it == str.end();
}

std::map<std::string, std::string> parseError(const std::string &error)
{
    std::map<std::string, std::string> ret;
    std::string path,  cle, value;
    size_t indexStart = 0, indexEnd = 0;
    indexStart = error.find_first_not_of(" \t", 0);
    indexEnd = error.find_first_of(" \t", indexStart);
    path = error.substr(indexStart, indexEnd - indexStart);
    while (indexEnd < error.size() && error[indexEnd] != '{')
        indexEnd++;
    if (indexEnd >= error.size())
        throw std::invalid_argument(std::string("invalid config file : ") + error);
    indexStart = indexEnd + 1;
    while (indexEnd < error.size() && indexStart < error.size())
    {
        indexStart = error.find_first_not_of(" \t", indexStart);
        if (indexEnd >= error.size())
            throw std::invalid_argument(std::string("invalid config file : ") + error);
        indexEnd = error.find_first_of(" \t", indexStart);
        if (indexEnd >= error.size())
            throw std::invalid_argument(std::string("invalid config file : ") + error);
        cle = error.substr(indexStart, indexEnd - indexStart);
        indexStart = error.find_first_not_of(" \t", indexEnd);
        if (indexEnd >= error.size())
            throw std::invalid_argument(std::string("invalid config file : ") + error);
        indexEnd = error.find_first_of("; \t", indexStart);
        if (indexEnd >= error.size())
            throw std::invalid_argument(std::string("invalid config file : ") + error);
        value = error.substr(indexStart, (indexEnd) - indexStart);
        indexEnd++;
        if (allNum(cle) && ret.find(cle) == ret.end())
            ret[cle] = path + "/" + value;
        else
            throw std::invalid_argument("invalid file" + cle);
        indexEnd = error.find_first_not_of(" \t", indexEnd);
        if (indexEnd < error.size() && error[indexEnd] == '}')
            break ;
        indexStart = indexEnd;
    }
    return (ret);
}

int addToServer(Data &servData, size_t &index, const std::string &content)
{
    const char  *serverInfo[] = {"server_name", "listen", "root", "body_size", "location", "error", NULL};
    size_t      indexEnd = 0, indexStart;
    size_t      i;
    while (index <= content.size() && content[index] != '}')
    {
        index = content.find_first_not_of(" \t", index);
        indexEnd = content.find_first_of(" \t", index);
        if (indexEnd > content.size() || index > content.size())
            break ;
        for (i = 0; serverInfo[i]; i++)
        {
            if (index > content.size())
                return (0) ;
            if (content.compare(index, strlen(serverInfo[i]), serverInfo[i]) == 0)
            {
                indexStart = content.find_first_not_of(" \t", indexEnd);
                break ;
            }
        }
        if(i != error && i != location)
        {
            indexEnd = content.find_first_of(";", index);
            if (indexEnd > content.size() || indexStart > content.size())
                break ;
        }
        switch(i)
        {
            case server_name:
            {
                if (!servData.name.empty())
                    throw std::invalid_argument("multiple definition : serve_name");
                servData.name = content.substr(indexStart, indexEnd - indexStart);
                break;
            }
            case _listen:
            {
                servData.listen += " " + content.substr(indexStart, indexEnd - indexStart);
                break;
            }
            case root:
            {
                if (!servData.root.empty())
                    throw std::invalid_argument("multiple definition : root");
                servData.root = content.substr(indexStart, indexEnd - indexStart);
                break;
            }
            case body_size:
            {
                if (!servData.body.empty())
                    throw std::invalid_argument("multiple definition : body_size");
                servData.body = content.substr(indexStart, indexEnd - indexStart);
				servData.bodymax = strtod(servData.body.c_str(), NULL);
                if (!allNum(servData.body) || servData.bodymax < 0 || static_cast<int>(servData.bodymax) < servData.bodymax || servData.bodymax == MAX(double)infinity() ||\
                   servData.bodymax > MAX(int)max() || servData.bodymax < 0)
                        throw std::invalid_argument("invalid body_size");
                break;
            }
            case location:
            {
                index = content.find_first_not_of(" \t", indexEnd);
                if (index > content.size())
                   return (0);
                for (; content[indexEnd] && content[indexEnd] != '{'; indexEnd++)
                    ;
                indexEnd++;
 				std::string s = getLocation(index, content, indexEnd);
                servData.locations.push_back(parseLocation(s));
                break;
            }
            case error:
            {
                if (!servData.error.empty())
                    throw std::invalid_argument("multiple definition : error");
                index = content.find_first_not_of(" \t", indexEnd);
                if (index > content.size())
                   return (0);
                for (; content[indexEnd] && content[indexEnd] != '{'; indexEnd++)
                    ;
                indexEnd++;
                servData.error = getLocation(index, content, indexEnd);
                servData.errors = parseError(servData.error);
                break;
            }
            default:
            {
                std::string errorMessage = "Invalid config file: ";
                errorMessage += std::string(content.c_str() + index, indexEnd - index);
                throw std::invalid_argument(errorMessage);
            }
        }
        if (indexEnd != std::string::npos && content[indexEnd] != '}')
            index = indexEnd + 1;
        else
            index = indexEnd;
    }
    index = content.find_first_not_of(" \t", index);
    if (index > content.size())
        throw std::invalid_argument("invalid config file");
    return (1);
}

bool getData(std::string &content, Data &servData, size_t &index)
{
    int status = 0;

    index = content.find_first_not_of("\n\t", index);
    if (index > content.size())
        throw std::invalid_argument("invalid file");
    if (content.compare(index, 6,"server") == 0)
    {
        index += 6;
        index = content.find_first_not_of(" \n\t", index);
        if (index > content.size())
            return (false);
        index++;
        if (content[index - 1] == '{')
            status = SERVER;
    }
    if (status != SERVER && index < content.size())
        throw std::invalid_argument("ici invalid file");
    while (index < content.size() && status == SERVER)
    {
        if (status == SERVER && !addToServer(servData, index, content))
            return (false);
        if (content[index] == '}')
            status--;
        if (status == OUTSIDE)
            return (true);
    }
    return (true);
}

void    clearData(Data &data)
{
    data.name.clear();
    data.root.clear();
    data.ports.clear();
    data.listen.clear();
    data.body.clear();
    data.locations.clear();
    data.error.clear();
    data.errors.clear();
    data.loc.clear();
    data.bodymax = -1;
    data.good = true;
}

std::vector<Data> parsing(const char *filename)
{
    std::vector<Data>   serveurs;
    Data                servData;
    std::string         content, line;
    size_t              index = 0;

    std::ifstream       file(filename);
    clearData(servData);
    while (std::getline(file, line))
        content += line;
    if (content.empty())
        throw   std::invalid_argument("invalid file");
    while (index < content.size())
    {
        clearData(servData);
        getData(content, servData, index);
        if (servData.name.empty() || servData.listen.empty() || servData.root.empty() || servData.bodymax < 0)
            throw std::invalid_argument("incomplete server");
        if (servData.good)
        {
            double nb;
            char *endptr;
            for (const char *str = servData.listen.c_str(); *str; str++)
            {
                if (servData.listen.find_first_not_of(" \t", 0) == std::string::npos)
                    throw std::invalid_argument("no port provided");
                nb = strtod(str, &endptr);
                if ((!std::isspace(*str) && !std::isdigit(*str)) || nb == MAX(double)infinity() ||\
                    nb > MAX(int)max() || nb < 0 || nb != std::floor(nb))
                {
                    std::string errorMessage = "Invalid config file: ";
                    errorMessage += servData.listen;
                    throw std::invalid_argument(errorMessage);
                }
                else
                {
                    if (std::find(servData.ports.begin(), servData.ports.end(), nb) ==  servData.ports.end())
                        servData.ports.push_back(nb);
                }
                str = endptr;
                if (!*endptr)
                    break ;
            }
                serveurs.push_back(servData);
        }
        clearData(servData);
        index = content.find_first_not_of(" \t", index);
        index++;
    }
    return (serveurs);
}
