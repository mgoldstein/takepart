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
    uglify: {
      options: {
        banner: '<%= banner %>',
        sourceMap: true
      },
      dist: {
        files: {
          'js/<%= pkg.name %>.form.js': [
            'bower_components/jquery.validation/jquery.validate.js',
            'bower_components/jquery.customSelect/jquery.customSelect.js',
            'js/src/form.js'
          ],
          'js/<%= pkg.name %>.landing.js': [
            'bower_components/jquery.customSelect/jquery.customSelect.js',
            'js/src/jquery.school-browser.js',
            'js/src/landing.js'
          ],
          'js/<%= pkg.name %>.app.js': [
            'bower_components/jquery.customSelect/jquery.customSelect.js',
            'js/src/jquery.school-browser.js',

            // lotta masonry deps
            'bower_components/eventEmitter/EventEmitter.js',
            'bower_components/eventie/eventie.js',
            'bower_components/doc-ready/doc-ready.js',
            'bower_components/get-style-property/get-style-property.js',
            'bower_components/get-size/get-size.js',
            'bower_components/jquery-bridget/jquery.bridget.js',
            'bower_components/matches-selector/matches-selector.js',
            'bower_components/outlayer/item.js',
            'bower_components/outlayer/outlayer.js',
            'bower_components/masonry/masonry.js',

            'bower_components/underscore/underscore.js',
            'bower_components/backbone/backbone.js',
            'bower_components/backbone-pageable/lib/backbone-pageable.js',
            'js/src/app.js'
          ]
        }
      }
    },
    replace: {
      js: {
        src: ['js/*.js'],
        overwrite: true,
        replacements: [{
          from: 'sourceMappingURL=',
          to: 'sourceMappingURL=/profiles/takepart/themes/takepart3/campaigns/teach/js/'
        }]
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

  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-newer');
  grunt.loadNpmTasks('grunt-notify');
  grunt.loadNpmTasks('grunt-text-replace');

  // Default task.
  grunt.registerTask('sassCompile', ['newer:compass', 'notify:compass']);
  grunt.registerTask('jsCompile', ['newer:jshint', 'uglify', 'replace:js', 'notify:uglify']);
  grunt.registerTask('default', ['sassCompile', 'jsCompile']);

};
