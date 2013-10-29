<?php
  /**
   * @file
   * Template for newsletter social block.
   */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="line"></div>

  <h2 class="block-title section-header block__title"><?php print $variables['header']; ?></h2>

  <?php print $content; ?>

  <div id="<?= $variables['response_id'] ?>">
    <p class="message"><?= $variables['body'] ?></p>
    <?php echo drupal_render($variables['form']); ?>
    <p class="terms-of-service"><?php print drupal_render($variables['tos_link']); ?></p>
</div>
<h3 class="follow-us"><?= t('Follow Us') ?></h3>
<ul class="social-links">
<?php foreach ($variables['social_links'] as $link): ?>
  <li><?php print render($link); ?></li>
<?php endforeach ?>
</ul>
</div>
