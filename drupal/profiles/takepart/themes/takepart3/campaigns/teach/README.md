# Getting Started with GruntJS and TEACH

TEACH front-end development is now using [grunt]

Before you start, make sure you have [```node.js```](http://nodejs.org/) and ```npm``` installed. You may want to use [Homebrew](http://brew.sh/) for this.

**Install the Grunt CLI and [Twitter Bower](http://bower.io/)**
```npm install -g grunt-cli bower```

Then, from within the ```drupal/profiles/takepart/themes/takepart3/campaigns/teach``` directory in the repository, run the following commands:

* ```npm install```
* ```bower install```

Congratulations! Paul Irish and Addy Osmani would be proud!

Now you can compile SASS/Compass and lint, concatenate, and minify javascript using the command ```grunt```. If you'd like grunt to monitor the directory for changes to SASS or JS and rebuild the compiled files when you save changes, use the command ```grunt watch```.
