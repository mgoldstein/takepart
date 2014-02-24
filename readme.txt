The following directories are relative to the drupal directory in our git repo.
All changes should be isolated to the sites/all directory and it subdirectories,
or to the profiles/takepart directory for fixes. DO NOT modify the core Drupal
files or the OpenPublish files.

Directories in this section should not be modified as they are part of the
Drupal or OpenPublish cores and modifications will break the upgrade path.

	./includes (do NOT modify)

		Include files that make up Drupal core.

  ./misc (do NOT modify)

    Miscellaneoud assets for Drupal core.

	./modules (do NOT modify)

		Drupal core modules

	./scripts

		Scripts for automating CMS activities. The following scripts are provided
    as part of Drupal core and should NOT be modified, any additional scripts
    are custom scripts used for site release and maintenance.

    - code-clean.sh
    - cron-curl.sh
    - cron-lynx.sh
    - drupal.sh
    - dump-database-d6.sh
    - dump-database-d7.sh
    - generate-d6-content.sh
    - generate-d7-content.sh
    - password-hash.sh
    - run-tests.sh
    - test.script

  ./themes (do NOT modify)

    Drupal core themes.

	./profiles

		Drupal installation profiles. The following profiles are provided as part
    of Drupal core.

    - minimal
    - standard
    - testing

    The TakePart profile (takepart) is a custom profile specific to our site.


Directories in this section can be modified if necessary for a fix, new
development should be done in the sites/all directory

	./profiles/takepart

		TakePart specific module and theming. Most (if not all) of the content
    under this folder actually belongs under sites/all/modules/custom or
    sites/all/themes. Resolving this issue is an on going Tech project, updates
    and bug fixes can be done in this directory, new development should use the
    correct sites/all directory

	./profiles/takepart/themes

		Custom Drupal themes for the site

	./profiles/takepart/themes/takepart3

		The primary TakePart theme. Including js, css, templates and images

	./profiles/takepart/modules

		Custom TakePart modules. These are being phased out in favor of contributed
    modules and a limited number of custom modules in sites/all/modules/custom

	./profiles/takepart/modules/features

    Legacy feature modules that have been extended to be modules. The features
    portion of these modules have been migrated to the current set of features
    in sites/all/module/features. The remaining module functionality is being
    phased out in favor of contributed modules and a limited number of custom
    modules in sites/all/modules/custom

Directories in this section can be modified as needed, a separation of
contributed modules and theming from custom TakePart modules and theming should
be maintained. Any modifications to contributed modules should be reviewed and
done in a manner that would allow them to be contributed back to the community.

	./sites

		All the modules and themes developed or used specifically for the TakePart
    site

	./sites/all

		Any code not part of core or the installation/distribution profile.

	./sites/all/libraries

		3rd party libraries (e.g. a wysiwyg editor)

	./sites/all/modules

		Modules for augmenting Drupal's core functionality

  ./sites/all/modules/contrib

    Contributed modules

  ./sites/all/modules/contrib/features

    The 'Features' contributed module (NOT for features created using said
    module)

	./sites/all/modules/custom

		Custom TakePart modules

  ./sites/all/modules/development

    Development modules only. Any modules that are for development use only
    (e.g. devel) should be downloaded and enabled in this directory.

  ./sites/all/modules/features

    Site features created using the contributed 'Features' module. Files in this
    directory should not be editted directly. IMPORTANT: These modules are meant
    to be generated using the Features modules and must NOT be extended with
    custom module code.

	./sites/all/modules/openpublish_features

		Legacy Openpublish feature module that provided Features Boxes and Image
    Boxes. This module is being phased out.

  ./sites/all/themes

    Contributed themes

    - pangea
    - rubik
    - tao
    - zen

    Custom themes

    - chunkpart (being phased out)
    - takepart_core (parent theme to chunkpart and takepart3, being phased out)
    - tp4 (current theme)

  ./sites/default

    Drupal settings files and location of 'files' symlink to assets directory

