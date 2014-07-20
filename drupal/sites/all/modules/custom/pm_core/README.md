# Participant Media Core

This module provides a base on which all other custom modules can be built. It
provides support for loading PHP libraries through using
[Composer](https://getcomposer.org/).

Modules that depend on libraries loaded through the Composer autoloader should
add this module as a dependency.

## Doctrine ORM

The [Doctrine ORM](http://www.doctrine-project.org/projects/orm.html) and Entity
Manager has been added to the code base to provide persistence of site data that
does not require a stand alone page or URI. For site data that requires a stand
along page or URI, create a content type. Prime candidates for using the
Doctrine ORM are:
  - Data pulled from external sources
  - Data sets with complex relations
  - Data that can benefit from STI (Single Table Inheritence)

[Doctrine Entities](http://docs.doctrine-project.org/projects/doctrine-orm/en/latest/reference/basic-mapping.html)
should be written in PHP and placed in the the `app/entities` directory in the
`pm_core` module directory. These entities **are not** Drupal Entities, they are
regular PHP objects.

Modules that use the Doctrine ORM should add this module as a dependency.
