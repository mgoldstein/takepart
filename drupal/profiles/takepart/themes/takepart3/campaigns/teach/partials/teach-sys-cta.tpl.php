<aside class="sys-cta">
  <h3><?php print w('story_cta_headlne'); ?></h3>
  <div class="sys-cta-body"><?php print w('story_cta_body'); ?></div>
  <div><?php $w = w('story_cta_button'); ?></div>
  <a href="<?php print $w->href; ?>" <?php print wa('story_cta_button'); ?>><?php print $w->single; ?></a>
</aside>