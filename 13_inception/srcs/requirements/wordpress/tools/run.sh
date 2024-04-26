#!/bin/bash
cd /var/www/html
rm -rf *
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x ./wp-cli.phar
mv ./wp-cli.phar /usr/local/bin/wp

if [ -f ./wp-config.php ]
then
	echo "Wordpress is already installed"
else
	wp core download --allow-root
	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/mariadb:3306/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php
	# wp core install --url='apayen.42.fr' --title='Blog Title' --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_MAIL --skip-email --allow-root
	# wp user create $USER_USER $USER_MAIL --user_pass=$USER_PASSWORD --allow-root
	mkdir /run/php
fi

exec "$@"
