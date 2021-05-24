docker run -it -p 80:80 -p 443:443 debian:buster
apt-get update
apt-get upgrade
apt-get -y install nginx
service nginx start
service nginx status
apt-get -y install curl
curl localhost
apt-get -y install openssl vim
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key <!--위치 cd / 인지 확인-->
vim etc/nginx/sites-available/default <!--한 후 set nu-->
<!--40번째 줄에 추가하기-->
```
	listen 443;

	ssl on;
	ssl_certificate /etc/ssl/certs/localhost.dev.crt;
	ssl_certificate_key /etc/ssl/private/localhost.dev.key;
```
service nginx reload <!--한 후 https://localhost 들어가서 NET::ERR_CERT_INVALID 누르고 thisisunsafe 입력-->



apt-get -y install php-fpm
vim /etc/nginx/sites-available/default <!-- :set nu -->
주석 해제 <!--63, 66, 69, -->
index.php 추가 <!-- 50번 째 줄-->
service php7.3-fpm start
service php7.3-fpm status
vim /var/www/html/phpinfo.php
```
<?php phpinfo(); ?>
```
service nginx reload
https://localhost/phpinfo.php
rm -rf /var/www/html/phpinfo.php


apt-get -y install mariadb-server php-mysql

apt-get install -y wget
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php
vim var/www/html/phpmyadmin/config.inc.php
<!-- blowfish 암호(2번링크) 생성해서 18번째 줄에 붙여넣기-->

service nginx reload
service mysql start
service php7.3-fpm restart

mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password

mysqladmin -u root -p password <!-- 엔터, 패스워드, 패스워드 확인-->

mysql <!--하면 MariaDB로 들어가짐-->
show databases;
CREATE DATABASE IF NOT EXISTS wordpress;
show databases;
exit

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress

cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php
vim var/www/html/wordpress/wp-config.php <!-- 한 후 :set nu -->
<!--23, 26, 29, 32, 35, 38 번째 줄 확인-->
내용 수정

service nginx reload

vim etc/nginx/sites-available/default
<!--50번 째 줄에서 삭제 or  cd /var/www/html에 있는 파일 자체 삭제-->
```
index.nginx-debian.html # vi index.nginx-debian.html
```
<!--57번 째 줄에 추가-->
```
autoindex on;
```
service nginx restart
https://localhost <!--들어가면 index page 나옴 -->


vim /etc/nginx/sites-available/default
<!-- 25번째 줄에 추가, port 80과 443에 대해 분리해야 함-->
```
return 301 https://$host$request_uri;
```
service nginx restart
https://localhost <!--들어가면 index page 나옴 -->
