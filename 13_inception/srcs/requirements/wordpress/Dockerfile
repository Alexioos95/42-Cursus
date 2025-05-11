FROM debian:bullseye

RUN	apt update -y \
        && apt upgrade -y \
	&& apt-get install curl -y \
	&& apt-get install -y php php-cgi php-fpm php-mysql mariadb-client \
	&& mkdir -p /var/www/html

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY conf/www.conf /etc/php7/php-fpm.d/www.conf
COPY tools/run.sh /home/run.sh

RUN chmod +x /home/run.sh

ENTRYPOINT ["/home/run.sh"]

WORKDIR /var/www/html/

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.4", "-F"]
