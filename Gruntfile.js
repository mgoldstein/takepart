module.exports = function (grunt) {
    grunt.initConfig({
        watch: {
            src: {
                files: ['**/*.scss', '**/*.php'],
                tasks: ['compass:fresh', 'compass:tp4', 'play:toolman']
            }
        },
        compass: {
            fresh: {
                options: {
                    sassDir: './drupal/sites/all/themes/fresh/sass',
                    cssDir: './drupal/sites/all/themes/fresh/css',
                    imagesDir: './drupal/sites/all/themes/fresh/images',
<<<<<<< HEAD
                    raw: "add_import_path 'drupal/sites/all/themes/base/sass' \n" +
                    "generated_images_dir = './drupal/sites/all/themes/fresh/images' \n" +
                    "http_images_path = '/sites/all/themes/fresh/images' \n" +
                    "http_generated_images_path = '/sites/all/themes/fresh/images'",
=======
                    raw: "add_import_path 'drupal/sites/all/themes/base/sass'",
>>>>>>> bebebf8... TP-3377: Grunt for compiling tp4 and fresh assets
                    environment: 'development',
                    force: true
                }
            },
            tp4: {
                options: {
                    sassDir: './drupal/sites/all/themes/tp4/sass',
                    cssDir: './drupal/sites/all/themes/tp4/css',
                    imagesDir: './drupal/sites/all/themes/tp4/images',
                    raw: "add_import_path 'drupal/sites/all/themes/base/sass' \n" +
                    "extensions_dir  = './drupal/sites/all/themes/tp4/sass-extensions' \n" +
<<<<<<< HEAD
                    "require 'zen-grids' \n" +
                    "generated_images_dir = './drupal/sites/all/themes/tp4/images' \n" +
                    "http_images_path = '/sites/all/themes/tp4/images' \n" +
                    "http_generated_images_path = '/sites/all/themes/tp4/images'",
=======
                    "require 'zen-grids'",
>>>>>>> bebebf8... TP-3377: Grunt for compiling tp4 and fresh assets
                    environment: 'development',
                    force: true
                }
            }
        },
        play: {
            toolman: {
                file: './grunt.mp3'
            }
        }
    });
    grunt.loadNpmTasks('grunt-contrib-compass');
    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-play');

    grunt.registerTask('dev', ['compass:fresh', 'compass:tp4']);
    grunt.registerTask('prod', ['compass:tp4']);
};

