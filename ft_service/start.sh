#!/bin/bash

kubectl apply -f srcs/nginx/nginx-secret.yml

kubectl apply -f srcs/nginx/nginx.yml

kubectl apply -f srcs/ftps/ftps.yml

kubectl apply -f srcs/mysql/mysql.yml

kubectl apply -f srcs/wordpress/wordpress.yml

kubectl apply -f srcs/phpmyadmin/phpmyadmin.yml

kubectl apply -f srcs/influxdb/influxdb.yml

kubectl apply -f srcs/telegraf/telegraf.yml

kubectl apply -f srcs/grafana/grafana.yml
