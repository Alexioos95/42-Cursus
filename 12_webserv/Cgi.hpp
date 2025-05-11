#ifndef CGI_HPP
#define CGI_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "Manager.hpp"

enum langage {ERROR, PHP, RUBY, PYTHON};
enum file {READ, WRITE};

class Cgi{
	public :
		Cgi(Manager &man, const std::vector<std::string> &);
		~Cgi();
		void	launchCgi(const std::string &);
		int	getFdWrite();
		int	getFdRead();
		int	getPid();

	private :
		int	_pid;
		int	_pipeIn[2];
		int	_pipeOut[2];
		char	**_env;
		Manager	&_man;
};

#endif
