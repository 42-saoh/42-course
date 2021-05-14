FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add nginx php7 php7-fpm php7-mbstring php7-session \
				php7-common php7-iconv php7-json php7-gd php7-curl php7-xml \
				php7-mysqli php7-imap php7-cgi fcgi php7-ctype php7-dom mysql-client

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz && mv wordpress/ /var/www/ && rm -f latest.tar.gz /etc/nginx/conf.d/default.conf
RUN mkdir -p /run/nginx

COPY wp-config.php /var/www/wordpress/
COPY default.conf /etc/nginx/conf.d/
COPY wordpress.sh /etc/nginx/
COPY wordpress.sql /run/nginx/wordpress.sql

RUN chmod +x /etc/nginx/wordpress.sh

EXPOSE 5050

ENTRYPOINT /bin/sh "/etc/nginx/wordpress.sh" &&  php-fpm7 && nginx -g "daemon off;"
