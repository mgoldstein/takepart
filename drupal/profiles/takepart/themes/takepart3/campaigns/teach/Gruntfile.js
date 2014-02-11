/*global module:false*/
module.exports = function(grunt) {

  // Project configuration.
  grunt.initConfig({
    // Metadata.
    pkg: grunt.file.readJSON('package.json'),
    banner: '/*! <%= pkg.title || pkg.name %> - v<%= pkg.version %> - ' +
      '<%= grunt.template.today("yyyy-mm-dd") %> */\n',
    // Task configuration.
    watch: {
      js: {
	files: ['js/src/{,*/}*.js'],
	tasks: ['jshint','concat', 'uglify']
      },
      compass: {
	files: ['css/{,*/}*.scss'],
	tasks: ['compass']
      }
    },
    concat: {
      options: {
	banner: '<%= banner %>',
	stripBanners: true
      },
      dist: {
	src: ['bower_components/jquery.validation/jquery.validate.js', 'js/src/*.js'],
	dest: '.tmp/<%= pkg.name %>.app.js'
      }
    },
    uglify: {
      options: {
	banner: '<%= banner %>'
      },
      dist: {
	src: '<%= concat.dist.dest %>',
	dest: 'js/<%= pkg.name %>.app.js'
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
    }
  });

  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-watch');

  // Default task.
  grunt.registerTask('default', ['compass', 'jshint','concat', 'uglify']);

};
