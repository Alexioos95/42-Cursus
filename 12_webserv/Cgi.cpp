#include "Cgi.hpp"

Cgi::Cgi(Manager &man, const std::vector<std::string> &env) : _man(man)
{
	int i = 0;
	_pid = -1;
	_env = new char*[(env.size() + 1) * sizeof(char *)];
	for (std::vector<std::string>::const_iterator ite = env.begin(); ite != env.end(); i++, ite++)
		_env[i] = (char *)ite->c_str();
	_env[i] = NULL;
	_pipeIn[0] = -2;
	_pipeIn[1] = -2;
	_pipeOut[0] = -2;
	_pipeOut[1] = -2;
	if (pipe(_pipeIn) == -1)
		throw std::runtime_error("cgi : pipe error");
	if (pipe(_pipeOut) == -1)
		throw std::runtime_error("cgi : pipe error");
}

Cgi::~Cgi()
{
	if (_pid > 0)
	{
		kill(_pid, SIGKILL);
		_pid = -1;
	}
	if (_pipeIn[0] > 0)
		close(_pipeIn[0]);
	if (_pipeIn[1] > 0)
		close(_pipeIn[1]);
	if (_pipeOut[0] > 0)
		close(_pipeOut[0]);
	if (_pipeOut[1] > 0)
		close(_pipeOut[1]);
	if (_env)
	{
		delete[] _env;
		_env = NULL;
	}
}

bool checkEnd(const char *a, const char *b)
{
	size_t aEnd = strlen(a);
	size_t bEnd = strlen(b);

	while (aEnd > 0 && bEnd > 0 && a[aEnd - 1] == b[bEnd - 1])
	{
		bEnd--;
		aEnd--;
	}
	return (bEnd == 0);
}

void Cgi::launchCgi(const std::string &f)
{
	int cgiType;

	if (access(f.c_str(), F_OK) == -1)
		throw (std::string("404 Not Found"));
	cgiType = checkEnd(f.c_str(), ".php") ? PHP : checkEnd(f.c_str(), ".ruby") ? RUBY : checkEnd(f.c_str(), ".py") ? PYTHON : ERROR;
	if (cgiType == ERROR)
		throw std::invalid_argument("only php and ruby are handdled");
	if (_pipeIn[1] > 0)
	{
		close(_pipeIn[1]);
		_pipeIn[1] = -2;
	}
	_pid = fork();
	if (_pid == 0)
	{
		if (_pipeOut[0] > -1)
			close(_pipeOut[0]);
		if (_pipeIn[1] > -1)
			close(_pipeIn[1]);
		dup2(_pipeIn[0], STDIN_FILENO);
		dup2(_pipeOut[1], STDOUT_FILENO);
		if (_pipeIn[0] > -1)
			close(_pipeIn[0]);
		if (_pipeOut[1] > -1)
			close(_pipeOut[1]);
		_man.shutdown(false);
		if (cgiType == PHP)
		{
			const char *args[] = {"php" ,f.c_str(), NULL};
			execve("/usr/bin/php", const_cast<char* const*>(args), _env);
		}
		else if (cgiType == RUBY)
		{
			const char *args[] = {"ruby" ,f.c_str(), NULL};
			execve("/usr/bin/ruby", const_cast<char* const*>(args), _env);
		}
		else if (cgiType == PYTHON)
		{
			const char *args[] = {"python" ,f.c_str(), NULL};
			execve("/usr/bin/python", const_cast<char* const*>(args), _env);
		}
		exit(5);
	}
	if (_pid == -1)
		throw std::runtime_error("cgi : fail to fork");
	if (_pipeIn[0] > -1)
	{
		close(_pipeIn[0]);
		_pipeIn[0] = -1;
	}
	if (_pipeOut[1] > -1)
	{
		close(_pipeOut[1]);
		_pipeOut[1] = -1;
	}
}

int Cgi::getFdWrite()
{
	return (_pipeIn[1]);
}

int Cgi::getFdRead()
{
	return (_pipeOut[0]);
}

int Cgi::getPid()
{
	return (_pid);
}
