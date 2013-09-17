<div class="content">
<?php foreach (wl('howto_section') as $ws): ?>
  <h1><?= w($ws->token . '_heading') ?><span><?= w($ws->token . '_tag') ?></span></h1>
  <?php if ($wis = wl($ws->token . '_items')): ?>
  <ul <?= wa($ws->token . '_items') ?>>
    <?php foreach ($wis as $wi): ?>
      <li><img src="<?= $wi->img_src ?>" /><?= $wi->multi ?></li>
    <?php endforeach ?>
  </ul>
  <?php endif ?>
<?php endforeach ?>
</div>
