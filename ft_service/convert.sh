sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/ftps/ftps.yml
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/ftps/vsftpd.conf
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/grafana/grafana.yml
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/wordpress/wordpress.yml
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/nginx/nginx.yml
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/nginx/default.conf
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/phpmyadmin/config.inc.php
sed -i '' "s/LB_IP/$LB_IP/g" ./srcs/phpmyadmin/phpmyadmin.php
