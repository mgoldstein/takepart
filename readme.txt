The following directories are relative to the drupal directory in our git repo.
All changes should be isolated to the sites/all directory and it subdirectories,
or to the profiles/takepart directory for fixes. DO NOT modify the core Drupal
files or the OpenPublish files.


Directories in this section should not be modified as they are part of the
Drupal or OpenPublish cores and modifications will break the upgrade path.

  ./themes (do NOT modify)

		Drupal core themes.

	./includes (do NOT modify)

		Include files that make up Drupal core.

	./modules (do NOT modify)

		Drupal core modules

	./scripts

		Scripts for automating CMS activities.

	./profiles

		Drupal installation profiles. This is code that is part of the core
    distribution, in our case OpenPublish

	./profiles/openpublish

		The OpenPublish profile that extends Drupal core.


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

	./profiles/takepart/themes/takepart_embeddable

		Theme for partnership with Starbucks, renders site without a footer or
    header

	./profiles/takepart/modules

		Custom TakePart modules. These should be in sites/all/modules/custom

	./profiles/takepart/modules/features

		Custom TakePart features (CMS content in code). These should be in
    site/all/modules/custom/features (or possibly sites/all/modules/features,
    as long as it does not conflict with the directory for the Features module
    itself)


Directories in this section can be modified as needed, a separation of
contributed modules and theming from custom TakePart modules and theming should
be maintained. Any modifications to contributed modules should be reviewed and
done in a manner that would allow them to be contributed back to the community.

	./sites

		All the modules and themes developed or used specifically for the TakePart
    site 

	./sites/all

		Any code not part of core or the installation/distribution profile.

	./sites/all/themes

		Custom and 3rd party themes 

	./sites/all/libraries

		3rd party libraries (e.g. a wysiwyg editor)

	./sites/all/modules

		Modules for augmenting Drupal's core functionality

	./sites/all/modules/custom

		Custom TakePart modules

	./sites/all/modules/contrib

		Contributed 3rd party modules

	./sites/all/modules/contrib/features

		The 'Features' module (not for features created using the Features module)

	./sites/all/modules/openpublish_features

		OpenPublish features (CMS content in code)

	./sites/default

		Drupal settings files and location of 'files' symlink to assets directory

	./systems 

		Files for integration with external systems/libraries and tests. This
    directory needs further review before making any modifications

