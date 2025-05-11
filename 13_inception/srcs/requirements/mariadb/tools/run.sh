#!/bin/sh
service mariadb start
if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then
	echo "Database '$MYSQL_DATABASE' exist"
else
	mysql_secure_installation << end
Y
$SQL_ROOT_PASSWORD
$SQL_ROOT_PASSWORD
Y
n
Y
Y
end
echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot
echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES;" | mysql -u root
fi
mysqladmin -u root -p$MYSQL_ROOT_PASSWORD shutdown
exec mysqld_safe
