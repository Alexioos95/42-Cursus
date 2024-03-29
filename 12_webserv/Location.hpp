/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:55:05 by apayen            #+#    #+#             */
/*   Updated: 2024/02/19 14:25:56 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
#define LOCATION_HPP

# include <utility>		// pair
# include <iostream>	// cout

class Location
{
	public:
	// Constructors and Destructor
		Location(void);
		Location(std::string path, bool get, bool post, bool del, bool cgi, bool autoindex, \
			std::pair<bool, std::string> index, std::pair<bool, std::string> dirpost, \
			std::pair<bool, std::string> ret, std::pair<bool, std::string> alias);
		Location(Location const &rhs);
		~Location(void);
	// Overloads
		Location						&operator=(Location const &rhs);
	// Getters
		bool							allowMethod(std::string method, bool &get, bool &post, bool &del) const;
		bool							allowCgi(void) const;
		bool							allowAutoindex(void) const;
		std::string						getPath(void) const;
		std::pair<bool, std::string>	getIndex(void) const;
		std::pair<bool, std::string>	getDirPost(void) const;
		std::pair<bool, std::string>	getReturn(void) const;
		std::pair<bool, std::string>	getAlias(void) const;

	private:
	// Attributes
		std::string						_path;
		bool							_get;
		bool							_post;
		bool							_del;
		bool							_cgi;
		bool							_autoindex;
		std::pair<bool, std::string>	_index;
		std::pair<bool, std::string>	_dirpost;
		std::pair<bool, std::string>	_ret;
		std::pair<bool, std::string>	_alias;
};

#endif
