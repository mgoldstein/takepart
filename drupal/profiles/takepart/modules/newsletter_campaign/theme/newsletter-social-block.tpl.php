<h3><?= $variables['header'] ?></h3>
<div id="<?= $variables['response_id'] ?>">
  <p class="message"><?= $variables['body'] ?></p>
  <?php echo drupal_render($variables['form']); ?>
  <p class="terms-of-service"><?php
    echo drupal_render($variables['tos_link']);
  ?></p>
</div>
<h3><?= t('Follow Us') ?></h3>
<ul>
<?php foreach ($variables['social_links'] as $link): ?>
  <li><?php echo render($link); ?></li>
<?php endforeach ?>
</ul>
