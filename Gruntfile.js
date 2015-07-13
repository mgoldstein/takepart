module.exports = function (grunt) {

    // load all grunt tasks matching the ['grunt-*', '@*/grunt-*'] patterns
    require('load-grunt-tasks')(grunt);

    grunt.initConfig({
        watch: {
            src: {
                files: [
                    'drupal/sites/all/themes/fresh/sass/**/*.scss',
                    'drupal/sites/all/themes/tp4/sass/**/*.scss'
                ],
                tasks: ['compass:fresh_dev', 'compass:tp4_dev', 'play:toolman']
            }
        },
        compass: {
            fresh: {
                options: {
                    sassDir: './drupal/sites/all/themes/fresh/sass',
                    cssDir: './drupal/sites/all/themes/fresh/css',
                    imagesDir: './drupal/sites/all/themes/fresh/images',
                    raw: "add_import_path 'drupal/sites/all/themes/base/sass' \n" +
                    "generated_images_dir = './drupal/sites/all/themes/fresh/images' \n" +
                    "http_images_path = '/sites/all/themes/fresh/images' \n" +
                    "http_generated_images_path = '/sites/all/themes/fresh/images'",
                    environment: 'development'
                }
            },
            tp4: {
                options: {
                    sassDir: './drupal/sites/all/themes/tp4/sass',
                    cssDir: './drupal/sites/all/themes/tp4/css',
                    imagesDir: './drupal/sites/all/themes/tp4/images',
                    raw: "add_import_path 'drupal/sites/all/themes/base/sass' \n" +
                    "require 'zen-grids' \n" +
                    "generated_images_dir = './drupal/sites/all/themes/tp4/images' \n" +
                    "http_images_path = '/sites/all/themes/tp4/images' \n" +
                    "http_generated_images_path = '/sites/all/themes/tp4/images'",
                    environment: 'development'
                }
            }
        },
        shell: {
            clear_cache: {
                command: [
                    'cd drupal',
                    'drush cc css-js'
                ].join('&&')
            }
        },
        play: {
            toolman: {
                file: './grunt.mp3'
            }
        }
    });

    grunt.registerTask('build_dev', [
        'compass:fresh',
        'compass:tp4',
        'shell:clear_cache'
    ]);
    grunt.registerTask('build_prod', [
        'compass:fresh',
        'compass:tp4'
    ]);
};

