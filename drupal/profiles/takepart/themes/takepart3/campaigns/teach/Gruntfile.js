/*global module:false*/
module.exports = function(grunt) {

  // Project configuration.
  grunt.initConfig({
    // Metadata.
    pkg: grunt.file.readJSON('package.json'),
    banner: '/*! <%= pkg.title || pkg.name %> - v<%= pkg.version %> */ ',
    // Task configuration.
    watch: {
      js: {
        files: ['js/src/{,*/}*.js'],
        tasks: ['jsCompile']
      },
      compass: {
        files: ['css/{,*/}*.scss'],
        tasks: ['sassCompile']
      }
    },
    concat: {
      options: {
        banner: '<%= banner %>',
        stripBanners: true
      },
      dist: {
        files: {
          '.tmp/<%= pkg.name %>.form.js': [
            'bower_components/jquery.validation/jquery.validate.js',
            'bower_components/jquery.customSelect/jquery.customSelect.js',
            'js/src/form.js'
          ],
          '.tmp/<%= pkg.name %>.landing.js': [
            'bower_components/jquery.customSelect/jquery.customSelect.js',
            'js/src/jquery.school-browser.js',
            'js/src/landing.js'
          ],
          '.tmp/<%= pkg.name %>.app.js': [
            'bower_components/jquery.customSelect/jquery.customSelect.js',
            'js/src/jquery.school-browser.js',
            'js/src/app.js'
          ]
        }
      }
    },
    uglify: {
      options: {
        banner: '<%= banner %>'
      },
      dist: {
        files: {
          'js/<%= pkg.name %>.form.js': ['.tmp/<%= pkg.name %>.form.js'],
          'js/<%= pkg.name %>.landing.js': ['.tmp/<%= pkg.name %>.landing.js'],
          'js/<%= pkg.name %>.app.js': ['.tmp/<%= pkg.name %>.app.js']
        }
      }
    },
    jshint: {
      options: {
        curly: true,
        eqeqeq: true,
        immed: true,
        latedef: true,
        newcap: true,
        noarg: true,
        sub: true,
        undef: true,
        unused: true,
        boss: true,
        eqnull: true,
        browser: true,
        globals: {}
      },
      gruntfile: {
        src: 'Gruntfile.js'
      }
    },
    compass: {
      config: 'config.rb'
    },
    notify: {
      compass: {
        options: {
          message: "SASS Compiled"
        }
      },
      uglify: {
        options: {
          message: "JS Compiled"
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-newer');
  grunt.loadNpmTasks('grunt-notify');

  // Default task.
  grunt.registerTask('sassCompile', ['newer:compass', 'notify:compass']);
  grunt.registerTask('jsCompile', ['newer:jshint', 'concat', 'uglify', 'notify:uglify']);
  grunt.registerTask('default', ['sassCompile', 'jsCompile']);

};
