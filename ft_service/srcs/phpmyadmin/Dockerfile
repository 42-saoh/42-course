FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add nginx php7 php7-fpm php7-mbstring php7-session \
				php7-common php7-iconv php7-json php7-gd php7-curl php7-xml \
				php7-mysqli php7-imap php7-cgi fcgi php7-ctype php7-dom mysql-client

RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz && tar -xvf /phpMyAdmin-4.9.5-all-languages.tar.gz && rm -f /phpMyAdmin-4.9.5-all-languages.tar.gz /etc/nginx/conf.d/default.conf
RUN mv /phpMyAdmin-4.9.5-all-languages /var/www/phpmyadmin
RUN mkdir -p /run/nginx

COPY config.inc.php /var/www/phpmyadmin/
COPY default.conf /etc/nginx/conf.d/

RUN chmod 705 /var/www/phpmyadmin/config.inc.php

EXPOSE 5000

ENTRYPOINT php-fpm7 && nginx -g "daemon off;"
