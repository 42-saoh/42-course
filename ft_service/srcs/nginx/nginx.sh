#!/bin/sh

rm /etc/nginx/conf.d/default.conf
mv /etc/nginx/default.conf /etc/nginx/conf.d/

mkdir -p /etc/nginx/ssl
openssl req -new -x509 -nodes -newkey rsa:2048 -keyout /etc/nginx/ssl/localhost.key -out /etc/nginx/ssl/localhost.crt -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/CN=localhost"

ssh-keygen -A
adduser --disabled-password ${SSH_USERNAME}
echo "${SSH_USERNAME}:${SSH_PASSWORD}" | chpasswd

mkdir -p /run/nginx/
echo "<h1>FT_SERVICES NGINX INDEX.HTML</h1>" >> /var/www/index.html

/usr/sbin/sshd
/usr/sbin/nginx -g "daemon off;"
