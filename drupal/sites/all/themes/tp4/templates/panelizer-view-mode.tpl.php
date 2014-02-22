<?php
// @todo document this!
// Might be a good idea.
?>

<?php //separate panelizer display for campaigns from others ?>
<?php
  $card_bundles = array(
    'campaign_card_media',
  );
?>
<?php if(in_array($element['#bundle'], $card_bundles) == true): ?>
  <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if (!empty($title)): ?>
      <<?php print $title_element;?> class="title">
        <?php if (!empty($entity_url)): ?>
          <a href="<?php print $entity_url; ?>"><?php print $title; ?></a>
        <?php else: ?>
          <?php print $title; ?>
        <?php endif; ?>
      </<?php print $title_element;?>>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print $content; ?>
  </div>
<?php else: ?>
  <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if (!empty($title)): ?>
      <<?php print $title_element;?> <?php print $title_attributes; ?>>
        <?php if (!empty($entity_url)): ?>
          <a href="<?php print $entity_url; ?>"><?php print $title; ?></a>
        <?php else: ?>
          <?php print $title; ?>
        <?php endif; ?>
      </<?php print $title_element;?>>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print $content; ?>
  </div>
<?php endif; ?>