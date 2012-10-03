Support for video popups in campaign map pages
==============================================

Installation for video popups on map page
-----------------------------------------

1) Enable Entity view modes module

2) Edit displays for video content type (admin/structure/types/manage/openpublish-video/display)
    a) clear all caches
    b) click on manage display button, add "video popup for map page"
    c) edit field Embedded video; label=hidden, format=media, file view mode=large
    d) edit field Promo Text; label=hidden, format=default
    e) edit field Promo Headline; label=hidden, format=default

3) Go to vidpop admin page (admin/config/media/vidpop/settings) and set node ID of the page with maps

4) Edit map page, paste in javascript.

5) Edit the addresses array to add more points. See comments for the field contents. Note that the last field is the text to be displayed as a tooltip if no video is specified. It can be a string in quotes, or the variable default_details.


Future:
-Allow multiple pages with maps. THis will require adding multiple nids to the admin screen, or some other way of detecting pages with maps.

