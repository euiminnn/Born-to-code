#!/bin/bash
# all will be run in bash

# Self-signed SSL
apt-get -y install openssl
apt-get -y install vim
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
chmod 600 localhost.dev.crt localhost.dev.key
mv localhost.dev.crt /etc/ssl/certs/
mv localhost.dev.key /etc/ssl/private/

# Nginx
cp -rp /root/default /etc/nginx/sites-available

# phpMyAdmin
apt-get install -y wget
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
cp -rp /root/config.inc.php /var/www/html/phpmyadmin/

# Database
service mysql start
mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'echung'@'localhost' IDENTIFIED BY 'mypwd' WITH GRANT OPTION" | mysql -u root --skip-password

# Wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp /root/wp-config.php /var/www/html/wordpress

service nginx start
service php7.3-fpm start
service mysql restart
