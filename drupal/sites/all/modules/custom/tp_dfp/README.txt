TakePart DFP is for backend API integration with Google's Doubleclick for Publisher.

#Installation instructions:
1) Download the latest version of Google DFP- https://github.com/googleads/googleads-php-lib/releases
2) Move directory to sites/all/libraries
3) Make sure the name is googleads-php-lib
4) Enable the module (drush en tp_dfp -y)
5) Add DFP values at admin/config/dfp

#Configuration:
Update Oauth settings and DFP id in the auth.ini file located in the google-dfp-lib-php
For more information regarding authentication: https://developers.google.com/doubleclick-publishers/docs/authentication
Add / Update the template ID at admin/config/dfp

#DFP Documenation
https://developers.google.com/doubleclick-publishers/?hl=en

#How to use:
1) Add or update the Template ID (from DFP) at admin/config/dfp
1) Add a 'sponsor' taxonomy term- admin/structure/taxonomy/sponsor/add
2) On the term add form, add a 'DFP Advertiser ID' (from DFP)
3) Save the term
*A 'success' message will get generated with a link to the freshly created creative on the DFP server
