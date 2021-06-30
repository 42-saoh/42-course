#!/bin/bash

export MINIKUBE_HOME=~/goinfre

minikube delete
minikube start --driver=virtualbox
minikube addons enable metallb

eval $(minikube docker-env)
docker build -t nginx ./srcs/nginx/
docker build -t ftps srcs/ftps
docker build -t mysql srcs/mysql
docker build -t wordpress srcs/wordpress
docker build -t phpmyadmin srcs/phpmyadmin
docker build -t influxdb srcs/influxdb
docker build -t telegraf srcs/telegraf
docker build -t grafana srcs/grafana

kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml
kubectl apply -f srcs/metallb-cm.yml
kubectl apply -f srcs/nginx/nginx-secret.yml
kubectl apply -f srcs/nginx/nginx.yml
kubectl apply -f srcs/ftps/ftps.yml
kubectl apply -f srcs/mysql/mysql.yml
kubectl apply -f srcs/influxdb/influxdb.yml
kubectl apply -f srcs/telegraf/telegraf.yml
kubectl apply -f srcs/grafana/grafana.yml
kubectl apply -f srcs/wordpress/wordpress.yml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yml

kubectl create -f srcs/service-account.yml
kubectl create -f srcs/cluster-role-binding.yml
