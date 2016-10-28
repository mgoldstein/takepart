# TakePart

> Stories That Matter, Actions That Count

## Getting Started

### Pre-requisites

Make sure you have the following installed

0. Download and Install [Docker for Mac](https://download.docker.com/mac/stable/Docker.dmg)

1. Clone this repo

        $ git clone https://github.com/takepart/takepart-com.git && cd takepart-com

2. Install [Node.js](https://nodejs.org/en/)

3. Install [Ruby](https://www.ruby-lang.org/en/)

        $ gem install -N bundler
        $ bundle install -j4

4. Install [npm](https://www.npmjs.com/)

        $ sudo npm install -g grunt-cli
        $ npm install

5. Install fswatch

        $ brew install fswatch


6. Edit your hosts

        127.0.0.1 takepart.dev www.takepart.dev

7. AWS ECR Authentication

        $ cd ~
        $ wget http://prod-jenkins.service.consul/docker.tgz
        $ tar -xzf docker.tgz

8. Start TakePart - create and run the containers

        $ docker-sync-stack start

9. MySQL

        $ docker exec -i takepartcom_db_1 mysql -uroot -proot takepart < ~/dumps/TP-prod-2016-10-10-00-15-00.sql

10. Drush

        $ docker exec -it takepartcom_drupal_1 bash -c "cd /var/www/html && APP_ENV=local ./drush dis securepages -y && ./drush en stage_file_proxy -y && ./drush vset stage_file_proxy_origin 'http://www.takepart.com' && drush cc all"

11. Admin

        Navigate to www.takepart.dev/user to login
        Goto admin/config/development/performance
        Uncheck ALL checkboxes

12. Files directory private folder permissions

        $ cd drupal/sites/default/files
        $ mkdir private
        $ cd ..
        $ chmod -R 755 files

13. Compile assets

        $ grunt build_prod


## Testing
Documentation on how we handle testing


## Git workflow
Documentation on TakePart's forking/branching workflow
