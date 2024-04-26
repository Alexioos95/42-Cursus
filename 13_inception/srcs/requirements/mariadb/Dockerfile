FROM debian:bullseye

RUN	apt update -y \
	&& apt upgrade -y \
	&& apt install curl -y \
	&& apt-get install apt-transport-https curl -y \
	&& mkdir -p /etc/apt/keyrings \
	&& curl -o /etc/apt/keyrings/mariadb-keyring.pgp 'https://mariadb.org/mariadb_release_signing_key.pgp' \
	&& apt-get install mariadb-server -y \
	&& apt-get install mariadb-client -y \
	&& mkdir -p /run/mysqld

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/run.sh /home/run.sh

RUN chmod +x /home/run.sh

CMD ["/home/run.sh"]
CMD ["mysql_install_db"]
CMD ["mysqld"]
