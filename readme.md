# TakePart

> Stories That Matter, Actions That Count


## Install

Install Node and Ruby
If you don't know if you have node or ruby installed...
```sh
$ node -v
$ ruby -v
```

Install grunt-cli
```sh
$ sudo npm install -g grunt-cli
```

Install the following gems
```sh
$ sudo gem install sass
$ sudo gem install compass
$ sudo gem install zen-grids
```

In the root directory
```sh
$ npm install
```


## Asset Compiling

In the root directory
```sh
$ grunt watch
```

or to run it once
```sh
$ grunt build_dev
```

to test compiled assets in the production state
```sh
$ grunt build_prod
```


Optionally in each theme
```sh
$ compass watch
```

## Testing
Documentation on how we handle testing


## Git workflow
Documentation on TakePart's forking/branching workflow