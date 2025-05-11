FROM debian:bullseye

RUN	apt update -y \
        && apt upgrade -y \
        && apt install nginx -y \
        && mkdir -p /etc/nginx/ssl \
	&& apt install openssl -y \
	&& openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
		-out /etc/nginx/ssl/inception.crt \
		-keyout /etc/nginx/ssl/inception.key \
		-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=apayen/CN=apayen/" \
	&& mkdir -p /var/run/nginx \
	&& chmod 755 /var/www/html \
	&& chown -R www-data:www-data /var/www/html

COPY conf/default /etc/nginx/sites-available/default

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
