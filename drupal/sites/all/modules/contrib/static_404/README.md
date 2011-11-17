# Static 404

## What does this do?

`static_404` makes it easier to respond to 404 errors with a static page that is
modeled on a given Drupal node. This prevents Drupal from doing a lot of
initialization on 404, presumably saving server time and memory.

## How do I use this?

1. Install and enable the module.
2. Create a page in Drupal that will dictate the static page to be serve. Let's
   say its path is `/404page`. 
3. Go to Configuration -> Site information and fill the `Default 404 (not found)
   page` with path of the page you just create, e.g. `404page`.
4. Save Site information.
5. When the page reloads, click the `Generate static 404 page` button.

## Automating generation with Drush

Regeneration of the static 404 page can be automated using cron with a Drush
command. The drush command `sudo drush static_404_generate -l [site url]` will
generate the static 404.

